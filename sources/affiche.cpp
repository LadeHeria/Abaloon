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

//il faudra surement ajouter un parametre qui donne la couleur de la boule qu'on affiche
void affiche_boules(int c, int i, cases tableau[60]){
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
  if(c==1&&i<9&&i>0){
  //afficher ici l'image à la bonne place, pour le moment on trace un cercle
	  drawCircle (tableau[35+i-1].x,tableau[35+i-1].y, 20, BLUE);
  }
  if(c==2&&i<8&&i>0){
  //afficher ici l'image à la bonne place, pour le moment on trace un cercle
	  drawCircle (tableau[43+i-1].x,tableau[43+i-1].y, 20, BLUE);
  }
  if(c==3&&i<7&&i>0){
  //afficher ici l'image à la bonne place, pour le moment on trace un cercle
	  drawCircle (tableau[50+i-1].x,tableau[50+i-1].y, 20, BLUE);
  }
  if(c==4&&i<6&&i>0){
  //afficher ici l'image à la bonne place, pour le moment on trace un cercle
	  drawCircle (tableau[56+i-1].x,tableau[56+i-1].y, 20, BLUE);
  }

};

void generer_places(cases tableau[60], int decalage_x, int decalage_y, int debutx, int debuty){
	//on place le premier pion de chaque ligne puis on place les pions dessus
	//ligne 1
	tableau[60].x=debutx+4*decalage_x;
	tableau[60].y=debuty;
	for(int i=1; i<5; i++){
		tableau[60-i].x=tableau[60].x-i*decalage_x;
		tableau[60-i].y=tableau[60].y;
	}
	//ligne 2
	tableau[55].x=debutx-decalage_x/2+5*decalage_x;
	tableau[55].y=debuty+decalage_y;
	for(int i=1; i<6; i++){
		tableau[55-i].x=tableau[55].x-i*decalage_x;
		tableau[55-i].y=tableau[55].y;
	}
	//ligne 3
	tableau[49].x=debutx+5*decalage_x;
	tableau[49].y=debuty+2*decalage_y;
	for(int i=1; i<7; i++){
		tableau[49-i].x=tableau[49].x-i*decalage_x;
		tableau[49-i].y=tableau[49].y;
	}
	//ligne 4
	tableau[42].x=debutx-decalage_x-decalage_x/2+7*decalage_x;
	tableau[42].y=debuty+3*decalage_y;
	for(int i=1; i<8; i++){
		tableau[42-i].x=tableau[42].x-i*decalage_x;
		tableau[42-i].y=tableau[42].y;
	}
	//ligne 5
	tableau[34].x=debutx+6*decalage_x;
	tableau[34].y=debuty+4*decalage_y;
	for(int i=1; i<9; i++){
		tableau[34-i].x=tableau[34].x-i*decalage_x;
		tableau[34-i].y=tableau[34].y;
	}
	//on symetrise les ligne par rapport à la premiere
	//ligne 6
	for(int i=0; i<8; i++){
		tableau[25-i].x=tableau[42-i].x;
		tableau[25-i].y=tableau[42-i].y+2*decalage_y;
	}
	//ligne 7
	for(int i=0; i<7; i++){
		tableau[17-i].x=tableau[49-i].x;
		tableau[17-i].y=tableau[49-i].y+4*decalage_y;
	}
	//ligne 8
	for(int i=0; i<6; i++){
		tableau[10-i].x=tableau[55-i].x;
		tableau[10-i].y=tableau[55-i].y+6*decalage_y;
	}
	//ligne 9
	for(int i=0; i<5; i++){
		tableau[4-i].x=tableau[60-i].x;
		tableau[4-i].y=tableau[60-i].y+8*decalage_y;
	}
}
  
  