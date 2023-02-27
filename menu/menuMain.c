#include "menu.h"
#include "option.h"
//#include "amelioration_menu.h"

int main(){

	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	SDL_Surface *screen;
int done = 0 ;
int ch1=1,ch2=1,ch3=1;
Image BackgMenu,BackgOption,BackgJeu;
boutton play1,play2,option1,option2,quiter1,quiter2;
int choix=0,num=0,i;

SDL_Event event;
	screen = SDL_SetVideoMode(1200, 800, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);//configuration de l'ecran (t7ot longeur w largeur ta3 l'ecran)
	SDL_Surface *tab[9];
	tab[0]= IMG_Load("anim1.png");
	tab[1]= IMG_Load("anim2.png");
	tab[2]= IMG_Load("anim3.png");
	tab[3]= IMG_Load("anim4.png");
	tab[4]= IMG_Load("anim5.png");
	tab[5]= IMG_Load("anim6.png");
	tab[6]= IMG_Load("anim7.png");
	tab[7]= IMG_Load("anim8.png");
	tab[8]= IMG_Load("anim9.png"); 
	SDL_Rect pos_tab;
	pos_tab.x=40;
	pos_tab.y=40;
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

	initBackground(&BackgMenu);
	initBackground_jeu(&BackgJeu);
	initBackground_option(&BackgOption);
	init_boutton_play1(&play1);
	init_boutton_play2(&play2);
	init_boutton_option1(&option1);
	init_boutton_option2(&option2);
	init_boutton_quiter1(&quiter1);
	init_boutton_quiter2(&quiter2);

	

while (!done) {
	afficher_back (BackgMenu,screen);
	
	if (ch1==1)
		afficher_bouton(play1, screen);
	else
		afficher_bouton(play2,screen);
	if (ch2==1)
		afficher_bouton(option1,screen);
	else
		afficher_bouton(option2,screen);
	if (ch3==1)
		afficher_bouton(quiter1,screen);
	else 
		afficher_bouton(quiter2,screen);
	SDL_Flip(screen);
	ch1=ch2=ch3=1;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
			done = 1;
		break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym){
				case SDLK_ESCAPE:
					done=1;
				break;
			//	case SDLK_j:
			//		play1(screen);
			//	break;
				case SDLK_o:
					afficher_option(screen);
					
				break;
			}
		break;
		case SDL_MOUSEMOTION:
                if (event.motion.x > 430 && event.motion.x <1630  && event.motion.y > 200 && event.motion.y < 284)
                {
                    ch1= 0;
                    //Mix_PlayChannel(-1,music1 , 0);
                }
                else if (event.motion.x > 430 && event.motion.x < 1630 && event.motion.y > 400 && event.motion.y < 495)
                {
                    ch2 = 0;
                    //Mix_PlayChannel(-1, music1, 0);
                }
                else if (event.motion.x > 430 && event.motion.x < 1630  && event.motion.y > 600 && event.motion.y < 696)
                {
                    ch3 = 0;

                    //Mix_PlayChannel(-1, music1 , 0);
                }
                break;

 
}
}
while(num<9){
		//	SDL_BlitSurface(backg,NULL, screen, &pos );
			SDL_BlitSurface(tab[num],NULL, screen, &pos_tab );
			// SDL_FreeSurface(image.tab[num]);
			SDL_Delay(550);
			 SDL_Flip(screen);

			num++;

			}
		//}
		for(i=0;i<9;i++){
		SDL_FreeSurface(tab[i]);
		}
printf("%d",choix);
liberer_boutton(play1);
liberer_boutton(play2);
liberer_boutton(option1);
liberer_boutton(option2);
liberer_boutton(quiter2);
liberer_boutton(quiter1);
SDL_Quit();
return 0;
}
