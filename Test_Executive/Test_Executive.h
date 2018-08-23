#pragma once
#ifndef TEST_EXE
#define TEST_EXE

///////////////////////////////////////////////////////////////////
// Project#3:   Dependency-based Code Publisher                  //
//              To create a Dependency-based Code Publisher      //
//                                                               //
// ## Created by using Prof. Jim Fawcett's 'CodeAnalyzer'     ## //
// ## project and augmenting it with 'Type Analysis',         ## //
// ## 'Dependency Analysis' and 'Code Publishing' features.   ## //
//                                                               //
// Test_Executive.h: Header file for Test Executive              //
// ************************************************************* //
// Version:     1.0                                              //
// Date:        03/15/2017                                       //
// Language:    Visual C++, Version 11.                          //
// Platform:    Visual Studio Community Edition                  //
//              HP ENVY, Windows 10                              //
// Application: CSE687 - Object Oriented Design                  //
// Author:      Sachin Basavani Shivashankara                    //
// SUID:        267871645                                        //
// Ph:, email:  (315)751-5895, sbasavan@syr.edu                  //
///////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <exception>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <Windows.h>

#include "../Parser/Parser.h"
#include "../FileSystem/FileSystem.h"
#include "../FileMgr/FileMgr.h"
#include "../Parser/ActionsAndRules.h"
#include "../Parser/ConfigureParser.h"
#include "../AbstractSyntaxTree/AbstrSynTree.h"
#include "../Logger/Logger.h"
#include "../Utilities/Utilities.h"
#include "../Analyzer/Executive.h"
#include "../Type_Table/Type_Table.h"
#include "../Type_Analysis/Type_Analysis.h"
#include "../Dependency_Analysis/Dep_Anal.h"
#include "../Publisher/Publisher.h"

class displayRequirements
{
	public:
		void req1();
		void req2();
		void req3();
		void req4();
		void req5();
		void req6();
		void req7();
};

inline void displayRequirements::req1()
{
	std::cout << "\n" << "***********************************************";
	std::cout << "\n" << "Demonstrating Requirement #1: Using VS 2015 C++";
	std::cout << "\n" << "***********************************************";
	std::cout << "\n" << "Please examine code in VS to verify the requirement" << "\n\n\n";
}

inline void displayRequirements::req2()
{
	std::cout << "\n" << "****************************************************************";
	std::cout << "\n" << "Demonstrating Requirement #2: To only use C++ standard libraries";
	std::cout << "\n" << "****************************************************************";
	std::cout << "\n" << "Please examine code in VS to verify the requirement" << "\n\n\n";
}

inline void displayRequirements::req3()
{
	std::cout << "\n" << "**************************************************************************";
	std::cout << "\n" << "Demonstrating Requirement #3: Creating HTML pages of C++ source code files";
	std::cout << "\n" << "**************************************************************************";
	std::cout << "\n" << "Please find the generated HTML files in the directory \"HtmlRepo\"" << "\n\n\n";
}

inline void displayRequirements::req4()
{
	std::cout << "\n" << "*************************************************************************************************************";
	std::cout << "\n" << "Demonstrating Requirement #4: To provide facility to expand or collapse code between scopes (Using JavaSript)";
	std::cout << "\n" << "*************************************************************************************************************";
	std::cout << "\n" << "Please examine in the generated HTML files to verify the requirement" << "\n\n\n"; 
}

inline void displayRequirements::req5()
{
	std::cout << "\n" << "********************************************************************************************************";
	std::cout << "\n" << "Demonstrating Requirement #5: To provide CSS (Style sheet) file and JavaScript (for Requirement #4) file";
	std::cout << "\n" << "********************************************************************************************************";
	std::cout << "\n" << "Please find \"styleSheet.css\" file in the \"CSS\" directory";
	std::cout << "\n" << "and";
	std::cout << "\n" << "\"toggleVisibility.js\" file in the \"JS\" directory" << "\n\n\n";
}

inline void displayRequirements::req6()
{
	std::cout << "\n" << "*****************************************************************************************************";
	std::cout << "\n" << "Demonstrating Requirement #6: To embed CSS and JavaScript file in the header section of the HTML file";
	std::cout << "\n" << "*****************************************************************************************************";
	std::cout << "\n" << "Please open the HTML files in Notepad to verify the requirement" << "\n\n\n";
}

inline void displayRequirements::req7()
{
	std::cout << "\n" << "*********************************************************************************************";
	std::cout << "\n" << "Demonstrating Requirement #7: To provide links to dependent files (Using Dependency Analysis)";
	std::cout << "\n" << "*********************************************************************************************";
	std::cout << "\n" << "Please examine in the generated HTML files to verify the requirement" << "\n\n\n";
}

#endif