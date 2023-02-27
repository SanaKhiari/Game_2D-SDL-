#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include"enigmeImage.h"

/**
* @file test.c
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date Apr 25 , 2022
*
* Testing program for testing 
*
*/

int main(int argc , char** argv){
SDL_Init(SDL_INIT_EVERYTHING);
	 SDL_Surface *screen =NULL;

	 screen = SDL_SetVideoMode(1000,600, 32,SDL_HWSURFACE | SDL_DOUBLEBUF); 
	if ( ! screen ) {
		printf("to set 600 * 300 voideo :%s /n ", SDL_GetError());
		return 1 ;
	 }else{
	int alea,i,j;
	SDL_Event event;
	int continuer=0; 
	Animation image;
	SDL_WM_SetCaption("enigme_SANA",NULL);
	enigmeImage e;
	SDL_Surface *bg;
	SDL_Rect pos_bg;
	bg=IMG_Load("/home/sana/enigme/enigmeImages/bg_EnigmeImage.png");
	pos_bg.x=0;
	pos_bg.y=0;
	pos_bg.w=1000;
	pos_bg.h=600;
	SDL_Surface *vrai;
        SDL_Rect pos_vrai;
        vrai=IMG_Load("/home/sana/enigme/src/true.png");
        pos_vrai.x=800;
        pos_vrai.y=150;
        pos_vrai.w=1000;
        pos_vrai.h=600;
	SDL_Surface *faux;
        SDL_Rect pos_faux;
        faux=IMG_Load("/home/sana/enigme/src/false.png");
        pos_faux.x=800;
        pos_faux.y=150;
        pos_faux.w=1000;
        pos_faux.h=600;

		SDL_BlitSurface(bg,NULL, screen, &pos_bg );

//		animer (screen);
		srand(time(0));
	do {
		alea = rand()%3 +1;
	}while ( alea <1 || alea > 3 ); //donne un numero aleatoire entre 1 et 3

	while (continuer==0){
	switch (alea){
		case 1:
		InitEnigme(&e, "../enigmeFiles/enigme1.txt");
    		afficherEnigme(e,screen);
    		SDL_Flip(screen);
//		animer (screen);
//		SDL_Flip(screen);
    		while(SDL_PollEvent(&event)){

			switch(event.type){
				case SDL_QUIT:
					continuer=1;
				break;
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym){
						case SDLK_ESCAPE:
							continuer=1;
						break;
					//switch (event.key.keysym.sym){
						case SDLK_a:
							 SDL_BlitSurface(faux,NULL, screen, &pos_faux );//affichage de resultat
						        SDL_Flip(screen);
							SDL_FreeSurface(bg);
                                                          free_surface_enigme(&e);
							  SDL_FreeSurface(faux);
							  SDL_FreeSurface(vrai);
							  SDL_Flip(screen);
							  SDL_Delay(1000);

						break;
						case SDLK_b :
							 SDL_BlitSurface(vrai,NULL, screen, &pos_vrai );
       							 SDL_Flip(screen);
							 animer (screen);
							 SDL_FreeSurface(bg);
							  SDL_FreeSurface(faux);
							  SDL_FreeSurface(vrai);
							  SDL_Flip(screen);
							  SDL_Delay(1000);
						break;
						case SDLK_c:
							 SDL_BlitSurface(faux,NULL, screen, &pos_faux );
						         SDL_Flip(screen);
							  free_surface_enigme(&e);
							 SDL_FreeSurface(bg);
							  SDL_FreeSurface(faux);
							  SDL_FreeSurface(vrai);
							  SDL_Flip(screen);
							  SDL_Delay(1000);
						break;
					}
				break;
				 case SDL_MOUSEBUTTONDOWN:
					if (event.button.button == SDL_BUTTON_LEFT){
                    				if (event.button.x > 0 && event.button.x < 1000 && event.button.y > 250 && event.button.y <850 ){
                                                         SDL_BlitSurface(faux,NULL, screen, &pos_faux );//affichage de resultat
                                                         SDL_Flip(screen);
							 free_surface_enigme(&e);
							 SDL_FreeSurface(bg);
							  SDL_FreeSurface(faux);
							  SDL_FreeSurface(vrai);
							  SDL_Flip(screen);
							  SDL_Delay(1000);

                    				}
                   				 else if (event.button.x > 0 && event.button.x < 1000 && event.button.y > 350 && event.button.y < 950){
                                                         SDL_BlitSurface(vrai,NULL, screen, &pos_vrai );
                                                         SDL_Flip(screen);
							animer (screen);
							 free_surface_enigme(&e);
							 SDL_FreeSurface(bg);
							  SDL_FreeSurface(faux);
							  SDL_FreeSurface(vrai);
							  SDL_Flip(screen);
							  SDL_Delay(1000);
                     				}
                    				else if (event.button.x > 0 && event.button.x < 1000 && event.button.y > 450 && event.button.y < 1050) {
                                                         SDL_BlitSurface(faux,NULL, screen, &pos_faux );//affichage de resultat
                                                         SDL_Flip(screen);
							free_surface_enigme(&e);
							 SDL_FreeSurface(bg);
							  SDL_FreeSurface(faux);
							  SDL_FreeSurface(vrai);
							  SDL_Flip(screen);
							  SDL_Delay(1000);


                   				 }
                			}
               			 break;
			}
		}
	break;
	case 2: 
		InitEnigme(&e, "../enigmeFiles/enigme2.txt");
    		afficherEnigme(e,screen);
    		SDL_Flip(screen);
	//	animer (screen);
	//	SDL_Flip(screen);
    		while(SDL_PollEvent(&event)){

			switch(event.type){
				case SDL_QUIT:
					continuer=1;
				break;
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym){
						case SDLK_ESCAPE:
							continuer=1;
						break;
					//switch (event.key.keysym.sym){
						case SDLK_a:
							 SDL_BlitSurface(vrai,NULL, screen, &pos_vrai );//affichage de resultat
						         SDL_Flip(screen);
							 animer (screen);
							free_surface_enigme(&e);
							 SDL_FreeSurface(bg);
							  SDL_FreeSurface(faux);
							  SDL_FreeSurface(vrai);
							  SDL_Flip(screen);
							  SDL_Delay(1000);

						break;
						case SDLK_b:
							 SDL_BlitSurface(faux,NULL, screen, &pos_faux );
       							 SDL_Flip(screen);
							free_surface_enigme(&e);
                                                         SDL_FreeSurface(bg);
							  SDL_FreeSurface(faux);
							  SDL_FreeSurface(vrai);
							  SDL_Flip(screen);
							  SDL_Delay(1000);
						break;
						case SDLK_c:
							 SDL_BlitSurface(faux,NULL, screen, &pos_faux );
						         SDL_Flip(screen);
							free_surface_enigme(&e);
							SDL_FreeSurface(bg);
							  SDL_FreeSurface(faux);
							  SDL_FreeSurface(vrai);
							  SDL_Flip(screen);
							  SDL_Delay(1000);
						break;
					}
				break;
				 case SDL_MOUSEBUTTONDOWN:
					if (event.button.button == SDL_BUTTON_LEFT){
                    				if (event.button.x > 0 && event.button.x < 1000 && event.button.y > 250 && event.button.y <850 ){
                                                         SDL_BlitSurface(vrai,NULL, screen, &pos_vrai );//affichage de resultat
                                                         SDL_Flip(screen);
							animer (screen);
							free_surface_enigme(&e);
							 SDL_FreeSurface(bg);
							  SDL_FreeSurface(faux);
							  SDL_FreeSurface(vrai);
							  SDL_Flip(screen);
							  SDL_Delay(1000);

                    				}
                   				 else if (event.button.x > 0 && event.button.x < 1000 && event.button.y > 350 && event.button.y < 950){
                                                         SDL_BlitSurface(faux,NULL, screen, &pos_faux );
                                                         SDL_Flip(screen);
							 free_surface_enigme(&e);
							 SDL_FreeSurface(bg);
							  SDL_FreeSurface(faux);
							  SDL_FreeSurface(vrai);
							  SDL_Flip(screen);
							  SDL_Delay(1000);
                     				}
                    				else if (event.button.x > 0 && event.button.x < 1000 && event.button.y > 450 && event.button.y < 1050) {
                                                         SDL_BlitSurface(faux,NULL, screen, &pos_faux );//affichage de resultat
                                                         SDL_Flip(screen);
							free_surface_enigme(&e);
							 SDL_FreeSurface(bg);
							  SDL_FreeSurface(faux);
							  SDL_FreeSurface(vrai);
							  SDL_Flip(screen);
							  SDL_Delay(1000);
                   				 }
                			}
               			 break;
			}
		}
		break;
		case 3:
		InitEnigme(&e, "../enigmeFiles/enigme3.txt");
    		afficherEnigme(e,screen);
    		SDL_Flip(screen);
	//	animer (screen);
	//	SDL_Flip(screen);
    		while(SDL_PollEvent(&event)){

			switch(event.type){
				case SDL_QUIT:
					continuer=1;
				break;
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym){
						case SDLK_ESCAPE:
							continuer=1;
						break;
					//switch (event.key.keysym.sym){
						case SDLK_a:
							 SDL_BlitSurface(vrai,NULL, screen, &pos_vrai );//affichage de resultat
						        SDL_Flip(screen);
							 animer (screen);
							free_surface_enigme(&e);
							SDL_FreeSurface(bg);
							  SDL_FreeSurface(faux);
							  SDL_FreeSurface(vrai);
							  SDL_Flip(screen);
							  SDL_Delay(1000);

						break;
						case SDLK_b:
							 SDL_BlitSurface(faux,NULL, screen, &pos_faux );
       							 SDL_Flip(screen);
							free_surface_enigme(&e);
							 SDL_FreeSurface(bg);
							  SDL_FreeSurface(faux);
							  SDL_FreeSurface(vrai);
							  SDL_Flip(screen);
							  SDL_Delay(1000);
						break;
						case SDLK_c:
							 SDL_BlitSurface(faux,NULL, screen, &pos_faux );
						        SDL_Flip(screen);
							free_surface_enigme(&e);
							SDL_FreeSurface(bg);
							  SDL_FreeSurface(faux);
							  SDL_FreeSurface(vrai);
							  SDL_Flip(screen);
							  SDL_Delay(1000);
					break;
					}
				break;
				 case SDL_MOUSEBUTTONDOWN:
					if (event.button.button == SDL_BUTTON_LEFT){
                    				if (event.button.x > 0 && event.button.x < 1000 && event.button.y > 250 && event.button.y <850 ){
                                                         SDL_BlitSurface(vrai,NULL, screen, &pos_vrai );//affichage de resultat
                                                         SDL_Flip(screen);
							animer (screen);
							free_surface_enigme(&e);
							 SDL_FreeSurface(bg);
							  SDL_FreeSurface(faux);
							  SDL_FreeSurface(vrai);
							  SDL_Flip(screen);
							  SDL_Delay(1000);

                    				}
                   				 else if (event.button.x > 0 && event.button.x < 1000 && event.button.y > 350 && event.button.y < 950){
                                                         SDL_BlitSurface(faux,NULL, screen, &pos_faux );
                                                         SDL_Flip(screen);
							free_surface_enigme(&e);
							 SDL_FreeSurface(bg);
							  SDL_FreeSurface(faux);
							  SDL_FreeSurface(vrai);
							  SDL_Flip(screen);
							  SDL_Delay(1000);
                     				}
                    				else if (event.button.x > 0 && event.button.x < 1000 && event.button.y > 450 && event.button.y < 1050) {
                                                         SDL_BlitSurface(faux,NULL, screen, &pos_faux );//affichage de resultat
                                                         SDL_Flip(screen);
							 free_surface_enigme(&e);
							  SDL_FreeSurface(bg);
							  SDL_FreeSurface(faux);
							  SDL_FreeSurface(vrai);
							  SDL_Flip(screen);
							  SDL_Delay(1000);

                   				 }
                			}
               			 break;
			}
		}
	break;
	}


	}

//	animer (screen);
	SDL_Quit();
	}
	return 0;
}

