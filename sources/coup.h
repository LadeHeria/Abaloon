#pragma once
using namespace std;
#include "plateau.h"
#include<stack>

class plateau;

class Coup {
public :
   cases b_bouges[3] ; // coordonn�es des billes � d�placer
   int size ;//nombre de boules � bouger
   stack<cases> sumito ;///nombre de boules � pousser
   cases dmove ; // direction du d�placement
   cases dboules ; //direction des boules
   int couleur ; //1 noir 2 blanc
   Coup();//constructeur simple
  Coup(cases tpix[61],cases tco[61], plateau p, int joueur) ;//contructeur pour l'utilisateur � partir de clics � la souris.
  Coup(cases listeboules[15], plateau p, int joueur) ;//constructeur al�atoire
  Coup(plateau p, cases bouledep, cases adboules, int asize, cases admove, int ajoueur);
  bool estCorrect(plateau p) const ;//juge de la correction d'un coup. Admissible ou non selon les r�gles d'abalone.
  
};


struct IA { //structure qui stock un coup et le nombre de points associ�s
	int valeur;
	Coup coup;
	//plateau p;
	IA();
	

};


bool aubord(cases c);//une case se trouve-t-elle au bord ?

Coup IA1(int profondeur, cases listeboules[15], plateau p, int joueur);//IA qui pousse l'adversaire en dehors du terrain lorsqu'elle le peut
Coup IA2(int profondeur, cases listeboules[15], plateau p, int joueur);//IA qui en plus de pousser, �prouve une pr�g�rence pour le centre
Coup IAborophobe(int profondeur, cases listeboules[15], plateau p, int joueur);//IA cens�e fuir les bords (pas au point)
/*Coup IA3(int profondeur, cases listeboules[15], plateau p, int joueur);
int Minf(int profondeur,IA IA33);
int Maxf(int profondeur, IA IA33);
*/



