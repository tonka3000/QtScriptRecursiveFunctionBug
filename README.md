QtScript recursive function bug
===============================

This little testapp demonstrate a possible bug in QtScript on Windows systems.<br>

## The problem
The problems occur if there is an function-call on a recursive function. The testscript **crash.js** (originally created with CoffeeScript) is a simple function which calls itself 1000 times. On a windows system this will lead into an crash after the program is finished and popContext will be called. If i will reduce the number from 1000 to 500 everything works fine (see **fine.js**).

## Script evaluation
The evaluation of the script engine is guarded with an new context to avoid garbage in the global object (created with pushContext). If the script evalution is finished popContext will be called => on windows, this will crash (with **crash.js**)!

This only happens on windows system (x86 & x64). On Linux, Mac OS X this app run without any problems.

If i remove the pushContext()/popContext guard no crash happens, but i will get garbage in my global object => bad.

## Tested Qt-Versions on windows

* 4.7.3 x64 (MSVC 2010 SP1 x64)
* 4.8.5 x86 (from Qt-Project.org MSVC2010)
* 4.8.6 x86 (from Qt-Project.org MSVC2010)
* 5.3.2 x86 (from Qt-Project.org MSVC2010)

## How to compile this app
Use Qt Creator to compile this app (open the pro-file)

## How to use this app
This app is a very simple terminal-app. The first parameter has to be the absoulte path to the js-script.

f.e.: ScriptTest.exe C:\\.....\js\crash.js

Different js-file
* crash.js => this file will crash
* fine.js  => this file works as expected

## Special thanks
...to **wysota** and **anda_skoa** from [www.qtcentre.org](http://www.qtcentre.org) which helped me testing on other platforms and generally for there help.
