# ProjectGame
##### created mostly by Lukas Guz, Felix Korthals
#
### Create/Compile the Game with the console (Makefile)
At first many thanks to **Hilton Lipschitz** for providing a great Tutorial for creating Makefiles ([Link](http://hiltmon.com/blog/2015/09/28/the-simple-c-plus-plus-makefile-executable-edition/))

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
_At last is to say always look into the Makefile before using it! Especially if it was created by beginners._

### Guide/Overview to the source code
The game obviously starts with the **main.cpp** with the int main(...) function. It only calls the _loop function_ of MainGame.cpp. This handles the game state of the game.   
**MainGame.cpp** controls all the major functions for running the game and "puts them together".

#
### Plans for the future (To-Do-List)
- [ ] add "error-code"
- [ ] if the texture in the loader function don't work set the texture to a placeholder
- [ ] put copyrights info outside the Linker files into the folder with the actual files
