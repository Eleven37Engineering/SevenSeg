#Seven Seg

This project is to display characters on a seven segment display in an easy to use manner.

Use for whatever, no need to give credit, contribute if you see a problem.  Donations are a great idea, but we would rather see you develop your own library and evolve the world like we're trying to do.


##Changelog
0.1.0 - Working implementation with time delay
0.0.2 - Implimentation of library definitions. Includes formatting error fixes from v0.0.1.
0.0.1 - Inital creation of project - includes wiring diagram and old_code example of how the library was built.


##Installation
1. Download the files
2. Insert the source code into new files of the arduino project
3. Add '#include <SevenSeg.h>' in your sketch


##Usage

This is still in full development for the wiring diagram please see: diagram.jpg
You can also see the Fritzing project under the fritzing folder.

This is a C++ library written to to operate in an object oriented manner.

Create a **SevenSeg** object and call the **SetDisplay** function, like so:
```
SevenSeg *sevenSeg = new SevenSeg();
sevenSeg->SetDisplay(1, 2, 3, 4, 1000);
```

Please reference the examples folder for implementations of the code, we've tried to build this up to support many examples.
