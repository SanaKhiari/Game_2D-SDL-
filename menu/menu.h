#ifndef Backg_H
#define Backg_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#define SCREEN_W 1200
#define SCREEN_H 800
typedef struct
 {
        SDL_Rect pos;
        SDL_Surface * img;
}Image;

typedef struct {
SDL_Surface *bouton;
SDL_Rect pos_boutton;
}boutton;

typedef struct {//++
	SDL_Surface *tab[9]; /*!< Rectangle*/
	SDL_Rect pos_tab;/*!< Surface. */
}Animation;//++


void initBackground(Image *B);
void initBackground_jeu(Image *B);
void initBackground_option(Image *B);
void afficher_back (Image B,SDL_Surface *screen);
void liberer(Image A);
void init_boutton_play1(boutton *A);
void init_boutton_play2(boutton *A);
void init_boutton_option1(boutton *A);
void init_boutton_option2(boutton *A);
void init_boutton_quiter1(boutton *A);
void init_boutton_quiter2(boutton *A);
void liberer_boutton(boutton b);
void afficher_bouton(boutton b , SDL_Surface *screen);
void play1(SDL_Surface *screen);
void animer_Menu( SDL_Surface * screen);
#endif

