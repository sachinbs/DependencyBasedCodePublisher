///////////////////////////////////////////////////////////////////
// Project#3:       Dependency-based Code Publisher              //
//                  To create a Dependency-based Code Publisher  //
//                                                               //
// ## Created by using Prof. Jim Fawcett's 'CodeAnalyzer'     ## //
// ## project and augmenting it with 'Type Analysis',         ## //
// ## 'Dependency Analysis' and 'Code Publishing' features.   ## //
//                                                               //
// Dep_Anal.cpp:    Test-stub for Dependency Anaylysis           //
// ************************************************************* //
// Version:         1.0                                          //
// Date:            03/15/2017                                   //
// Language:        Visual C++, Version 11.                      //
// Platform:        Visual Studio Community Edition              //
//                  HP ENVY, Windows 10                          //
// Application:     CSE687 - Object Oriented Design              //
// Author:          Sachin Basavani Shivashankara                //
// SUID:            267871645                                    //
// Ph:, email:      (315)751-5895, sbasavan@syr.edu              //
///////////////////////////////////////////////////////////////////

#include "Dep_Anal.h"

using namespace CodeAnalysis;
using TypeTableMap = std::map<std::string, std::vector<CodeAnalysis::TypeInfo>>;
using DepTableMap = std::map<std::string, DepInfo>;

#ifdef  DEP_ANAL

// Test stub for Dependency Analysis
int main()
{
	std::cout << "Testing Dependency Analysis\n";
	// To create Type Table
	TypeAnalysis ta;

	ta.doTypeAnal();

	TypeTable tt = ta.getTypeTable();
	TypeTableMap dpt = tt.returnTT();

	// To create Dependency Table
	DepAnalysis dt;

	std::set<std::string> f1 = ta.getAllFilenames();
	dt.doDepAnal(dpt, f1);

	return 0;
}
#endif
