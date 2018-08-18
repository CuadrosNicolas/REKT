CC = g++
CFLAGS = -Wall
EXEC_NAME = bin/REKT
INCLUDES = includes/
OBJECTS = bin/objects/
HEADERS = headers/
LIBS = -lsfml-graphics -lsfml-window -lsfml-system lib/JsonReader.a
INSTALL_DIR = /usr/bin
OBJ_FILES = $(OBJECTS)Rekt.o $(OBJECTS)JData.o $(OBJECTS)JPage.o $(OBJECTS)JLocation.o $(OBJECTS)Button.o   $(OBJECTS)Page.o $(OBJECTS)Dock.o $(OBJECTS)Mouse.o $(OBJECTS)HitBox.o $(OBJECTS)ToggleButton.o $(OBJECTS)Entity.o $(OBJECTS)EventHandler.o $(OBJECTS)Str.o $(OBJECTS)Ressources.o $(OBJECTS)test.o $(OBJECTS)main.o $(OBJECTS)configFile.o
all : $(EXEC_NAME)

clean :
	rm $(EXEC_NAME) $(OBJ_FILES)

$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES) $(LIBS)

$(OBJECTS)%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<


install :
	cp $(EXEC_NAME) $(INSTALL_DIR)