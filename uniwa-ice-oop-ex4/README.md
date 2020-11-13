# uniwa-ice-oop-4
Exercise 4 in OOP from ICE dept in UNIWA

## Goal
Implementation of an AppSystem where the following entities exist:
- App `App.cpp/h` with attributes: *code, name, minimum required OS, developer, price, ratings*
- GameApp `Game.cpp/h` which inherits App and additionally contains the attributes: *isOnline, gameType*
- OfficeApp `Office.cpp/h` which inherits App and additionally contains the attribute: *fileTypes*
- Developer `Developer.cpp/h` with attributes: *code, name, email*
- Rating `Rating.cpp/h` with with attributes: *stars, rater, comment*

## Features
- AppSystem current state dump extraction and load on memory
- Proper destruction schemes (no memory leaks)
- Implemented methods for adding/modifying data in AppSystem
- Shared pointers for App entity achieving polymorphism and proper memory management
