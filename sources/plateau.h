#pragma once
#include <Imagine/Graphics.h>
using namespace Imagine;
using namespace std ;
#include "annexe.h"
#include "coup.h"

///Le type "case" est un couple de nombre ; on l'utilise autant pour indiquer une position sur le plateau, qu'une direction


//O case vide
//1 case noire
//2 cases blanche
//3 dehors


class plateau {
	int t[61];//61 cases sur un plateau ; on les stock dans un vecteur de taille 61 en parcourant le plateau de la gauche vers la droite et du bas vers le haut
	int boules_b;//nombre de boules blanches sur le plateau
	int boules_n;//nombre de boules noires sur le plateau
	cases tco[61];//index des coordonnées. 0<->(-4;1), 1<->(-4;2)...
public:
	plateau();//contructeur
	int get(cases c);//qu'y a-t-il en c ?
	void set(cases c, int v);//valeur v affectée à la case c
	void deplacement(cases c,cases d, int &score_b, int &score_n);//on déplace la boule en c dans la direction d + maj des scores
	void executeCoup(Coup coup, int &score_b, int &score_n);//on execute un coup + maj des scores
	void listeboules(int joueur, cases boules[15]);//rentre dans le tableau "boules" les positions des boules du "joueur" ; la 15ème case contient le nombre de boules du joueur <15
	bool estdedans(cases c);//un couple de coordonnées se réfère-t-il à une case du plateau ?
	int evalCoup(Coup coup);//une fonction de notation d'un coup. Un coup pertinent est mieux noté qu'un coup banal. Fonction purement ordinale. Ici un point = une boule sortie.
	int evalCoup2(Coup coup);//fonction de notation plus fine. Le centre a une valeur (car sécurise les boules). 
};
