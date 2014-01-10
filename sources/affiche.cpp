#include <iostream>
#include "annexe.h"
#include <Imagine/Graphics.h>
#include "affiche.h"
using namespace Imagine;
using namespace std ;






void affiche_plateau() {
  int W ; int H;
  byte*r ;
  byte*g ;
  byte*b ;

  loadColorImage(srcPath("ppd.jpg"),r,g,b,W,H);
  putColorImage(0,0,r,g,b,W,H) ;
}

void affiche_boules(char c, int i){
    int W ; int H;
  byte*r ;
  byte*g ;
  byte*b ;
};
  
  