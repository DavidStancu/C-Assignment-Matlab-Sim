#Copyright David-Ioan Stancu 312CAb 2023-2024
build:
	gcc -Wall -Wextra -pedantic -std=c99 my_octave.c -o my_octave

pack:
	zip -FSr 312CA_StancuDavidIoan_Tema1.zip README Makefile *.c *.h

clean:
	rm -f my_octave

.PHONY: pack clean