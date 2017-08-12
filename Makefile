#
#  Makefile
#  GameProject
#
#  Created by Hilton Lipschitz on 2015-09-01.
#  Copyright (c) 2015 Maritime Capital LP. All rights reserved.
#	Processed by Lukas Guz, Felix Korthals.

# Determine the platform
UNAME_S := $(shell uname -s)

# CC (compiler for the chosen platform)
ifeq ($(UNAME_S),Darwin)
  CC := g++
else
  CC := g++
endif

###############################################################################

# Folders (set folders from to compile)
# Source folder
SRCDIR := Source
# buildobjects folder
BUILDDIR := Build
# folder for target
TARGETDIR := Bin

###############################################################################

# Targets (set the targets for this project)
EXECUTABLE := GameProject
TARGET := $(TARGETDIR)/$(EXECUTABLE)

# Final Paths (path where Game will be installed)
INSTALLBINDIR := /Users/LukasGuz/Programmieren/ProjectGame/Bin

###############################################################################

# Code Lists (find cpp to make .o files)
# extensions used for building
SRCEXT := cpp
# search in sourcefolder for cpp files and generate list of them
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
# create an objectslist out of the source list
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

###############################################################################

# Folder Lists (include folders needed for this project)
# contains list of used subfolders for includes (headers etc.)
INCDIRS := $(shell find Headerfiles/* -name '*.h' -exec dirname {} \; | sort | uniq)
# INCLIST is a transformation guide for INCDIRS to use as compiler flags
INCLIST := $(patsubst include/%,-I include/%,$(INCDIRS))
# creates the subfolders for the BUILDDIR (example: include/Graphics.h gets build/Graphics.h)
BUILDLIST := $(patsubst include/%,$(BUILDDIR)/%,$(INCDIRS))

###############################################################################

# Shared Compiler Flags (under mac and linux)
# tells to compile only
CFLAGS := -c
# INC tells compiler where to find include files (self created and system used)
INC := -I Headerfiles $(INCLIST) -I /usr/local/include
#  tells where the shared system libs are
LIB := -L/usr/local/lib -lSDL2 -lSDL2_mixer -lSDL2_image

###############################################################################

# Platform Specific Compiler Flags (deleted -02 from linux)
ifeq ($(UNAME_S),Linux)
    CFLAGS += -std=gnu++11

else
  CFLAGS += -g -O1 -std=c++11
endif

###############################################################################

# now the actual makeing begins:
# "$^" means the list of targets
#
$(TARGET): $(OBJECTS)
	# create the target dir
	@mkdir -p $(TARGETDIR)
	@echo "Linking..."
	@echo "	 Linking $(TARGET)"; $(CC) $^ -o $(TARGET) $(LIB)

# creates the build folder and makes objectsfiles of all source files
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDLIST)
	@echo "Compiling $<..."; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

###############################################################################

# clean the project from all files created by make
clean:
	@echo "Cleaning $(TARGET)..."; $(RM) -r $(OBJECTS) $(TARGET)
# deleted the $(BUILDDIR) option after -r maybe change on other projects
###############################################################################

# install the game where it should run
install:
	@echo "Installing $(EXECUTABLE)..."; cp $(TARGET) $(INSTALLBINDIR)

###############################################################################

# uninstall of the game from install folder
distclean:
	@echo "Removing $(EXECUTABLE)"; rm $(INSTALLBINDIR)/$(EXECUTABLE)

# this allows to use make clean; otherwise it would build a file called clean
.PHONY: clean
