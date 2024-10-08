# Projekt: CProjectMaker
# Autor: Lukáš PAchta

# VARS
NAME=cpm
SOURCE_FILES=main.cpp cpm.cpp 
CC=g++

CFLAGS=-pedantic -Wall -g
EXE_FILE=$(NAME)
ALL_FILES=./*

compile:
	$(CC) $(CFLAGS) $(SOURCE_FILES) -o $(EXE_FILE)

run:
	./$(EXE_FILE)


clear-exe:
	rm $(EXE_FILE)

clear-bin:
	rm -rf bin/ 
	rm -rf obj/

clear-pack:
	rm $(NAME).tar.gz
	rm $(NAME).zip

pack: clear-bin
	rm %(NAME)
	tar cvzf $(NAME).tar.gz $(ALL_FILES)
	zip $(NAME).zip $(ALL_FILES)

clear: clear-bin clear-pack clear-exe
