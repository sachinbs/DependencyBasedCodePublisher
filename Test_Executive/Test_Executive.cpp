///////////////////////////////////////////////////////////////////
// Project#3:   Dependency-based Code Publisher                  //
//              To create a Dependency-based Code Publisher      //
//                                                               //
// ## Created by using Prof. Jim Fawcett's 'CodeAnalyzer'     ## //
// ## project and augmenting it with 'Type Analysis',         ## //
// ## 'Dependency Analysis' and 'Code Publishing' features.   ## //
//                                                               //
// Test_Executive.cpp: Test-stub for Test Executive              //
// ************************************************************* //
// Version:     2.0                                              //
// Date:        04/04/2017                                       //
// Language:    Visual C++, Version 11.                          //
// Platform:    Visual Studio Community Edition                  //
//              HP ENVY, Windows 10                              //
// Application: CSE687 - Object Oriented Design                  //
// Author:      Sachin Basavani Shivashankara                    //
// SUID:        267871645                                        //
// Ph:, email:  (315)751-5895, sbasavan@syr.edu                  //
///////////////////////////////////////////////////////////////////
// Maintenance Information:
// ========================
// Version: 2.0
//         - Modified the package to display the requirements for Project#3.
// Version: 1.0
//         - Used the package to display the requirements for Project#2 like: Type Table, Dependency Table and Strong Components.

#include "Test_Executive.h"

using namespace CodeAnalysis;

using Rslt = Logging::StaticLogger<0>;
using Demo = Logging::StaticLogger<1>;
using Dbug = Logging::StaticLogger<2>;
using TypeTableMap = std::map<std::string, std::vector<CodeAnalysis::TypeInfo>>;
using DepTableMap = std::map<std::string, DepInfo>;

//#ifdef TEST_EXE

// Test stub to demonstrate requirements
int main(int argc, char* argv[])
{
	using namespace CodeAnalysis;
	CodeAnalysisExecutive exec;
	displayRequirements dr;
	try
	{
		bool succeeded = exec.ProcessCommandLine(argc, argv);
		if (!succeeded)
			return 1;
		exec.setDisplayModes();
		exec.startLogger(std::cout);
		std::ostringstream tOut("Code Publisher");
		Utils::sTitle(tOut.str(), 3, 92, tOut, '=');
		Rslt::write(tOut.str());
		Rslt::write("\n     " + exec.systemTime());
		Rslt::flush();

		exec.showCommandLineArguments(argc, argv);
		Rslt::write("\n");

		exec.getSourceFiles();
		exec.processSourceCode(true);
		exec.dispatchOptionalDisplays();
		exec.flushLogger();

		// Code related to Type Table 
		std::cout << "\nPerforming Type Analysis...";
		TypeAnalysis ta;
		ta.doTypeAnal();
		TypeTable tt = ta.getTypeTable();
		TypeTableMap dpt = tt.returnTT();

		// Code related to Dependency Table and HTML Code Publisher
		std::cout << "\n\nPerforming Dependency Analysis...";
		std::cout << "\n\nGenerating HTML pages of the source code...";
		std::set<std::string> f1 = ta.getAllFilenames();
		DepAnalysis dt;
		dt.doDepAnal(dpt, f1);
		DependencyTable dtObj = dt.getDepTable(); 
		DepTableMap dtMap = dtObj.returnDepTable();
		
		// Displaying Requirements
		dr.req1(); // Displaying Requirement#1
		dr.req2(); // Displaying Requirement#2
		dr.req3(); // Displaying Requirement#3
		dr.req4(); // Displaying Requirement#4
		dr.req5(); // Displaying Requirement#5
		dr.req6(); // Displaying Requirement#6
		dr.req7(); // Displaying Requirement#7

		// To launch the HTML file
		std::map<std::string, DepInfo>::iterator openFile = dtMap.begin();
		std::string openFile1 = FileSystem::Path::getName(openFile->first);
		std::cout << "\nOpening " << openFile1 + ".html\n";
		std::string path = "..\\..\\HtmlRepo\\" + openFile1 + ".html";
		std::string command("start \"\" \"" + path + "\"");
		std::system(command.c_str());

		exec.flushLogger();
		Rslt::write("\n");
		std::ostringstream out;
		Rslt::write("\n");
		exec.stopLogger();	
	}
	catch (std::exception& except)
	{
		exec.flushLogger();
		std::cout << "\n\n  Caught exception in Executive::main: " + std::string(except.what()) + "\n\n";
		exec.stopLogger();
		return 1;
	}
	system("pause");
	return 0;
}

//#endif