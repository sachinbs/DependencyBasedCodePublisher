#pragma once
#ifndef DEP_TABLE
#define DEP_TABLE

///////////////////////////////////////////////////////////////////
// Project#3:      Dependency-based Code Publisher               //
//                 To create a Dependency-based Code Publisher   //
//                                                               //
// ## Created by using Prof. Jim Fawcett's 'CodeAnalyzer'     ## //
// ## project and augmenting it with 'Type Analysis',         ## //
// ## 'Dependency Analysis' and 'Code Publishing' features.   ## //
//                                                               //
// Publisher.h:    Header file for Publisher                     //
// ************************************************************* //
// Version:        2.0                                           //
// Date:           03/28/2017                                    //
// Language:       Visual C++, Version 11.                       //
// Platform:       Visual Studio Community Edition               //
//                 HP ENVY, Windows 10                           //
// Application:    CSE687 - Object Oriented Design               //
// Author:         Sachin Basavani Shivashankara                 //
// SUID:           267871645                                     //
// Ph:, email:     (315)751-5895, sbasavan@syr.edu               //
///////////////////////////////////////////////////////////////////

// Module Operations:
// ==================
//          -Contains a class (DependencyTable) that saves and displays Dependency Table.
// 
// Public Interface:
// =================
//          bool save(std::string typeName, DepInfo val);               // Save into Dependency Table
//          void addHeader(std::map<std::string, DepInfo>::iterator it, std::ofstream& myfile, std::string fileName); // Adds HTML tags and provides links to the file dependencies
//          void addBody(std::map<std::string, DepInfo>::iterator it, std::ofstream& myfile);                         // Adds the code into the body section of the HTML file//
//          std::map<std::string, DepInfo>& returnDepTable();           // returns Dependency Table
//												 
// Required Files:
// ===============
// Publisher.h, Publisher.cpp
//
// Maintenance Information:
// ========================
// Version: 2.0
//         - Renamed package to "Publisher.h" from "Dependency_Table.h"
//         - Added "Code Publishing" feature. That is, to create HTML files which provides links to the dependencies of the code.
// Version: 1.0
//         - Created class that provides options to save and display "Dependency Table"

#include <iostream>
#include <string>
#include <vector>
#include <map> 
#include <iomanip> 
#include <sstream>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <exception>
#include <chrono>
#include <ctime>

#include <sys/types.h>
#include <sys/stat.h>

#include "../Parser/Parser.h"
#include "../FileSystem/FileSystem.h"
#include "../FileMgr/FileMgr.h"
#include "../Parser/ActionsAndRules.h"
#include "../Parser/ConfigureParser.h"
#include "../AbstractSyntaxTree/AbstrSynTree.h"
#include "../Logger/Logger.h"
#include "../Utilities/Utilities.h"
#include "../Analyzer/Executive.h"
#include"../Type_Table/Type_Table.h"
#include"../Type_Analysis/Type_Analysis.h"
#include "../Dependency_Analysis/Dep_Anal.h"
#include"../Type_Table/Type_Table.h"

namespace CodeAnalysis
{
	// Struct to store dependencies (vector of string)
	struct DepInfo
	{
		std::vector<std::string> DepItem;
	};

	// Class to create HTML pages from the Dependency Table
	class DependencyTable
	{
	private:
		std::map<std::string, DepInfo> DTmap;						// Dependency Table map
	public:
		bool save(std::string typeName, DepInfo val);				// Save into Dependency Table
		void createHtml();                                          // Display Dependency Table
		void addHeader(std::map<std::string, DepInfo>::iterator it, std::ofstream& myfile, std::string fileName); // Adds HTML tags and provides links to the file dependencies
		void addBody(std::map<std::string, DepInfo>::iterator it, std::ofstream& myfile); // Adds the code into the body section of the HTML file
		std::map<std::string, DepInfo>& returnDepTable();			// returns Dependency Table
	};

	// Returns Dependency Table
	inline std::map<std::string, DepInfo>& DependencyTable::returnDepTable()
	{
		return DTmap;
	}

	// Saves into Dependency Table
	inline bool DependencyTable::save(std::string typeName, DepInfo val)
	{
		if (val.DepItem.size() == 0)
		{
			DTmap[typeName].DepItem.push_back("-");
			return true;
		}
		for (auto v : val.DepItem)
			DTmap[typeName].DepItem.push_back(v);

		return true;
	}

	// Creates HTML pages of the code
	inline void DependencyTable::createHtml()
	{
		std::cout << "\n ";
		std::map<std::string, DepInfo>::iterator it = DTmap.begin();
		std::string strPath = "HtmlRepo";
		struct stat status;
		stat(strPath.c_str(), &status);
		if (!(status.st_mode & S_IFDIR))       // Checks if the directory "HtmlRepo" already exists
		{
			system("mkdir ..\\..\\HtmlRepo");          // If not create a directory with name "HtmlRepo"
		}
		for (it; it != DTmap.end(); ++it)
		{
			std::string fileName = FileSystem::Path::getName(it->first);
			std::string filePath = ("../../HtmlRepo/" + fileName + ".html");
			std::ofstream myfile(filePath);
			if (myfile.is_open())
				addHeader(it, myfile, fileName);        // Adds HTML tags and provides links to the dependent files
			addBody(it, myfile);	                    // Adds the code into the body section of the HTML file
		}
	}

	// Adds HTML tags and provides links to the file dependencies
	// Calls the styling sheet (.css file)
	// Also calls the JavaScript file (For expanding and collapsing facility between scopes)
	inline void DependencyTable::addHeader(std::map<std::string, DepInfo>::iterator it, std::ofstream& myfile, std::string fileName)
	{
		std::cout << std::right;
		DepInfo val = it->second;

		myfile <<
			"<!-------------------------------------------------------------------------------------" << "\n" <<
			"Project#3: Dependency-based Code Publisher. To create a Dependency-based Code Publisher" << "\n" <<
			fileName << ".html - Published to fulfill Requirements of Project#3" << "\n" <<
			"Name: Sachin Basavani Shivashankara, SUID: 267871645." << "\n" <<
			"Ph: (315)751-5895, Email: sbasavan@syr.edu" << "\n" <<
			"CSE687 - Object Oriented Design, Spring 2017" << "\n" <<
			"-------------------------------------------------------------------------------------->" << "\n" <<
			"\n" <<
			"<html>" << "\n" <<

			"  <head>" << "\n" <<

			"    <link rel = \"StyleSheet\" type = \"text/css\" href = \"../CSS/styleSheet.css\">" << "\n" <<
			"	 <script src = \"../JS/toggleVisibility.js\"></script>" << "\n" <<

			"  </head>" << "\n" <<

			"  <body>" << "\n" <<
			"    <h3>" << fileName << "</h3>" << "\n" <<
			"    <hr />" << "\n" <<
			"    <div class=\"indent\">" << "\n" <<
			"      <h4>Dependencies:</h4>" << "\n";

		// Adds links for dependencies in the HTML file
		if (val.DepItem.size() == 1 && val.DepItem[0].compare("-") == 0)
			myfile << "      No dependents" << "\n";
		for (std::string str : val.DepItem)
		{
			if (str.compare("-") == 0)
				continue;
			std::string dependentPath = str + ".html";
			myfile <<
			"      <a href=\"" << dependentPath << "\">" << str << "</a>" << "\n" <<
			"      <br />" << "\n";
		}
		myfile <<
			"    </div>" << "\n" <<
			"    <hr />" << "\n";
	}

	// Adds the code into the body section of the HTML file
	// Replaces "<" and ">" markup characters into "&lt;" and "&gt;"
	// Also adds the facility to expand and collapse class bodies, methods and global functions (For code within scopes)
	inline void DependencyTable::addBody(std::map<std::string, DepInfo>::iterator it, std::ofstream& myfile)
	{
		std::ifstream fileInput(it->first);
		std::string writeLine;
		myfile << "    <pre>" << "\n";

		int scopeCount = 0;
		size_t findIndex = 0;
		while (std::getline(fileInput, writeLine, '\n'))
		{
			findIndex = 0;
			while ((findIndex = writeLine.find("<", findIndex)) != std::string::npos)
				writeLine.replace(findIndex, 1, std::string("&lt;"));

			findIndex = 0;
			while ((findIndex = writeLine.find(">", findIndex)) != std::string::npos)
				writeLine.replace(findIndex, 1, std::string("&gt;"));

			findIndex = 0;
			if ((findIndex = writeLine.find("{", findIndex)) != std::string::npos && writeLine.find("}", findIndex) == std::string::npos && writeLine.find("find") == std::string::npos)
			{
				scopeCount += 1;
				writeLine =  writeLine.replace(findIndex, 1, std::string("{") + "<pre id=\"id" + std::to_string(scopeCount) + "\">");
				writeLine = "<div onclick=\"toggleVisibility('id" + std::to_string(scopeCount) + "', 'x" + std::to_string(scopeCount) + "'); \" id=\"x" + std::to_string(scopeCount) + "\">[-]</div>" + writeLine;
			}

			findIndex = 0;
			if (writeLine.find("{", findIndex) == std::string::npos && (findIndex = writeLine.find("}", findIndex)) != std::string::npos && writeLine.find("find") == std::string::npos)
				writeLine = "</pre>" + writeLine;

			myfile << writeLine << "\n";
		}
		myfile << "    </pre>" << "\n";
		myfile << "    <hr />" << "\n";
		myfile << "  </body>" << "\n";
		myfile << "</html>" << "\n";
	}
}

#endif