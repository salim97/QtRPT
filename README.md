# Setup
1) copy "QtRptProject" folder to your project ( see "QtRPT-Example" folder )
2) add those lines to your .pro file of your project

```ruby
INCLUDEPATH += $$PWD/QtRptProject
include($$PWD/QtRptProject/QtRPT/QtRPT.pri)
```
3) copy "QtRPT-Example/DLL/QtZint.dll" to your exe application folder in order to work properly without error

# Tutorial
[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/M4AoJiXNvCo/0.jpg)](https://www.youtube.com/watch?v=M4AoJiXNvCo)


# Summary

QtRPT is the easy-to-use report engine written in C++ QtToolkit.
It allows combining several reports in one XML file. For separately taken field,
you can specify some condition depending on which this field will display in different font and background color, etc. 
The project consists of two parts: 
report library QtRPT and report designer application QtRptDesigner.
Report file is a file in XML format.
The report designer makes easy to create report XML file.
