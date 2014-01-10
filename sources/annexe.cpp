
#include <iostream>
//#include "annexe.h"
#include <Imagine/Graphics.h>
using namespace Imagine;
using namespace std ;

int min (int i, int j) {
  if (i<j) {return i;} 
  else {return j;}
}

void inject (int taille,int taille1,byte*t,byte*t1) {
  for (int i=0; i<(min(taille,taille1)*min(taille,taille1)); i++) {
    t1[i]=t[i];
  }
}

void inject2 (int W,int taille1,byte*t,byte*t1) {
  for (int j=0; j<taille1;j++) {
    for (int i=0; i<taille1;i++) {
      t1[i+W*j]=t1[i+W*j];
    };
  };
}




    
    
  
  
  