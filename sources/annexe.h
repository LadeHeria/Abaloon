//LISSER Marwan

#include <Imagine/Graphics.h>
#include <cstdlib>
#include <ctime>
using namespace Imagine;
using namespace std ;
#pragma once

const int A = -4 ; // pour passer d'une ligne à une autre +/- 1
const int B = -3 ; // !!!! test dans_plateau : 0<|lettre|+chiffre-pos(lettre) <10
const int C = -2 ;
const int D = -1 ;
const int E = 0 ;
const int F = 1 ;
const int G = 2 ;
const int H = 3 ;
const int I = 4 ;

int pos(int a); 


struct cases {
  int x ;
  int y ;
  cases operator +(cases s) {
	  cases c ; c.x = x+s.x ; c.y = y+s.y;
	  return(c);
  }
  cases operator -(cases s) {
	  cases c ; c.x = x-s.x ; c.y = y-s.y;
	  return(c);
  }
  cases operator*(int i){
	  cases c;
	  c.x=i*x ; c.y=y*i;
	  return(c);
  }
  bool operator==(cases s){
    return (x==s.x)&&(s.y==y);
  }
  bool operator!=(cases s){
    return !((x==s.x)&&(s.y==y));
  }
};

void generer_pix(cases tableau[61], int decalage_x, int decalage_y, int debutx, int debut_y); // j'ai juste renommé ta fonction


void generer_co(cases t[61]); // la fonction qui rempli tco

cases pixtoco (cases s, cases tpix[61], cases tco[61]) ; // littéralement pix to co. transforme les pixels en coordonnées

cases cotopix (cases s, cases tpix[61], cases tco[61]) ; // la réciproque



cases souris(cases tpix[61], cases tco[61]); // la souris. on lui donne les pixels, elle rend la position grâce aux tableaux index

int max (int i, int j);

void InitRandom();

int Random(int a, int b);

int couleurop(int a);
