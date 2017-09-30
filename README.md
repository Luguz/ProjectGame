# ProjectGame
##### created by Lukas Guz, Felix Korthals
#

### Status Linux:
### Status MacOS: 

### Create/Compile the Game with the console (Makefile)
At first many thanks to **Hilton Lipschitz** for providing a great Tutorial for creating Makefiles ([Link](http://hiltmon.com/blog/2015/09/28/the-simple-c-plus-plus-makefile-executable-edition/))

**MacOS:**
1. Step: open console in the directory _../ProjectGame_
2. Step: type ``make clean`` to clean previous compilations
3. Step: (optional) sometimes not creating the folders Build and Bin by hand can create errors _(need fix)_
4. Step: type ``make`` in console (finally creates the game)
5. Step: (optional) type ``make install`` to install in chosen install-dir or type ``make distclean`` to delete it from there

###### What to change in Makefile when use new libraries, includes, other systems etc. to allow further usability:
- ``$(LIB)`` controls the used libraries
- ``$(INC)`` controls the used includes (normally don't have to be changed)
- there are platform specific compilation flags in the Makefile -> change to your needs
#
_At last it is to say always look into the Makefile before using it! Especially if it was created by beginners._

### Guide/Overview to the source code
- **main :** generic main.cpp
- **Main_Game :** manages the basic functions and wear  together the most important functions
- **Screen_Graphics :** creates the magic on the Screen
- **Audio_Playback :** handles everything relating to music
- **Player_World_Interaction :** manages the Player decisions
- **Player_World_Variables :** holds and manages the Informations about the World
- **File_Manager :** everything related to Files (Ressource linking, ErrorLog)
