#include <iostream>
#include "annexe.h"
#include <Imagine/Graphics.h>
#include "affiche.h"
#include <cmath>
#include "plateau.h"
using namespace Imagine;
using namespace std ;



Color couleur(int i){
	if(i==0){return RED;} ;
	if(i==1){return BLACK;}
	if(i==2) {return GREEN;}
}




void affiche_plateau() {
  int W ; int H;
  byte*r ;
  byte*g ;
  byte*b ;

  loadColorImage(srcPath("ppd.jpg"),r,g,b,W,H);
  putColorImage(0,0,r,g,b,W,H) ;
}

//il faudra surement ajouter un parametre qui donne la couleur de la boule qu'on affiche
void affiche_boules(int c, int i, cases tableau[61]){
    int W ; int H;
  byte*r ;
  byte*g ;
  byte*b ;
  if(c==-4&&i<6&&i>0){
  //afficher ici l'image à la bonne place, pour le moment on trace un cercle
	  drawCircle (tableau[i-1].x,tableau[i-1].y, 20, BLUE);
  }
  if(c==-3&&i<7&&i>0){
  //afficher ici l'image à la bonne place, pour le moment on trace un cercle
	  drawCircle (tableau[5+i-1].x,tableau[5+i-1].y, 20, BLUE);
  }
  if(c==-2&&i<8&&i>0){
  //afficher ici l'image à la bonne place, pour le moment on trace un cercle
	  drawCircle (tableau[11+i-1].x,tableau[11+i-1].y, 20, BLUE);
  }
  if(c==-1&&i<9&&i>0){
  //afficher ici l'image à la bonne place, pour le moment on trace un cercle
	  drawCircle (tableau[18+i-1].x,tableau[18+i-1].y, 20, BLUE);
  }
  if(c==0&&i<10&&i>0){
  //afficher ici l'image à la bonne place, pour le moment on trace un cercle
	  drawCircle (tableau[26+i-1].x,tableau[26+i-1].y, 20, BLUE);
  }
  if(c==1&&i<10&&i>1){
  //afficher ici l'image à la bonne place, pour le moment on trace un cercle
	  drawCircle (tableau[35+i-1-1].x,tableau[35+i-1-1].y, 20, BLUE);
  }
  if(c==2&&i<10&&i>2){
  //afficher ici l'image à la bonne place, pour le moment on trace un cercle
	  drawCircle (tableau[43+i-1-2].x,tableau[43+i-1-2].y, 20, BLUE);
  }
  if(c==3&&i<10&&i>3){
  //afficher ici l'image à la bonne place, pour le moment on trace un cercle
	  drawCircle (tableau[50+i-1-3].x,tableau[50+i-1-3].y, 20, BLUE);
  }
  if(c==4&&i<10&&i>4){
  //afficher ici l'image à la bonne place, pour le moment on trace un cercle
	  drawCircle (tableau[56+i-1-4].x,tableau[56+i-1-4].y, 20, BLUE);
  }

};


void affiche_boules2(int c, int i, cases t[61]){ //version "automatisée" toujours un peu dégue, mais l'algorithme de parcours est le même que generer_co
    int W ; int H;
  byte*r ;
  byte*g ;
  byte*b ;
  
  int d=0; int v=0 ;
  for (int a = -4; a<5&&(v==0); a++){
    for(int k=1+pos(a); (k+abs(a)-pos(a)<10)&&(v==0);k++){
      //cout<<a<<" "<<k<<" "<<j<<endl;
      if ((a==c)&&(k==i)){
	drawCircle(t[d].x,t[d].y,20,BLUE) ; v=1 ; 
      } ;
      d++ ;
    }
  }  
}

void affiche_boule3(cases s, cases tpix[61], cases tco[61],Color co){ //censée ramener la case en pixels...
  cases c ; 
  c = cotopix(s, tpix, tco) ; 
  drawCircle(c.x,c.y,20,co) ;
}
  
 
void affiche_t(plateau p,cases tco[61], cases tpix[61]){
  for(int i=0;i<61;i++){
    affiche_boule3(tco[i], tpix, tco, couleur(p.get(tco[i]))) ; cout<<i+1<<" "<<(p.get(tco[i]))<<endl;
  }
}


  