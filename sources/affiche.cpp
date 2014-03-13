#include <iostream>
#include "annexe.h"
#include <Imagine/Graphics.h>
#include "affiche.h"
#include <cmath>
#include "plateau.h"
using namespace Imagine;
using namespace std ;



Color couleur(int i){ //convention d'affichage
	if(i==0){return RED;} 
	if(i==1){return BLACK;}
	if(i==2) {return GREEN;}
}




void affiche_boule3(cases s, cases tpix[61], cases tco[61],Color co){ //affiche une boule en "s" de couleur "co", les positions graphiques associ�es au coordonn�es donn�es par les deux tableaux.
  cases c ; 
  c = cotopix(s, tpix, tco) ; //ce que repr�sente la coordonn�e c en terme de pixels
  drawCircle(c.x,c.y,20,co) ;
}
  
 
void affiche_t(plateau p,cases tco[61], cases tpix[61]){ //fonction d'affichage du plateau
  for(int i=0;i<61;i++){
    affiche_boule3(tco[i], tpix, tco, couleur(p.get(tco[i]))) ; //pour chacune des cases du plateau, affiche en tco[i] (coordonn�e) ce qu'il doit y �tre (p.get(tco[i])
  }
}


  