#include <iostream>
#include "annexe.h"
#include <Imagine/Graphics.h>
#include "plateau.h"
#pragma once
using namespace Imagine;
using namespace std ;





void affiche_boule3(cases s, cases tpix[61], cases tco[61], Color co); //affichage d'une boule de couleur "co" en lieu "s"

void affiche_t(plateau p,cases tco[61], cases tpix[61]);//affichage du plateau


//cette fonction g�n�re un tableau de points comportant la position des sommets haut-gauche des boules)
//Pour une image de largeur 2000*1736.
//Premier carr� : 513 ;120 
//largeur carr� : 143
//D�calage � droite +193
//D�calage en bas (449 ;288) soit 168

