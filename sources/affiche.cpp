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

void generer_places(cases tableau[60], int decalage_x, int decalage_y, int debutx, int debuty){
	//on place le premier pion de chaque ligne puis on place les pions dessus
	//ligne 1
	tableau[60].x=debutx;
	tableau[60].y=debuty;
	for(int i=1; i<5; i++){
		tableau[60-i].x=debutx+i*decalage_x;
		tableau[60-i].y=tableau[60].y;
	}
	//ligne 2
	tableau[55].x=debutx-decalage_x/2;
	tableau[55].y=debuty+decalage_y;
	for(int i=1; i<6; i++){
		tableau[55-i].x=tableau[55].x+i*decalage_x;
		tableau[55-i].y=tableau[55].y;
	}
	//ligne 3
	tableau[49].x=debutx-decalage_x;
	tableau[49].y=debuty+2*decalage_y;
	for(int i=1; i<7; i++){
		tableau[49-i].x=tableau[49].x+i*decalage_x;
		tableau[49-i].y=tableau[49].y;
	}
	//ligne 4
	tableau[42].x=debutx-decalage_x-decalage_x/2;
	tableau[42].y=debuty+3*decalage_y;
	for(int i=1; i<8; i++){
		tableau[42-i].x=tableau[42].x+i*decalage_x;
		tableau[42-i].y=tableau[42].y;
	}
	//ligne 5
	tableau[34].x=debutx-2*decalage_x;
	tableau[34].y=debuty+4*decalage_y;
	for(int i=1; i<9; i++){
		tableau[34-i].x=tableau[34].x+i*decalage_x;
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
  
  