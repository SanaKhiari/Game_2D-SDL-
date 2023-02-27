#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "enigmeImage.h"

/**  
* @file enigmeImage.c  
* @brief Testing Program.  
* @author C Team  
* @version 0.1  
* @date Apr 25, 2022  
*  
* Testing program for enigme  *  
*/



/**  
* @brief To initialize the enigme e .  
* @param e the enigmeImage  
* @param url the url of the image  
* @return Nothing  
*/  
void InitEnigme(enigmeImage *e, char *nomfichier){
		FILE* f = NULL;
        char caractereLu;
        int  ligne=0;
        char quest[7];
        char rep1[15];
        char rep2[15];
        char rep3[15];
	int i;
        f=fopen(nomfichier,"r");
        if(f!=NULL){
        fgets(quest,7,f);
        while (caractereLu !=EOF && ligne < 2 )
                {
                        caractereLu = fgetc(f);
                        if ( caractereLu == '\n'){
                                ligne++;}
                                fscanf(f,"%s %s %s ",rep1,rep2,rep3);
                }

                fclose(f);
                }else{
        printf("pas d'ouverture de fichier text !!");
        }


		e->question = IMG_Load(quest);
		if (e->question == NULL){
                printf("Unable to load png : %s\n",SDL_GetError());
                return;
		}
		e->pos_question.x=5;
		e->pos_question.y=50;
		e->reponse_1=IMG_Load(rep1);
		if (e->reponse_1 == NULL){
                printf("Unable to load png : %s\n",SDL_GetError());
                return;
                }

		e->pos_reponse_1.x=0;
		e->pos_reponse_1.y=250;
		e->reponse_2=IMG_Load(rep2);
		if (e->reponse_2 == NULL){
                printf("Unable to load png : %s\n",SDL_GetError());
                return;
                }
                e->pos_reponse_2.x=0;
                e->pos_reponse_2.y=350;
		e->reponse_3=IMG_Load(rep3);
		if (e->reponse_3 == NULL){
                printf("Unable to load png : %s\n",SDL_GetError());
                return;
                }
                e->pos_reponse_3.x=0;
                e->pos_reponse_3.y=450;

}

/**  
* @brief To affiche enigme e .  
* @param e the enigmeImage  
* @param url the url of the image  
* @return Nothing  
*/  

void afficherEnigme(enigmeImage e, SDL_Surface * screen){
 
	SDL_BlitSurface(e.question,NULL, screen, &e.pos_question );
	SDL_BlitSurface(e.reponse_1,NULL,screen,&e.pos_reponse_1);
        SDL_BlitSurface(e.reponse_2,NULL,screen,&e.pos_reponse_2);
        SDL_BlitSurface(e.reponse_3,NULL,screen,&e.pos_reponse_3);
}

/**  
* @brief To free the enigme e .  
* @param e the enigme  
* @param url the url of the image  
* @return Nothing  
*/  
void free_surface_enigme( enigmeImage *e ){

	SDL_FreeSurface(e->question);
	SDL_FreeSurface(e->reponse_1);
        SDL_FreeSurface(e->reponse_2);
        SDL_FreeSurface(e->reponse_3);
}
/**  
* @brief To animate the screen .  
* @param screen  
* @param url the url of the image  
* @return Nothing  
*/  

void animer (SDL_Surface * screen){
	Animation image;
        int i=0,j,num=0;
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
			SDL_Delay(550);
			 SDL_Flip(screen);

			num++;

			}
		//}
		for(i=0;i<16;i++){
		SDL_FreeSurface(image.tab[i]);
		}
	
}



