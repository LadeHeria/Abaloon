#include "plateau.h"
#include "coup.h"
#include "annexe.h"
#include <stack>
#include <cmath>
using namespace std ;

cases min(cases a, cases b){
  if (abs(a.x)+abs(a.y)<abs(b.x)+abs(b.y)) return a ;
  else return b ;
}

cases mins(stack<cases> s){
  if (empty(s)) return 0 ; 
  stack<cases> t = stack<cases> s ;
  cases m=t.pop() ;
  return min(m,mins(t));
}


  

Coup::Coup(cases tpix[61],cases tco[61]) {
  i.push(souris(tpix,tco)) ; //on rentre la première case
  cases n=souris(tpix,tco) ; 
  while (get(n)==get(i[0])) {//tant que c'est des cases de la même couleur, on les met...
    i.push(souris(tpix,tco)) ; n=souris(tpix,tco)  ;
  }
    i.push(mins(n-) ;//on rentre en dernier la direction (attention, pas bijectif, éviter les cas prêtant à confusion)
  
}
  





int estCorrect(Coup *coup, Plateau *p, char joueur){
    int nombreBillesSelectionnees = 0, nombreBillesJoueur = 0, nombreBillesAdversaire = 0,
        x = coup->x, y = coup->y, test = 0, i = 0;
    /*
    La variable test devient vraie quand on rencontre une bille adverse sur la trajectoire,
    si on retrouve une bille du joueur ensuite, le coup n'est pas valide.
    */
    int dirSelection[2] = {0}; /* il permet d'éviter de modifier le Coup pour les test. */
    char trajectoire[6] = {0}; /* il contiendra toutes les billes sur la trajectoire de la bille de départ. */

    if (p->plateau[x][y]!=joueur || coup->dirDeplacement[0]*coup->dirDeplacement[1]<0
            || (coup->dirDeplacement[0]==0 && coup->dirDeplacement[1]==0)
            || fabs(coup->dirDeplacement[0])>1 || fabs(coup->dirDeplacement[1])>1
            || coup->dirSelection[0]*coup->dirSelection[1]<0
            || (coup->dirSelection[0]==0 && coup->dirSelection[1]==0)
            || fabs(coup->dirSelection[0])>2 || fabs(coup->dirSelection[1])>2) return 0;
    /*
    Ce test permet de vérifier que le coup déplace une bille du joueur
    et ce avec avec des vecteurs de direction et de sélection corrects.
    */
    else if (coup->estRectiligne)
    {
        for (i=0; i<6; i++)
        {
            if (p->plateau[x][y]==joueur)
            {
                if (test) return 0;
                nombreBillesJoueur++;
                trajectoire[i] = joueur;
                x += coup->dirDeplacement[0];
                y += coup->dirDeplacement[1];
            }
            else if (p->plateau[x][y]==adversaire(joueur))
            {
                nombreBillesAdversaire++;
                trajectoire[i] = adversaire(joueur);
                test++;
                x += coup->dirDeplacement[0];
                y += coup->dirDeplacement[1];
            }
        }
        if (nombreBillesJoueur>3 || nombreBillesJoueur<=nombreBillesAdversaire
                || (p->plateau[x][y]!='.' && trajectoire[nombreBillesJoueur+nombreBillesAdversaire-1]==joueur)) return 0;
        /* ce test vérifie que les nombres de billes sont conformes et que le joueur ne suicide pas une bille. */
    }
    else
    {
        nombreBillesSelectionnees = max(fabs(coup->dirSelection[0]),fabs(coup->dirSelection[1]));
        dirSelection[0] = (coup->dirSelection[0]>0)? 1: ((coup->dirSelection[0]<0)? -1: 0); /* On normalise le vecteur de sélection. */
        dirSelection[1] = (coup->dirSelection[1]>0)? 1: ((coup->dirSelection[1]<0)? -1: 0);
        if (dirSelection[0]*coup->dirDeplacement[1]==dirSelection[1]*coup->dirDeplacement[0]) return 0;
        /*ce test vérifie que les vecteurs de sélection et de déplacement ne sont pas colinéaires. */
        for (i=0; i<=nombreBillesSelectionnees; i++)
        {
            if (p->plateau[x][y] != joueur || p->plateau[x+coup->dirDeplacement[0]][y+coup->dirDeplacement[1]]!='.') return 0;
            /* ce test vérifie que le coup sélectionne des billes du joueur et pars vers des cases vides. */
            x += dirSelection[0];
            y += dirSelection[1];
        }
    }
    return 1;
}

void Coup::executeCoup(plateau p)
{
    int x = coup->x, y = coup->y, k = 0, nombreBillesSelectionnees = 1;
    char echange = '.', temp = ' ';

    if (coup->estRectiligne)
    {
        do
        {
            temp = p->plateau[x][y];
            p->plateau[x][y] = echange;
            echange = temp;
            x += coup->dirDeplacement[0];
            y += coup->dirDeplacement[1];
        }
        while ((p->plateau[x][y]=='B' || p->plateau[x][y]=='N'|| p->plateau[x][y]=='.')
                && (echange=='B' || echange=='N'));
    }
    else
    {
        nombreBillesSelectionnees = max(fabs(coup->dirSelection[0]),fabs(coup->dirSelection[1]));
        coup->dirSelection[0] = (coup->dirSelection[0]>0)? 1: ((coup->dirSelection[0]<0)? -1: 0); /* On normalise le vecteur de sélection. */
        coup->dirSelection[1] = (coup->dirSelection[1]>0)? 1: ((coup->dirSelection[1]<0)? -1: 0);
        coup->estRectiligne = 1;
        for (k=0; k<=nombreBillesSelectionnees; k++)
        {
            executerCoup(coup , p);
            coup->x += coup->dirSelection[0];
            coup->y += coup->dirSelection[1];
        }
    } 
}

void rechercherCoup(Coup *coupRetour, Plateau *p, char joueur)
{
    Coup *coupsPossibles =  NULL; /* le nombre maximal de coups possibles pour un tour est de 148. */
    Coup coup = {0};
    int x = 0, y = 0, i = 0, j = 0, k = 0, l = 0, m = 0, n = 0;
    coupsPossibles = calloc(148, sizeof(Coup));
    for (x=0; x<9; x++)
    {
        for (y=0; y<10; y++) /* On génère tous les points de départ, */
        {
            if (p->plateau[x][y]==joueur)
            {
                for (i=-1; i<=1; i++)
                {
                    for (j=-1; j<=1; j++) /* Toutes les directions de déplacements, */
                    {
                        initialiserCoup(&coup, x, y, 1, 1, i, j, 1);
                        if (estCorrect(&coup, p, joueur)) /* On teste le coup obtenu, */
                        {
                            initialiserCoup(&coupsPossibles[m], x, y, 1, 1, i, j, 1); /* On l'ajoute, */
                            m++;
                            for (k=-2; k<=2; k++)
                            {
                                for (l=-2; l<=2; l++) /* On génère toutes les directions de sélection, */
                                {
                                    initialiserCoup(&coup, x, y, k, l, i, j, 0);
                                    if (estCorrect(&coup, p, joueur)) /* On teste le coup obtenu, */
                                    {
                                        initialiserCoup(&coupsPossibles[m], x, y, k, l, i, j, 0); /* On l'ajoute. */
                                        m++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    n = rand()% (m-1);
    initialiserCoup(coupRetour, coupsPossibles[n].x, coupsPossibles[n].y, coupsPossibles[n].dirSelection[0], coupsPossibles[n].dirSelection[1], coupsPossibles[n].dirDeplacement[0], coupsPossibles[n].dirDeplacement[1], coupsPossibles[n].estRectiligne);
}

void afficherCoup(Coup *coup)
{
    printf("\n%d%d %d%d %d%d %d \n", coup->x,coup->y,coup->dirSelection[0],coup->dirSelection[1],coup->dirDeplacement[0],coup->dirDeplacement[1],coup->estRectiligne);
}

void coupHumain(char joueur, Plateau *p, Liste *liste)
{
    char *entree = malloc(9*sizeof(char));
    Coup coup = {0};
    int compteur = 0;
    do
    {
        compteur++;
        printf("Joueur %c entrez un coup valide\n", joueur);
        scanf("%9s", entree);
   if (!strcmp(entree,"sauver")) {
            sauvegarder(p, joueur);
        }

       if (!strcmp(entree,"undo")) {
            undo(p, liste);
            undo(p, liste);
        }
        if (!strcmp(entree,"redo")) {
            redo(p, liste);
            redo(p, liste);
        }
        traduireCoup(entree, &coup);
        if (compteur%4==0) afficher(p); /* Pour continuer à voir le plateau après quelques erreurs... */
    }
    while (!estCorrect(&coup, p, joueur));
   executerCoup(&coup, p); 
   insertion(liste, p);
   afficher(p);
}

void coupRobot(char joueur, Plateau *p, Liste *liste)
{
    Coup coup = {0};
    rechercherCoup(&coup, p, joueur);
    executerCoup(&coup, p);
    insertion(liste, p); 
    afficher(p);
}

