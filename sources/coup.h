#pragma once
using namespace std;
#include "plateau.h"
#include<stack>

class plateau;

class Coup {
public :
   cases b_bouges[3] ; // coordonnées des billes à déplacer
   int size ;
   stack<cases> sumito ;
   cases dmove ; // direction du déplacement
   cases dboules ; //direction des boules
   int couleur ; //1 noir 2 blanc
   Coup();
  Coup(cases tpix[61],cases tco[61], plateau p, int joueur) ;
  Coup(cases listeboules[15], plateau p, int joueur) ;
  Coup(plateau p, cases bouledep, cases adboules, int asize, cases admove, int ajoueur);
  bool estCorrect(plateau p) ;
  
};
struct IA {
	int valeur;
	Coup coup;
	//plateau p;
	IA();
	bool operator<(IA IA1){
    return (valeur<IA1.valeur);
	 }

};
Coup IA1(int profondeur, cases listeboules[15], plateau p, int joueur);



