# DependencyBasedCodePublisher
A tool that publishes source code files as web pages with embedded child links. Each link refers to a code file that the displayed code file depends on

    The code publisher is embedded in a repository which supports publishing of source code as web pages
    Generates HTML files for each of the C++ source code files which captures the content of the source file
    Provides embedded links to the dependant files on top of the web page and captures the content of the source code under it
    Provides facility to expand or collapse class bodies, methods and global functions (of the source code) using JavaScript and page styling using CSS

///////////////////////////////////////////////////////////////////
// Project#3:      Dependency-based Code Publisher               //
//                 To create a Dependency-based Code Publisher   //
//                                                               //
// ## Created by using Prof. Jim Fawcett's 'CodeAnalyzer'     ## //
// ## project and augmenting it with 'Type Analysis',         ## //
// ## 'Dependency Analysis' and 'Code Publishing' features.   ## //
// ************************************************************* //
// Version:        1.0                                           //
// Date:           04/04/2017                                    //
// Language:       Visual C++, Version 11.                       //
// Platform:       Visual Studio Community Edition               //
//                 HP ENVY, Windows 10                           //
// Application:    CSE687 - Object Oriented Design               //
// Author:         Sachin Basavani Shivashankara                 //
// SUID:           267871645                                     //
// Ph:, email:     (315)751-5895, sbasavan@syr.edu               //
///////////////////////////////////////////////////////////////////

1. run.bat by default runs on the whole project "CodePublisher"
2. All the HTML files of the project are generated in the directory "HtmlRepo"
3. Please find the style sheet "styleSheet.css" in the "CSS" directory
4. Please find the JavaScript "toggleVisibility.js" in the "JS" directory
