#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include "enigmeImage.h"

int main(int argc , char** argv){
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Surface *screen,*backg;
	SDL_Rect pos;
	Animation image;
        int i=0,j,num=0;
	Uint32 start;
	screen = SDL_SetVideoMode(1000,600,32,SDL_HWSURFACE | SDL_SRCALPHA);
	if ( ! screen ) {
		printf("to set 600 * 300 voideo :%s /n ", SDL_GetError());
		return 1 ;
	 }
	backg=IMG_Load("../enigmeImages/bg_EnigmeImage.png");
	if (backg == NULL){
                printf("Unable to load png : %s\n",SDL_GetError());
                return 1;
                }
	pos.x=0;
	pos.y=0;
	pos.w=1000;
	pos.h=600;
	SDL_BlitSurface(backg,NULL, screen, &pos );
//	animer(screen);
	image.tab[0]= IMG_Load("1.png");
                if (image.tab[0] == NULL){
                printf("Unable to load png : %s\n",SDL_GetError());
                return 1;
                }
		image.tab[1]= IMG_Load("2.png");
                if (image.tab[1] == NULL){
                printf("Unable to load png : %s\n",SDL_GetError());
                return 1;
                }
		image.tab[2]= IMG_Load("3.png");
                if (image.tab[2] == NULL){
                printf("Unable to load png : %s\n",SDL_GetError());
                return 1;
                }
		image.tab[3]= IMG_Load("4.png");
                if (image.tab[3] == NULL){
                printf("Unable to load png : %s\n",SDL_GetError());
                return 1;
                }
		image.tab[4]= IMG_Load("5.png");
                if (image.tab[4] == NULL){
                printf("Unable to load png : %s\n",SDL_GetError());
                return 1;
                }
		image.tab[5]= IMG_Load("6.png");
                if (image.tab[5] == NULL){
                printf("Unable to load png : %s\n",SDL_GetError());
                return 1;
                }
		image.tab[6]= IMG_Load("7.png");
                if (image.tab[6] == NULL){
                printf("Unable to load png : %s\n",SDL_GetError());
                return 1;
                }
		image.tab[7]= IMG_Load("8.png");
                if (image.tab[7] == NULL){
                printf("Unable to load png : %s\n",SDL_GetError());
                  return 1;
                }
		image.tab[8]= IMG_Load("9.png");
                if (image.tab[8] == NULL){
                printf("Unable to load png : %s\n",SDL_GetError());
                return 1;
                }
		image.tab[9]= IMG_Load("10.png");
                if (image.tab[9] == NULL){
                printf("Unable to load png : %s\n",SDL_GetError());
                return 1;
                }
		image.tab[10]= IMG_Load("11.png");
                if (image.tab[10] == NULL){
                printf("Unable to load png : %s\n",SDL_GetError());
                return 1;
                }
		image.tab[11]= IMG_Load("12.png");
                if (image.tab[11] == NULL){
                printf("Unable to load png : %s\n",SDL_GetError());
                return 1;
                }
		image.tab[12]= IMG_Load("13.png");
                if (image.tab[12] == NULL){
                printf("Unable to load png : %s\n",SDL_GetError());
                return 1;
                }
		image.tab[13]= IMG_Load("14.png");
                if (image.tab[13] == NULL){
                printf("Unable to load png : %s\n",SDL_GetError());
                return 1;
                }
		image.tab[14]= IMG_Load("15.png");
                if (image.tab[14] == NULL){
                printf("Unable to load png : %s\n",SDL_GetError());
               return 1;
                }
		image.tab[15]= IMG_Load("16.png");
                if (image.tab[15] == NULL){
                printf("Unable to load png : %s\n",SDL_GetError());
                return 1;
                }

                image.pos_tab.x=750;
                image.pos_tab.y=400;
		while(num<16){
		//	SDL_BlitSurface(backg,NULL, screen, &pos );
			SDL_BlitSurface(image.tab[num],NULL, screen, &image.pos_tab );
			// SDL_FreeSurface(image.tab[num]);
			SDL_Delay(1000);
			 SDL_Flip(screen);

			num++;

			}
		//}
		for(i=0;i<16;i++){
		SDL_FreeSurface(image.tab[i]);
		}
	SDL_Flip(screen);
	SDL_Delay(10000);
	SDL_Quit();
return 0;
}
