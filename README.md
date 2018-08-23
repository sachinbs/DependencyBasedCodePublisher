# DependencyBasedCodePublisher
A tool that publishes source code files as web pages with embedded child links. Each link refers to a code file that the displayed code file depends on

* The code publisher is embedded in a repository which supports publishing of source code as web pages
* Generates HTML files for each of the C++ source code files which captures the content of the source file
* Provides embedded links to the dependant files on top of the web page and captures the content of the source code under it
* Provides facility to expand or collapse class bodies, methods and global functions (of the source code) using JavaScript and page styling using CSS

1. run.bat by default runs on the whole project "CodePublisher"
2. All the HTML files of the project are generated in the directory "HtmlRepo"
3. Please find the style sheet "styleSheet.css" in the "CSS" directory
4. Please find the JavaScript "toggleVisibility.js" in the "JS" directory
