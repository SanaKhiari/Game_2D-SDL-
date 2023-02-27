#ifndef enig_fichier_H_INCLUDED
#define enig_fichier_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#define SCREEN_W 1000
#define SCREEN_H 600

/**  
* @struct enigmeImage  
* @brief struct for enigmeImage  
*/  
typedef struct {
	SDL_Surface *question,*reponse_1,*reponse_2,*reponse_3; /*!< Rectangle*/
	SDL_Rect pos_question, pos_reponse_1,pos_reponse_2,pos_reponse_3;/*!< Surface. */
}enigmeImage;

/**  
* @struct Animation  
* @brief struct for Animation  
*/ 
typedef struct {//++
	SDL_Surface *tab[16]; /*!< Rectangle*/
	SDL_Rect pos_tab;/*!< Surface. */
}Animation;//++

void InitEnigme(enigmeImage * e, char *nomfichier);
void afficherEnigme(enigmeImage e, SDL_Surface * screen);
void animer( SDL_Surface * screen);
void free_surface_enigme( enigmeImage *e );

#endif
