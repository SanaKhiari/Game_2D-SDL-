#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "option.h"
void save_volume(int volume){

    FILE *fichier = NULL;
    fichier = fopen("volume.txt", "w");
    fprintf(fichier, "%d", volume);
    fclose(fichier);

}


int get_volume(){

    int volume , *choix;
    FILE *fichier = NULL;
    fichier = fopen("volume.txt", "r");
    while (!feof(fichier))
        fscanf(fichier, "%d", &volume);
    fclose(fichier);
    return volume;
}


void afficher_option(SDL_Surface *screen){

	int choix;
	 int volum=get_volume();
	 Mix_Chunk  *music1;
         Mix_AllocateChannels(2);
         if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1){
       		 printf("%s", Mix_GetError());
        }
        music1 = Mix_LoadWAV("sound.wav");

	Mix_Music *music;
	music= Mix_LoadMUS("music.mp3");
	Mix_VolumeMusic(volum);
	Mix_PlayMusic(music,-1);
	//creation background
	SDL_Surface *background = NULL;
	background = IMG_Load("background.png");
	
	// detreminerr pos de back
	SDL_Rect background_pos;
	background_pos.x = 0;
	background_pos.y = 0;
	//creation bouton volume
	SDL_Surface *volume[4];
	volume[0] = IMG_Load("volume1.jpg");
	
	volume[1] = IMG_Load("volume2.jpg");
	
	volume[2] = IMG_Load("volume3.jpg");
	
	volume[3] = IMG_Load("volume4.jpg");
	
	int vl = 0, v = 0;
    	if (volum == 0)
        	v = 0;
   	 if (volum == 33)
        	v = 1;
    	if (volum == 66)
        	v = 2;
    	if (volum == 99)
        	v = 3;
	//pos buton volume
	SDL_Rect volume_pos;
 	volume_pos.x = 230;
	volume_pos.y = 350;
	//creation bouton full
	SDL_Surface *full[3];
	full[0] = IMG_Load("button_full.png");
	
	full[1] = IMG_Load("button_full1.png");
	
	full[2] = IMG_Load("button_full2.png");
	
	int fl = 0;
	//pos buton full
	SDL_Rect full_pos;
	full_pos.x = 450;
	full_pos.y = 350;
	//creation bouton back
	SDL_Surface *back[2];
	back[0] = IMG_Load("back1.png");
	
	back[1] = IMG_Load("back2.png");
	
	int ba = 0;
	//pos buton back
	SDL_Rect back_pos;
	back_pos.x = 700;
	back_pos.y = 350;


	//creation boutton joueur
	SDL_Surface *player1 = NULL;
	player1 = IMG_Load("player1.png");
	
	// detreminerr pos de joueur
	SDL_Rect player1_pos;
	player1_pos.x = 350;
	player1_pos.y = 600;

	//creation boutton joueur
	SDL_Surface *player2 = NULL;
	player2 = IMG_Load("player2.png");
	
	// detreminerr pos de joueur
	SDL_Rect player2_pos;
	player2_pos.x = 650;
	player2_pos.y = 600;

	SDL_Event event;
	int done = 1;
	while (done){
        	
        	if (SDL_PollEvent(&event)) // ki ninzel ala ay haja
		{
           	 switch (event.type) //tal9a type el 7aja
            	{
            case SDL_QUIT: //nenzel 3al (X) el 7amra
                done = 0;
                break;

            //avec clavier
            case SDL_KEYDOWN:                 // ay haja fil clav
                switch (event.key.keysym.sym) // taref type l haja l nzalt alaha fil clav
                {
                ////////////////////////////////////////////////////////////////////////////////////////////////////////
                ////////////////////////////////////////////////////////////////////////////////////////////////////////
		case SDLK_ESCAPE:
			done=0;
		break;
		
		case SDLK_1:
			choix=1;
		break;
		case SDLK_2:
			choix=2;
		break;

                case SDLK_UP: //flech fou9ani
                    if (vl == 0 && fl == 0 && ba == 0)
                    {
                        vl = 1;
                    }
                    else if (vl == 1 )
                    {
                        ba = 1;
                        vl = 0;
                        fl = 0;
                    }
                    else if (ba == 1 )
                    {
                        fl = 1;
                        vl = 0;
                        ba = 0;
                    }
                    else if (fl == 1 )
                    {
                        fl = 0;
                        vl = 1;
                        ba = 0;
                    }

                    break;
                ////////////////////////////////////////////////////////////////////////////////////////////////////////
                ////////////////////////////////////////////////////////////////////////////////////////////////////////
                case SDLK_DOWN: //flech loutani
                    if (vl == 0 && fl == 0 && ba == 0)
                    {
                        ba = 1;
                    }
                    else if (vl == 1 )
                    {
                        ba = 0;
                        vl = 0;
                        fl = 1;

                    }
                    else if (fl == 1 )
                    {
                        fl = 0;
                        vl = 0;
                        ba = 1;

                    }
                    else if (ba == 1 )
                    {
                        ba = 0;
                        fl = 0;
                        vl = 1;
                    }

                    break;
                ////////////////////////////////////////////////////////////////////////////////////////////////////////
                ////////////////////////////////////////////////////////////////////////////////////////////////////////
                case SDLK_RETURN: //entree
                    if (fl == 1)
                    {
                        screen = SDL_SetVideoMode(1100, 700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
                    }
                    else if (ba == 1)
                    {
                        done = 0;
                    }
                    break;
                ////////////////////////////////////////////////////////////////////////////////////////////////////////
                ////////////////////////////////////////////////////////////////////////////////////////////////////////
                case SDLK_RIGHT: //t9awi music//t9awi music//t9awi music//t9awi music
                    if (volum < 99 && vl == 1)
                    {
                        volum += 33;
                        v++;
                       Mix_VolumeMusic(volum);
                    }
                    break;
                ////////////////////////////////////////////////////////////////////////////////////////////////////////
                ////////////////////////////////////////////////////////////////////////////////////////////////////////
                case SDLK_LEFT: //tna9s music
                    if (volum > 0 && vl == 1)
                    {
                        volum -= 33;
                        v--;
			Mix_VolumeMusic(volum);
                    }
                    break;
               
                }
                break;
            ////////


            } //fin switch event

        }     //fin pollevent

	//afficher
        SDL_BlitSurface(background, NULL, screen, &background_pos);
        SDL_BlitSurface(volume[v], NULL, screen, &volume_pos);
        SDL_BlitSurface(full[fl], NULL, screen, &full_pos);
        SDL_BlitSurface(back[ba], NULL, screen, &back_pos);
	SDL_BlitSurface(player1, NULL, screen, &player1_pos);
	SDL_BlitSurface(player2, NULL, screen, &player2_pos);

        SDL_Flip(screen);

    } //fin while done
	save_volume(volum);
	Mix_FreeChunk(music1);
	SDL_FreeSurface(background);
	TTF_Quit();
} //fin focnt
