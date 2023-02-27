#include "menu.h"

//backgrounds
void initBackground(Image *B){
	B->img=IMG_Load("background.png");
        	if (B->img == NULL){
               		 printf("Unable to load png : %s\n",SDL_GetError());
                	 return;
		}
	B->pos.x=0;
	B->pos.y=0;
	B->pos.w = SCREEN_W;
	B->pos.h = SCREEN_H;

}

void initBackground_jeu(Image *B){
	B->img=IMG_Load("background.png");
        if (B->img == NULL){
                printf("Unable to load png : %s\n",SDL_GetError());
                return;
	}
	B->pos.x=0;
	B->pos.y=0;

}

void initBackground_option(Image *B){
	 B->img=IMG_Load("background.png");
        if (B->img == NULL){
                printf("Unable to load png : %s\n",SDL_GetError());
                return;
        }
        B->pos.x=0;
        B->pos.y=0;
}

void afficher_back (Image B,SDL_Surface *screen){
	SDL_BlitSurface(B.img,NULL,screen,&B.pos);
}

void liberer_background(Image a){
	SDL_FreeSurface( a.img );
}

//les bouttons

void init_boutton_play1(boutton *A){
	A->bouton=IMG_Load("play01.png");
        if (A->bouton == NULL){
                printf("Unable to load png : %s\n",SDL_GetError());
                return;
}
        A->pos_boutton.x=430;
        A->pos_boutton.y=200;
	
}

void init_boutton_play2(boutton *A){
        A->bouton=IMG_Load("play02.png");
        if (A->bouton == NULL){
                printf("Unable to load png : %s\n",SDL_GetError());
                return;
}
        A->pos_boutton.x=430;
        A->pos_boutton.y=200;


}

void init_boutton_option1(boutton *A){
	A->bouton=IMG_Load("option01.png");
        if (A->bouton == NULL){
                printf("Unable to load png : %s\n",SDL_GetError());
                return;
}
        A->pos_boutton.x=430;
        A->pos_boutton.y=400;

}


void init_boutton_option2(boutton *A){ 
        A->bouton=IMG_Load("option02.png");
        if (A->bouton == NULL){
                printf("Unable to load png : %s\n",SDL_GetError());
                return;
}
        A->pos_boutton.x=430;
        A->pos_boutton.y=400;   

}
void init_boutton_quiter1(boutton *A){
	A->bouton=IMG_Load("quiter01.png");
        if (A->bouton == NULL){
                printf("Unable to load png : %s\n",SDL_GetError());
                return;
	}
        A->pos_boutton.x=430;
        A->pos_boutton.y=600;   
}

void init_boutton_quiter2(boutton *A){ 
	A->bouton=IMG_Load("quiter02.png");
        if (A->bouton == NULL){
                printf("Unable to load png : %s\n",SDL_GetError());
                return;
	}
        A->pos_boutton.x=430;
        A->pos_boutton.y=600;   
}
void afficher_bouton(boutton b , SDL_Surface *screen){
	SDL_BlitSurface( b.bouton , NULL , screen , &b.pos_boutton );
}
void liberer_boutton(boutton b){
	SDL_FreeSurface( b.bouton );
}


void animer_Menu(SDL_Surface * screen){
	Animation image;
        int i=0,j,num=0;
	image.tab[0]= IMG_Load("anim1.png");
                
		image.tab[1]= IMG_Load("anim2.png");
                
		image.tab[2]= IMG_Load("anim3.png");
                
		image.tab[3]= IMG_Load("anim4.png");
                
		image.tab[4]= IMG_Load("anim5.png");
                
		image.tab[5]= IMG_Load("anim6.png");
                
		image.tab[6]= IMG_Load("anim7.png");
                
		image.tab[7]= IMG_Load("anim8.png");
                
		image.tab[8]= IMG_Load("anim9.png");
                
		
                image.pos_tab.x=100;
                image.pos_tab.y=200;
		while(num<9){
		//	SDL_BlitSurface(backg,NULL, screen, &pos );
			SDL_BlitSurface(image.tab[num],NULL, screen, &image.pos_tab );
			// SDL_FreeSurface(image.tab[num]);
			SDL_Delay(550);
			 SDL_Flip(screen);

			num++;

			}
		//}
		for(i=0;i<9;i++){
		SDL_FreeSurface(image.tab[i]);
		}
}
	


