///////////////////////////////////////////////////////////////////
// Project#3:     Dependency-based Code Publisher                //
//                To create a Dependency-based Code Publisher    //
//                                                               //
// ## Created by using Prof. Jim Fawcett's 'CodeAnalyzer'     ## //
// ## project and augmenting it with 'Type Analysis',         ## //
// ## 'Dependency Analysis' and 'Code Publishing' features.   ## //
//                                                               //
// Publisher.cpp: Test-stub for HTML Code Publisher              //
// ************************************************************* //
// Version:       1.0                                            //
// Date:          03/28/2017                                     //
// Language:      Visual C++, Version 11.                        //
// Platform:      Visual Studio Community Edition                //
//                HP ENVY, Windows 10                            //
// Application:   CSE687 - Object Oriented Design                //
// Author:        Sachin Basavani Shivashankara                  //
// SUID:          267871645                                      //
// Ph:, email:    (315)751-5895, sbasavan@syr.edu                //
///////////////////////////////////////////////////////////////////

#include "../Dependency_Analysis/Dep_Anal.h"
#include "Publisher.h"

using namespace CodeAnalysis;

using Rslt = Logging::StaticLogger<0>;
using Demo = Logging::StaticLogger<1>;
using Dbug = Logging::StaticLogger<2>;
using TypeTableMap = std::map<std::string, std::vector<CodeAnalysis::TypeInfo>>;

#ifdef DEP_TABLE

// Test-stub for Publisher (HTML publisher using Dependency Table)
int main()
{
	std::cout << "Testing Publisher (HTML page creation from Dependency Table)\n";

	// To create Type Table
	TypeAnalysis ta;

	ta.doTypeAnal();

	TypeTable tt = ta.getTypeTable();
	TypeTableMap dpt = tt.returnTT();

	// To create HTML files from Dependency Table
	DepAnalysis dt;

	std::set<std::string> f1 = ta.getAllFilenames();
	dt.doDepAnal(dpt, f1);         // Performs Dependency Analysis and publishes HTML files

	return 0;
}

#endif