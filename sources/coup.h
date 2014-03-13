#pragma once
using namespace std;
#include "plateau.h"
#include<stack>

class plateau;

class Coup {
public :
   cases b_bouges[3] ; // coordonnées des billes à déplacer
   int size ;//nombre de boules à bouger
   stack<cases> sumito ;///nombre de boules à pousser
   cases dmove ; // direction du déplacement
   cases dboules ; //direction des boules
   int couleur ; //1 noir 2 blanc
   Coup();//constructeur simple
  Coup(cases tpix[61],cases tco[61], plateau p, int joueur) ;//contructeur pour l'utilisateur à partir de clics à la souris.
  Coup(cases listeboules[15], plateau p, int joueur) ;//constructeur aléatoire
  Coup(plateau p, cases bouledep, cases adboules, int asize, cases admove, int ajoueur);
  bool estCorrect(plateau p) const ;//juge de la correction d'un coup. Admissible ou non selon les règles d'abalone.
  
};


struct IA { //structure qui stock un coup et le nombre de points associés
	int valeur;
	Coup coup;
	//plateau p;
	IA();
	

};


bool aubord(cases c);//une case se trouve-t-elle au bord ?

Coup IA1(int profondeur, cases listeboules[15], plateau p, int joueur);//IA qui pousse l'adversaire en dehors du terrain lorsqu'elle le peut
Coup IA2(int profondeur, cases listeboules[15], plateau p, int joueur);//IA qui en plus de pousser, éprouve une prégérence pour le centre
Coup IAborophobe(int profondeur, cases listeboules[15], plateau p, int joueur);//IA censée fuir les bords (pas au point)
/*Coup IA3(int profondeur, cases listeboules[15], plateau p, int joueur);
int Minf(int profondeur,IA IA33);
int Maxf(int profondeur, IA IA33);
*/



