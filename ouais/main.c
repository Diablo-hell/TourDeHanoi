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

void initPiliers(int N, int pilier1[], int pilier2[], int pilier3[])
{



int i=0;


    for (i=0; i<N; i++)
    {
        pilier1[i]=i+1;
        pilier2[i]=0;
        pilier3[i]=0;

    }
}

void tableauToDisque(int pilier1[], int pilier2[],int  pilier3[],SDL_Renderer *renderer, int N, SDL_Window *window)
{
    int i=0;
    for (i=0; i<N; i++)
    {
        afficherDisque(renderer, pilier1[i], 1, i+1, pilier1[i]%9,N,window);
        afficherDisque(renderer, pilier2[i], 2, i+1, pilier2[i]%9,N,window);
        afficherDisque(renderer, pilier3[i], 3, i+1, pilier3[i]%9,N,window);
    }

}
int maxTableau(int tableau[], int indicemax)
{
    int i=0, c=0;
    for (i=indicemax; i>=0; i--)
    {
        c = tableau[i];
        if (c!=0)
        {
            break;
        }
    }
    return c;
}
int indiceTableau(int tableau[], int indicemax)
{
    int i, c=0;
    for (i=indicemax; i>=0; i--)
    {
        c = tableau[i];

        if (c!=0)
        {
            break;
        }
    }



    return i;
}
void Hanoi(int n, char depart, char arrivee, char libre, int pilier1[],int pilier2[],int pilier3[],int secondes, int N, SDL_Renderer *renderer,SDL_Window *window)
{
static int g=0;
if (n>0) {

Hanoi(n-1,depart,libre,arrivee,pilier1,pilier2,pilier3, secondes,N, renderer,window);
int f,q,d;

if (depart=='A' && arrivee == 'B')
{
    f=maxTableau(pilier1,N-1);
    q=indiceTableau(pilier1,N-1);
    d=indiceTableau(pilier2,N-1);
    pilier2[d+1]=f;
    pilier1[q]=0;



}

else if (depart=='A' && arrivee == 'C')
{
f=maxTableau(pilier1,N-1);
    q=indiceTableau(pilier1,N-1);
    d=indiceTableau(pilier3,N-1);
    pilier3[d+1]=f;
    pilier1[q]=0;

}

else if (depart=='B' && arrivee == 'A')
{
f=maxTableau(pilier2,N-1);
    q=indiceTableau(pilier2,N-1);
    d=indiceTableau(pilier1,N-1);
    pilier1[d+1]=f;
    pilier2[q]=0;

}

else if (depart=='B' && arrivee == 'C')
{
f=maxTableau(pilier2,N-1);
    q=indiceTableau(pilier2,N-1);
    d=indiceTableau(pilier3,N-1);
    pilier3[d+1]=f;
    pilier2[q]=0;

}

else if (depart=='C' && arrivee == 'A')
{
f=maxTableau(pilier3,N-1);
    q=indiceTableau(pilier3,N-1);
    d=indiceTableau(pilier1,N-1);
    pilier1[d+1]=f;
    pilier3[q]=0;

}

else if (depart=='C' && arrivee == 'B')
{
f=maxTableau(pilier3,N-1);
    q=indiceTableau(pilier3,N-1);
    d=indiceTableau(pilier2,N-1);
    pilier2[d+1]=f;
    pilier3[q]=0;

}

g=g+1;


SDL_RenderClear(renderer);

jouerLet(renderer,window);

tableauToDisque(pilier1, pilier2, pilier3, renderer, N, window);



    SDL_RenderPresent(renderer);
SDL_Delay(secondes);
Hanoi(n-1,libre,arrivee,depart,pilier1,pilier2,pilier3,secondes, N, renderer,window);
}
}
void afficherDisque(SDL_Renderer *renderer, int valeurDisque, int pilier, int index, int couleur, int N, SDL_Window *window)
{
    if (valeurDisque!=0)
    {


    if(couleur==0)
        {SDL_SetRenderDrawColor(renderer,255,0,0, SDL_ALPHA_OPAQUE);} // ROUGE
    if(couleur==1)
        {SDL_SetRenderDrawColor(renderer,0,255,0, SDL_ALPHA_OPAQUE);} // BLEU
    if(couleur==2)
        {SDL_SetRenderDrawColor(renderer,0,0,255,SDL_ALPHA_OPAQUE);} // VERT
    if(couleur==3)
        {SDL_SetRenderDrawColor(renderer,255,128,0,SDL_ALPHA_OPAQUE);} // ORANGE
    if(couleur==4)
        {SDL_SetRenderDrawColor(renderer,0,255,128,SDL_ALPHA_OPAQUE);} // TURQUOISE
    if(couleur==5)
        {SDL_SetRenderDrawColor(renderer,128,0,255,SDL_ALPHA_OPAQUE);}  // VIOLET
    if(couleur==6)
        {SDL_SetRenderDrawColor(renderer,255,255,0, SDL_ALPHA_OPAQUE);} // JAUNE
    if(couleur==7)
        {SDL_SetRenderDrawColor(renderer,0,255,255, SDL_ALPHA_OPAQUE);} // CYAN
    if(couleur==8)
        {SDL_SetRenderDrawColor(renderer,255,0,255, SDL_ALPHA_OPAQUE);}  // MAGENTA
    int largeurFN, hauteurFN, decalage=20;
    if (N<=3)
    {
        decalage=80;
    }
    else if (N==4)
    {
        decalage=70;
    }
    else if (N==5)
    {
        decalage=50;
    }
    else if (N<=7)
    {
        decalage=40;
    }
    else if (N<=9)
    {
        decalage=30;
    }
    else if (N<=14)
    {
        decalage = 20;
    }
    else {decalage = 15;}
    SDL_GetWindowSize(window, &largeurFN, &hauteurFN);
    SDL_Rect Disque;
    Disque.w=380*largeurFN/1280-(valeurDisque*decalage);
    Disque.h=40;
    Disque.y=hauteurFN-(index*Disque.h);
    if (pilier==1)
        {Disque.x=largeurFN/6-(Disque.w)/2;}
    else if (pilier==2)
        {Disque.x=largeurFN/2-(Disque.w)/2;}
    else if (pilier==3)
        {Disque.x=largeurFN*5/6-(Disque.w)/2;}

    Disque.h=40;

    SDL_RenderFillRect(renderer, &Disque);
    SDL_SetRenderDrawColor(renderer,0,0,0,SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(renderer, &Disque);
    }

}
void jouerLet(SDL_Renderer *renderer,SDL_Window *window)
{
    int largeurFN, hauteurFN;
    SDL_GetWindowSize(window,&largeurFN,&hauteurFN);
    SDL_RenderClear(renderer);
    if (largeurFN==1280 && hauteurFN==720)
    {
        afficherImage("fond720.jpg", renderer, 0,0);
        SDL_SetRenderDrawColor(renderer, 242,132,11, SDL_ALPHA_OPAQUE);
        SDL_Rect pilier;
        pilier.x=203;
        pilier.y=60;
        pilier.h=660;
        pilier.w=20;
        SDL_RenderFillRect(renderer, &pilier);

        pilier.x=630;

        SDL_RenderFillRect(renderer, &pilier);

        pilier.x=1057;

        SDL_RenderFillRect(renderer, &pilier);
    }
    else
    {
        afficherImage("fond1080.jpg",renderer,0,0);
        SDL_SetRenderDrawColor(renderer, 242,132,11, SDL_ALPHA_OPAQUE);
        SDL_Rect pilier;
        pilier.x=largeurFN/6-15;
        pilier.y=60;
        pilier.h=hauteurFN-pilier.y;
        pilier.w=30;
        SDL_RenderFillRect(renderer, &pilier);

        pilier.x=largeurFN/2-15;

        SDL_RenderFillRect(renderer, &pilier);

        pilier.x=largeurFN*5/6-15;

        SDL_RenderFillRect(renderer, &pilier);
    }


    SDL_RenderPresent(renderer);





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

SDL_Surface afficherTexte(const char policeT[],const char texte[],SDL_Renderer *renderer, int taille, int x, int y, SDL_Color couleur)
{
        TTF_Font *police = NULL;
        police = TTF_OpenFont(policeT, taille);
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
    int N=8, secondes=50,R1,R2,R3,RA,RB,RC;

    FILE* fichier = NULL;

    fichier = fopen("couleurs.txt", "r");

    if (fichier != NULL)
    {
        fscanf(fichier, "%d %d %d\n", &R1, &R2, &R3);
        fscanf(fichier, "%d %d %d", &RA, &RB, &RC);
        fclose(fichier);
    }
    fichier = fopen("settings.txt", "r");
    if (fichier != NULL)
    {
        fscanf(fichier, "%d\n", &N);
        fscanf(fichier, "%d", &secondes);
        fclose(fichier);
    }
    char nbdisc[3]="", sleep[5]="";
    sprintf(nbdisc, "%d", N);
    sprintf(sleep, "%d", secondes);


    int *pilier1=NULL, *pilier2=NULL, *pilier3=NULL;
    pilier1 = malloc(sizeof(int)*N);
    pilier2 = malloc(sizeof(int)*N);
    pilier3 = malloc(sizeof(int)*N);
    initPiliers(N, pilier1,pilier2,pilier3);
    int largeurFS=0,hauteurFS=0;

    /* Initialisation simple */
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    }
        SDL_Color couleurNoir = {R1,R2,R3};
        SDL_Color couleurBleu = {RA,RB,RC};
        TTF_Init();
        /* Création de la fenêtre */
        SDL_Window* window = NULL;
        SDL_Renderer *renderer = NULL;

        SDL_CreateWindowAndRenderer(LARGEURW, HAUTEURW,0,&window,&renderer);
        int window_full=0, xJouer=900, yJouer=400, jouerSouris=0, optionsSouris=0, xDisques = 250, yDisques = 400;
        int xSleep = xDisques, ySleep= yDisques+50;


        double ratio = 0;
        SDL_SetWindowTitle(window, "Tour de Hanoi");

        afficherImage("fond720.jpg", renderer, 0, 0);

        SDL_SetRenderDrawColor(renderer, 255,255,255,255);

        int xTitre =100, yTitre =60;
        afficherTexte("acme.ttf", "Les Tours de Hanoi", renderer, 120, xTitre, yTitre,couleurNoir);
        SDL_Surface jouer = afficherTexte("righteous.ttf","Jouer", renderer, 125, xJouer, yJouer, couleurNoir);
        int jouerW =jouer.w-20, jouerH = jouer.h-20;
        int xOptions =xJouer, yOptions=yJouer + jouerH-10;
        SDL_Surface options = afficherTexte("righteous.ttf","Options", renderer, 60, xOptions, yOptions, couleurNoir);
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
                                    SDL_RenderClear(renderer);
                                    jouerLet(renderer,window);
                                    tableauToDisque(pilier1,pilier2,pilier3,renderer,N,window);
                                    SDL_RenderPresent(renderer);
                                    SDL_Delay(secondes);
                                    Hanoi(N,'A','C','B',pilier1,pilier2,pilier3,secondes,N, renderer,window);
                                    initPiliers(N,pilier1,pilier2,pilier3);

                              }
                            else if (event.button.x>=xOptions && event.button.x<=(xOptions + optionsW+20) && event.button.y >=yOptions+10 && event.button.y<=(yOptions +optionsH+15))
                            {
                                free(pilier1);
                                free(pilier2);
                                free(pilier3);
                                 pilier1 = malloc(sizeof(int)*N);
                                    pilier2 = malloc(sizeof(int)*N);
                                        pilier3 = malloc(sizeof(int)*N);
                                    initPiliers(N, pilier1,pilier2,pilier3);
                                FILE* fichier = NULL;

                                    fichier = fopen("couleurs.txt", "r");

                                if (fichier != NULL)
                                    {
                                        fscanf(fichier, "%d %d %d\n", &R1, &R2, &R3);
                                            fscanf(fichier, "%d %d %d", &RA, &RB, &RC);
                                            fclose(fichier);
                                            }
                                            fichier = fopen("settings.txt", "r");
                                if (fichier != NULL)
                                            {
                                                fscanf(fichier, "%d\n", &N);
                                            fscanf(fichier, "%d", &secondes);
                                            fclose(fichier);
                                                }

                                            sprintf(nbdisc, "%d", N);
                                            sprintf(sleep, "%d", secondes);
                                        free(pilier1);
                                        free(pilier2);
                                        free(pilier3);
                                        pilier1 = malloc(sizeof(int)*N);
                                        pilier2 = malloc(sizeof(int)*N);
                                        pilier3 = malloc(sizeof(int)*N);
                                    initPiliers(N, pilier1,pilier2,pilier3);
                               SDL_RenderClear(renderer);// OPTIONS PAS FULLSCREEN
                            afficherImage("fond720.jpg", renderer, 0, 0);
                            afficherTexte("acme.ttf", "Options", renderer, 120, xTitre, yTitre,couleurNoir);
                            afficherTexte("righteous.ttf", "Nombre de disques : ", renderer, 50, xDisques, yDisques,  couleurNoir);
                            afficherTexte("righteous.ttf", nbdisc, renderer, 50, xDisques + 750, yDisques,  couleurNoir );
                            afficherTexte("righteous.ttf", "Temps entre chaque étape : ", renderer, 50, xSleep, ySleep,  couleurNoir);
                            afficherTexte("righteous.ttf", sleep, renderer, 50, xSleep +750, ySleep, couleurNoir );

                            SDL_RenderPresent(renderer);









                                }




                            }





                    else  if (window_full%2==1)

                        {
                            if (event.button.x>=xJouer*ratio && event.button.x<=(xJouer*ratio + jouerW+20) && event.button.y >=yJouer*ratio+25 && event.button.y<=(yJouer*ratio +jouerH-15))
                            {
                                    SDL_RenderClear(renderer);
                                    jouerLet(renderer,window);
                                    tableauToDisque(pilier1,pilier2,pilier3,renderer,N,window);
                                    SDL_RenderPresent(renderer);
                                    SDL_Delay(secondes);
                                    Hanoi(N,'A','C','B',pilier1,pilier2,pilier3,secondes,N, renderer,window);
                                    initPiliers(N,pilier1,pilier2,pilier3);
                            }

                            else if (event.button.x>=xOptions*ratio && event.button.x<=(xOptions*ratio + optionsW+20) && event.button.y >=ratio*yJouer + jouerH-5 && event.button.y<=(ratio*yJouer + jouerH-10 +optionsH+15))
                            {
                                free(pilier1);
                                free(pilier2);
                                free(pilier3);
                                FILE* fichier = NULL;

                                    fichier = fopen("couleurs.txt", "r");

                                    if (fichier != NULL)
                                            {
                                        fscanf(fichier, "%d %d %d\n", &R1, &R2, &R3);
                                                                fscanf(fichier, "%d %d %d", &RA, &RB, &RC);
                                            fclose(fichier);
                                                        }
                                                fichier = fopen("settings.txt", "r");
                                            if (fichier != NULL)
                                                    {
                                    fscanf(fichier, "%d\n", &N);
                                    fscanf(fichier, "%d", &secondes);
                                    fclose(fichier);
                                        }

                                        sprintf(nbdisc, "%d", N);
                                        sprintf(sleep, "%d", secondes);
                                        free(pilier1);
                                        free(pilier2);
                                        free(pilier3);
                                        pilier1 = malloc(sizeof(int)*N);
                                        pilier2 = malloc(sizeof(int)*N);
                                        pilier3 = malloc(sizeof(int)*N);
                                    initPiliers(N, pilier1,pilier2,pilier3);
                            SDL_RenderClear(renderer);// OPTIONS FULLSCREEN
                            afficherImage("fond1080.jpg", renderer, 0, 0);
                            afficherTexte("acme.ttf", "Options", renderer, 120, ratio*xTitre, ratio*yTitre,couleurNoir);
                            afficherTexte("righteous.ttf", "Nombre de disques : ", renderer, 50, ratio*xDisques, ratio*yDisques,  couleurNoir);
                            afficherTexte("righteous.ttf", nbdisc, renderer, 50, ratio*xDisques + 750, ratio*yDisques,  couleurNoir );
                            afficherTexte("righteous.ttf", "Temps entre chaque étape : ", renderer, 50, ratio*xSleep, ratio*ySleep,  couleurNoir);
                            afficherTexte("righteous.ttf", sleep, renderer, 50, ratio*xSleep +750, ratio*ySleep,  couleurNoir );

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

                            afficherTexte("acme.ttf", "Les Tours de Hanoi", renderer, 120, ratio*xTitre, ratio*yTitre,couleurNoir);
                            SDL_Surface jouer = afficherTexte("righteous.ttf", "Jouer", renderer, 125,ratio*xJouer,ratio*yJouer,couleurNoir);

                            SDL_Surface options = afficherTexte("righteous.ttf","Options", renderer, 60, ratio*xOptions, ratio*yJouer + jouerH-10, couleurNoir);



                        }
                        else if (window_full%2==1)
                        {
                            SDL_SetWindowFullscreen(window, 0);
                            SDL_RenderClear(renderer);

                            afficherImage("fond720.jpg", renderer, 0, 0);
                            afficherTexte("acme.ttf", "Les Tours de Hanoi", renderer, 120, xTitre, yTitre,couleurNoir);
                            SDL_Surface jouer = afficherTexte("righteous.ttf","Jouer", renderer, 125, xJouer, yJouer,couleurNoir);

                            SDL_Surface options = afficherTexte("righteous.ttf","Options", renderer, 60, xOptions, yOptions, couleurNoir);



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
                                        afficherTexte("acme.ttf", "Les Tours de Hanoi", renderer, 120, xTitre, yTitre,couleurNoir);
                                        afficherTexte("righteous.ttf", "Jouer", renderer, 125, xJouer, yJouer,couleurBleu);
                                        afficherTexte("righteous.ttf","Options", renderer, 60, xOptions, yOptions, couleurNoir);
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
                                        afficherTexte("acme.ttf", "Les Tours de Hanoi", renderer, 120, xTitre, yTitre,couleurNoir);
                                        afficherTexte("righteous.ttf", "Jouer", renderer, 125, xJouer, yJouer,couleurNoir);
                                        afficherTexte("righteous.ttf","Options", renderer, 60, xOptions, yOptions,  couleurBleu);
                                        SDL_RenderPresent(renderer);
                                        optionsSouris = 1;
                                        }

                            }
                            else {
                                    if (jouerSouris == 1 || optionsSouris == 1)
                                    {
                                        SDL_RenderClear(renderer);
                                        afficherImage("fond720.jpg", renderer, 0, 0);
                                        afficherTexte("acme.ttf", "Les Tours de Hanoi", renderer, 120, xTitre, yTitre,couleurNoir);
                                        afficherTexte("righteous.ttf", "Jouer", renderer, 125, xJouer, yJouer,couleurNoir);
                                        afficherTexte("righteous.ttf","Options", renderer, 60, xOptions, yOptions, couleurNoir);
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
                                        afficherTexte("acme.ttf", "Les Tours de Hanoi", renderer, 120, ratio*xTitre, ratio*yTitre,couleurNoir);
                                        afficherTexte("righteous.ttf", "Jouer", renderer, 125,(ratio*xJouer),(ratio*yJouer),couleurBleu);
                                        afficherTexte("righteous.ttf","Options", renderer, 60, ratio*xOptions, ratio*yJouer + jouerH-10, couleurNoir);
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
                                        afficherTexte("acme.ttf", "Les Tours de Hanoi", renderer, 120, ratio*xTitre, ratio*yTitre,couleurNoir);
                                        afficherTexte("righteous.ttf", "Jouer", renderer, 125, ratio*xJouer, ratio*yJouer,couleurNoir);
                                        afficherTexte("righteous.ttf","Options", renderer, 60, ratio*xOptions, ratio*yJouer + jouerH-10,  couleurBleu);
                                        SDL_RenderPresent(renderer);
                                        optionsSouris = 1;
                                        }

                            }
                            else {
                                    if (jouerSouris == 1 || optionsSouris == 1)
                                    {
                                        SDL_RenderClear(renderer);
                                        afficherImage("fond1080.jpg", renderer, 0,0);
                                        afficherTexte("acme.ttf", "Les Tours de Hanoi", renderer, 120, ratio*xTitre, ratio*yTitre,couleurNoir);
                                        afficherTexte("righteous.ttf", "Jouer", renderer, 125,ratio*xJouer,ratio*yJouer,couleurNoir);
                                        afficherTexte("righteous.ttf","Options", renderer, 60, ratio*xOptions, ratio*yJouer + jouerH-10,  couleurNoir);
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






    free(pilier1);
    free(pilier2);
    free(pilier3);
    SDL_FreeSurface(&jouer);
    SDL_FreeSurface(&options);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();

    return 0;
}
