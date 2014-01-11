#include <iostream>
#include "annexe.h"
#include <Imagine/Graphics.h>
#pragma once
using namespace Imagine;
using namespace std ;



void affiche_plateau() ;

void affiche_boules(int c, int i, cases tableau[60]);

//cette fonction g�n�re un tableau de points comportant la position des sommets haut-gauche des boules)
//Pour une image de largeur 2000*1736.
//Premier carr� : 513 ;120 
//largeur carr� : 143
//D�calage � droite +193
//D�calage en bas (449 ;288) soit 168


//a priori, il n'est pas n�cessaire de faire un pointeur pour un tableau de 61 cases

void generer_places(cases tableau[60], int decalage_x, int decalage_y, int debutx, int debut_y);
