#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

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
void Hanoi(int n, char depart, char arrivee, char libre, int pilier1[],int pilier2[],int pilier3[],int secondes, int N)
{
static int g=0;
if (n>0) {

Hanoi(n-1,depart,libre,arrivee,pilier1,pilier2,pilier3, secondes,N);
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

    Sleep(secondes);

system("CLS");
printf("Tour de Hanoi avec %d etages\n\n",N);
printf("------------- ETAPE %d -------------\n",g);
int i;
for (i=N-1; i>=0; i--)
    {

        printf("\t%d\t%d\t%d\n", pilier1[i], pilier2[i], pilier3[i]);
    }
printf("\n");
Hanoi(n-1,libre,arrivee,depart,pilier1,pilier2,pilier3,secondes, N);
}
}

int main()

{
    int h=0, i=0, nombre_etages=0, c=0, indice=0,secondes=0,N=5;
    int *pilier1=NULL, *pilier2=NULL, *pilier3=NULL;
    printf("Nombre de disques de la tour ?\n");
    scanf("%d", &N);
    printf("Temps entre chaque etape (en ms) ?\n");
    scanf("%d", &secondes);
    pilier1 = malloc(sizeof(int)*N);
    pilier2 = malloc(sizeof(int)*N);
    pilier3 = malloc(sizeof(int)*N);
    for (i=0; i<N; i++)
    {
        pilier1[i]=i+1;
        pilier2[i]=0;
        pilier3[i]=0;

    }
    system("CLS");
    printf("Tour de Hanoi avec %d etages\n\n",N);
    printf("------------- ETAPE 0 -------------\n");
    for (i=N-1; i>=0; i--)
    {
        printf("\t%d\t%d\t%d\n", pilier1[i], pilier2[i], pilier3[i]);
    }


    Hanoi(N,'A','C','B',pilier1,pilier2,pilier3,secondes,N);
    printf("\n\t\t      **********************************\n");
    printf("\t\t ****** (O_o)  VOUS AVEZ GAGNE ! (^-^) ******\n");
    printf("\t\t      **********************************\n");
    system("pause");
return 0;
}
