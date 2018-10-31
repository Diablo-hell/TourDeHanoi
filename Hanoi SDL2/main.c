#ifdef __cplusplus
    #include <cstdlib>
    #include <cstdio>
#else
    #include <stdlib.h>
    #include <stdio.h>
#endif

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#define LARGEURW 1280
#define HAUTEURW 720
char ecriturePseudo (SDL_Event event)
{
    char caractere = 0;
    int maj = 0;

    switch (event.key.keysym.sym)
    {

    case SDLK_a:
        caractere = 'a';//faire le reste
        break;

    case SDLK_b:
        caractere = 'b';//faire le reste
        break;

    case SDLK_c:
        caractere = 'c';//faire le reste
        break;

    case SDLK_d:
        caractere = 'd';//faire le reste
        break;

    case SDLK_e:
        caractere = 'e';//faire le reste
        break;

    case SDLK_f:
        caractere = 'f';//faire le reste
        break;

    case SDLK_g:
        caractere = 'g';//faire le reste
        break;

    case SDLK_h:
        caractere = 'h';//faire le reste
        break;

    case SDLK_i:
        caractere = 'i';//faire le reste
        break;

    case SDLK_j:
        caractere = 'j';//faire le reste
        break;

    case SDLK_k:
        caractere = 'k';//faire le reste
        break;

    case SDLK_l:
        caractere = 'l';//faire le reste
        break;

    case SDLK_m:
        caractere = 'm';//faire le reste
        break;

    case SDLK_n:
        caractere = 'n';//faire le reste
        break;

    case SDLK_o:
        caractere = 'o';//faire le reste
        break;

    case SDLK_p:
        caractere = 'p';//faire le reste
        break;

    case SDLK_q:
        caractere = 'q';//faire le reste
        break;

    case SDLK_r:
        caractere = 'r';//faire le reste
        break;

    case SDLK_s:
        caractere = 's';//faire le reste
        break;

    case SDLK_t:
        caractere = 't';//faire le reste
        break;

    case SDLK_u:
        caractere = 'u';//faire le reste
        break;

    case SDLK_v:
        caractere = 'v';//faire le reste
        break;

    case SDLK_w:
        caractere = 'w';//faire le reste
        break;

    case SDLK_x:
        caractere = 'x';//faire le reste
        break;

    case SDLK_y:
        caractere = 'y';//faire le reste
        break;

    case SDLK_z:
        caractere = 'z';//faire le reste
        break;

    case SDLK_UNDERSCORE:
        caractere = '_';
        break;

    case SDLK_MINUS:
        caractere = '-';
        break;

/*
    case SDLK_SPACE:
        caractere = ' ';
        break;*/

    case SDLK_QUOTE:
        caractere = 96; //ASCII de l'apostrophe
        break;

    case SDLK_0:
        caractere = '0';
        break;

    case SDLK_1:
        caractere = '1';
        break;

    case SDLK_2:
        caractere = '2';
        break;

    case SDLK_3:
        caractere = '3';
        break;

    case SDLK_4:
        caractere = '4';
        break;

    case SDLK_5:
        caractere = '5';
        break;

    case SDLK_6:
        caractere = '6';
        break;

    case SDLK_7:
        caractere = '7';
        break;

    case SDLK_8:
        caractere = '8';
        break;

    case SDLK_9:
        caractere = '9';
        break;

    default:
        caractere = 0;
        break;

    }



    return caractere;

}
void afficherImage(const char chemin[], SDL_Renderer *renderer, int x, int y)
{


    SDL_Surface *image=NULL;
    image = IMG_Load(chemin);
    SDL_Texture *texture = NULL;

    texture = SDL_CreateTextureFromSurface(renderer,image);
    SDL_Rect rect;
    rect.x=x;
    rect.y=y;
    SDL_QueryTexture(texture,NULL,NULL,&rect.w,&rect.h);
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_FreeSurface(image);
    SDL_DestroyTexture(texture);

}
SDL_Surface afficherTexte(const char policeT[],const char texte[],SDL_Renderer *renderer, int taille, int x, int y, int style, SDL_Color couleur)
{
        TTF_Font *police = NULL;
        police = TTF_OpenFont(policeT, taille);
        if (style)
        {
            TTF_SetFontStyle(police, TTF_STYLE_BOLD);
        }
        else TTF_SetFontStyle(police, TTF_STYLE_NORMAL);


        SDL_Surface *surfaceTexte;
        surfaceTexte = TTF_RenderText_Blended(police, texte, couleur);

        SDL_Texture *texture = NULL;
        texture = SDL_CreateTextureFromSurface(renderer,surfaceTexte);
        SDL_Rect rect;
        rect.x=x;
        rect.y=y;
        SDL_QueryTexture(texture,NULL,NULL,&rect.w,&rect.h);

        SDL_RenderCopy(renderer, texture, NULL, &rect);

        SDL_DestroyTexture(texture);
        TTF_CloseFont(police);
        return *surfaceTexte;
}



int main(int argc, char** argv)
{
    int largeurFS=0,hauteurFS=0;
    /* Initialisation simple */
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    }
        SDL_Color couleurNoir = {252,101,1};
        SDL_Color couleurBleu = {236,169,17};
        TTF_Init();
        /* Création de la fenêtre */
        SDL_Window* window = NULL;
        SDL_Renderer *renderer = NULL;

        SDL_CreateWindowAndRenderer(LARGEURW, HAUTEURW,0,&window,&renderer);
        int window_full=0, xJouer=900, yJouer=400, jouerSouris=0, optionsSouris=0, xDisques = 250, yDisques = 400;
        int xSleep = xDisques, ySleep= yDisques+50;
        int nombreDisques = 6;
        int tempsSleep = 3000;
        int entree =0;
        char nbdisc[2]="", sleep[]="3000";
        int index =1;
        char caractere=0;

        sprintf(nbdisc, "%d", nombreDisques);
        printf("%s", sleep);
        double ratio = 0;
        SDL_SetWindowTitle(window, "Tour de Hanoi");

        afficherImage("fond720.jpg", renderer, 0, 0);


        SDL_SetRenderDrawColor(renderer, 255,255,255,255);

        int xTitre =100, yTitre =60;
        afficherTexte("acme.ttf", "Les Tours de Hanoi", renderer, 120, xTitre, yTitre,0,couleurNoir);
        SDL_Surface jouer = afficherTexte("righteous.ttf","Jouer", renderer, 125, xJouer, yJouer, 0, couleurNoir);
        int jouerW =jouer.w-20, jouerH = jouer.h-20;
        int xOptions =xJouer, yOptions=yJouer + jouerH-10;
        SDL_Surface options = afficherTexte("righteous.ttf","Options", renderer, 60, xOptions, yOptions, 0, couleurNoir);
        int optionsW = options.w-20, optionsH = options.h-20;

        SDL_RenderPresent(renderer);
    //////////////////////////////////////////////////
        SDL_bool menu = SDL_TRUE;
        while(menu)
        {
            SDL_Event event;
            while(SDL_PollEvent(&event))
                switch(event.type)
            {
                case SDL_QUIT:
                    menu=SDL_FALSE;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (window_full%2==0) //SI PAS FULLSCREEN
                        {
                            if (event.button.x>=xJouer && event.button.x<=(xJouer + jouerW+20) && event.button.y >=yJouer+25 && event.button.y<=(yJouer +jouerH-10))
                              {
                                  printf("\nJOUER\n");   // JOUER PAS FULLSCREEN

                              }
                            else if (event.button.x>=xOptions && event.button.x<=(xOptions + optionsW+20) && event.button.y >=yOptions+10 && event.button.y<=(yOptions +optionsH+15))
                            {
                               SDL_RenderClear(renderer);// OPTIONS PAS FULLSCREEN
                            afficherImage("fond720.jpg", renderer, 0, 0);
                            afficherTexte("acme.ttf", "Options", renderer, 120, xTitre, yTitre,0,couleurNoir);
                            afficherTexte("righteous.ttf", "Nombre de disques : ", renderer, 50, xDisques, yDisques, 0, couleurNoir);
                            afficherTexte("righteous.ttf", nbdisc, renderer, 50, xDisques + 750, yDisques, 0 , couleurNoir );
                            afficherTexte("righteous.ttf", "Temps entre chaque étape : ", renderer, 50, xSleep, ySleep, 0, couleurNoir);
                            afficherTexte("righteous.ttf", sleep, renderer, 50, xSleep +750, ySleep, 0 , couleurNoir );

                            SDL_RenderPresent(renderer);

                            while(SDL_PollEvent(&event))
                            {
                                switch(event.type)
                                    {
                                        case SDL_QUIT:
                                            menu=SDL_FALSE;
                                                break;
                                        default:
                                            continue;
                            }







                                }




                            }





                    else  if (window_full%2==1)

                        {
                            if (event.button.x>=xJouer*ratio && event.button.x<=(xJouer*ratio + jouerW+20) && event.button.y >=yJouer*ratio+25 && event.button.y<=(yJouer*ratio +jouerH-15))
                            {
                                  printf("\nJOUER\n");//JOUER  FULLSCREEN
                            }
                            else if (event.button.x>=xOptions*ratio && event.button.x<=(xOptions*ratio + optionsW+20) && event.button.y >=ratio*yJouer + jouerH-5 && event.button.y<=(ratio*yJouer + jouerH-10 +optionsH+15))
                            {
                            SDL_RenderClear(renderer);// OPTIONS FULLSCREEN
                            afficherImage("fond1080.jpg", renderer, 0, 0);
                            afficherTexte("acme.ttf", "Options", renderer, 120, ratio*xTitre, ratio*yTitre,0,couleurNoir);
                            afficherTexte("righteous.ttf", "Nombre de disques : ", renderer, 50, ratio*xDisques, ratio*yDisques, 0, couleurNoir);
                            afficherTexte("righteous.ttf", nbdisc, renderer, 50, ratio*xDisques + 750, ratio*yDisques, 0 , couleurNoir );
                            afficherTexte("righteous.ttf", "Temps entre chaque étape : ", renderer, 50, ratio*xSleep, ratio*ySleep, 0, couleurNoir);
                            afficherTexte("righteous.ttf", sleep, renderer, 50, ratio*xSleep +750, ratio*ySleep, 0 , couleurNoir );

                            SDL_RenderPresent(renderer);
                            }

                        }

                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {

                    case SDLK_ESCAPE:
                        menu=SDL_FALSE;
                        break;

                    case SDLK_F11:
                        SDL_Delay(600);
                        if (window_full%2==0)
                        {
                            SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
                            SDL_RenderClear(renderer);
                            afficherImage("fond1080.jpg", renderer, 0, 0);


                            if (ratio==0)
                            {
                                SDL_GetWindowSize(window, &largeurFS,&hauteurFS);
                                ratio = (double) largeurFS / (double) LARGEURW;
                            }

                            afficherTexte("acme.ttf", "Les Tours de Hanoi", renderer, 120, ratio*xTitre, ratio*yTitre,0,couleurNoir);
                            SDL_Surface jouer = afficherTexte("righteous.ttf", "Jouer", renderer, 125,ratio*xJouer,ratio*yJouer,0,couleurNoir);

                            SDL_Surface options = afficherTexte("righteous.ttf","Options", renderer, 60, ratio*xOptions, ratio*yJouer + jouerH-10, 0, couleurNoir);



                        }
                        else if (window_full%2==1)
                        {
                            SDL_SetWindowFullscreen(window, 0);
                            SDL_RenderClear(renderer);

                            afficherImage("fond720.jpg", renderer, 0, 0);
                            afficherTexte("acme.ttf", "Les Tours de Hanoi", renderer, 120, xTitre, yTitre,0,couleurNoir);
                            SDL_Surface jouer = afficherTexte("righteous.ttf","Jouer", renderer, 125, xJouer, yJouer,0,couleurNoir);

                            SDL_Surface options = afficherTexte("righteous.ttf","Options", renderer, 60, xOptions, yOptions, 0, couleurNoir);



                        }
                        window_full++;
                        SDL_RenderPresent(renderer);
                            break;
                        default:
                        continue;
                    }
                case SDL_MOUSEMOTION:

                    if (window_full%2==0) //SI PAS FULLSCREEN
                        {
                            if (event.motion.x>=xJouer && event.motion.x<=(xJouer + jouerW+20) && event.motion.y >=yJouer+25 && event.motion.y<=(yJouer +jouerH-10)) //si bouton jouer
                                {

                                    if (jouerSouris == 0)
                                    {
                                        SDL_RenderClear(renderer);
                                        afficherImage("fond720.jpg", renderer, 0, 0);
                                        afficherTexte("acme.ttf", "Les Tours de Hanoi", renderer, 120, xTitre, yTitre,0,couleurNoir);
                                        afficherTexte("righteous.ttf", "Jouer", renderer, 125, xJouer, yJouer,0,couleurBleu);
                                        afficherTexte("righteous.ttf","Options", renderer, 60, xOptions, yOptions, 0, couleurNoir);
                                        SDL_RenderPresent(renderer);

                                        jouerSouris=1;


                                    }


                                }
                            else if (event.motion.x>=xOptions && event.motion.x<=(xOptions + optionsW+20) && event.motion.y >=yOptions+10 && event.motion.y<=(yOptions +optionsH+15)) // SI OPTIONS
                            {
                                        if (optionsSouris==0)
                                        {


                                        SDL_RenderClear(renderer);
                                        afficherImage("fond720.jpg", renderer, 0, 0);
                                        afficherTexte("acme.ttf", "Les Tours de Hanoi", renderer, 120, xTitre, yTitre,0,couleurNoir);
                                        afficherTexte("righteous.ttf", "Jouer", renderer, 125, xJouer, yJouer,0,couleurNoir);
                                        afficherTexte("righteous.ttf","Options", renderer, 60, xOptions, yOptions, 0, couleurBleu);
                                        SDL_RenderPresent(renderer);
                                        optionsSouris = 1;
                                        }

                            }
                            else {
                                    if (jouerSouris == 1 || optionsSouris == 1)
                                    {
                                        SDL_RenderClear(renderer);
                                        afficherImage("fond720.jpg", renderer, 0, 0);
                                        afficherTexte("acme.ttf", "Les Tours de Hanoi", renderer, 120, xTitre, yTitre,0,couleurNoir);
                                        afficherTexte("righteous.ttf", "Jouer", renderer, 125, xJouer, yJouer,0,couleurNoir);
                                        afficherTexte("righteous.ttf","Options", renderer, 60, xOptions, yOptions, 0, couleurNoir);
                                        SDL_RenderPresent(renderer);
                                        jouerSouris = 0;
                                        optionsSouris=0;
                                    }


                        }
                        }
                        else  // SI FULLSCREEN
                        {
                            if (event.motion.x>=xJouer*ratio && event.motion.x<=(xJouer*ratio + jouerW+20) && event.motion.y >=yJouer*ratio+25 && event.motion.y<=(yJouer*ratio +jouerH-15))
                                {
                                 if (jouerSouris == 0)
                                    {
                                        SDL_RenderClear(renderer);
                                        afficherImage("fond1080.jpg", renderer, 0, 0);
                                        afficherTexte("acme.ttf", "Les Tours de Hanoi", renderer, 120, ratio*xTitre, ratio*yTitre,0,couleurNoir);
                                        afficherTexte("righteous.ttf", "Jouer", renderer, 125,(ratio*xJouer),(ratio*yJouer),0,couleurBleu);
                                        afficherTexte("righteous.ttf","Options", renderer, 60, ratio*xOptions, ratio*yJouer + jouerH-10, 0, couleurNoir);
                                        SDL_RenderPresent(renderer);
                                        jouerSouris=1;


                                    }


                                }
                                else if (event.motion.x>=xOptions*ratio && event.motion.x<=(xOptions*ratio + optionsW+20) && event.motion.y >=ratio*yJouer + jouerH-5 && event.motion.y<=(ratio*yJouer + jouerH-10 +optionsH+15))
                            {
                                        if (optionsSouris==0)
                                        {


                                        SDL_RenderClear(renderer);
                                        afficherImage("fond1080.jpg", renderer, 0, 0);
                                        afficherTexte("acme.ttf", "Les Tours de Hanoi", renderer, 120, ratio*xTitre, ratio*yTitre,0,couleurNoir);
                                        afficherTexte("righteous.ttf", "Jouer", renderer, 125, ratio*xJouer, ratio*yJouer,0,couleurNoir);
                                        afficherTexte("righteous.ttf","Options", renderer, 60, ratio*xOptions, ratio*yJouer + jouerH-10, 0, couleurBleu);
                                        SDL_RenderPresent(renderer);
                                        optionsSouris = 1;
                                        }

                            }
                            else {
                                    if (jouerSouris == 1 || optionsSouris == 1)
                                    {
                                        SDL_RenderClear(renderer);
                                        afficherImage("fond1080.jpg", renderer, 0,0);
                                        afficherTexte("acme.ttf", "Les Tours de Hanoi", renderer, 120, ratio*xTitre, ratio*yTitre,0,couleurNoir);
                                        afficherTexte("righteous.ttf", "Jouer", renderer, 125,ratio*xJouer,ratio*yJouer,0,couleurNoir);
                                        afficherTexte("righteous.ttf","Options", renderer, 60, ratio*xOptions, ratio*yJouer + jouerH-10, 0, couleurNoir);
                                        SDL_RenderPresent(renderer);
                                        jouerSouris= 0;
                                        optionsSouris=0;
                                    }
                            }
                        }

                        break;



                default:
                    continue;
                    if (menu==SDL_FALSE)
                    {
                        break;
                    }
                }
            }
        }








    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();

    return 0;
}
