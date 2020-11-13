# uniwa-ice-oop-project
Project in OOP from ICE dept in UNIWA

## Goal
Implementation of a Dashboard where the following entities exist:
- Student `Student.cpp/h` with attributes: *id, first, last, grades*
- Course `Course.cpp/h` with attributes: *old id, old name, new id, new name*

Final goal was to load a large `.csv` file with students' grade data 
and check whether all grades had been transferred according to a given 
correspondence between old id to new id  

## Features
- Maps using `char *` as keys with custom string comparison function
- `.csv` file loading into classes using regexp
- Proper destruction schemes (no memory leaks)
- Error handling/logging
