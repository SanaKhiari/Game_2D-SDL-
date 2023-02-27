prog: menuMain.o menu.o option.o
	gcc menuMain.o menu.o option.o -o prog -lSDL -g -lSDL_image -lSDL_mixer -lSDL_ttf
menuMain.o:menuMain.c
	gcc -c menuMain.c -g
menu.o:menu.c
	gcc -c menu.c -g
option.o:option.c
	gcc -c option.c -g
