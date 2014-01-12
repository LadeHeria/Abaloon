#include <iostream>
#include "annexe.h"
#include <Imagine/Graphics.h>
#pragma once
using namespace Imagine;
using namespace std ;



void affiche_plateau() ;

void affiche_boules(int c, int i, cases tableau[60]);

void affiche_boules2(int c, int i, cases t[60]);

void affiche_boule3(cases s, cases tpix[61], cases tco[61]);

void affiche_t(cases s[61]);

//cette fonction génère un tableau de points comportant la position des sommets haut-gauche des boules)
//Pour une image de largeur 2000*1736.
//Premier carré : 513 ;120 
//largeur carré : 143
//Décalage à droite +193
//Décalage en bas (449 ;288) soit 168


//a priori, il n'est pas nécessaire de faire un pointeur pour un tableau de 61 cases


