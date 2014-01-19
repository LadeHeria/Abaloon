
#include <iostream>
#include "annexe.h"
#include <Imagine/Graphics.h>
using namespace Imagine;
using namespace std ;



int dis(cases a, cases b){ // une distance pratique
  return min((b.x-a.x),(b.y-a.y));
}

int dis2(cases a, cases b) {
  return max((b.x-a.x),(b.y-a.y)) ;
}

int pos(int a) {//partie positive
  if (a<0) return 0 ; else a ;
}

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

void generer_co(cases t[61]){ //même algorythme que pour affiche_balles2 - fonctionnel normalement donc
  int j=0; 
  for (int a = -4; a<5; a++){
    for(int k=1+pos(a); (k+abs(a)-pos(a)<10);k++){
	t[j].x=a ; t[j].y=k ;  j++ ;
     } ;
     
   }
}

void generer_pix(cases tableau[61], int decalage_x, int decalage_y, int debutx, int debuty){
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
  
cases pixtoco (cases s, cases tpix[61], cases tco[61]) { //je parcours bêtement le premier tableau jusqu'à trouver l'égalité, donc l'indice, puis j'utilise l'autre tableau
  int j=0;
  for (int i=0; i<61&&(s!=tpix[i]); i++) {
    j++ ;
  };

  return tco[j] ;
}
  
cases cotopix(cases s, cases tpix[61], cases tco[61]) {
   int j=0;
  for (int i=0; i<61&&(s!=tco[i]); i++) {
    j++;
  };
  return tpix[j] ;
}
    


cases souris(cases tpix[61], cases tco[61]){
	int button;
	cases s ; int sw; Window W1 ;
	cases c ;
	c.x=0;
	c.y=0;
	button=anyGetMouse(s.x,s.y,W1,sw);
	int d =std::numeric_limits<int>::max() ;// dis(tpix[0],s); 

	
	cout<<s.x<<" "<<s.y<<endl ;
	
	for (int i=0; i<61;i++) { // je cherche le point le plus proche
	  if(dis(tpix[i],s)>0&&dis2(tpix[i],s)<d) {
	    d = dis2(tpix[i],s) ; c = tpix[i] ; cout<<c.x<<" "<<c.y<<endl ;
	  };		    
	}
	cout<<c.x<<" "<<c.y<<endl ;
	c = pixtoco(c, tpix, tco) ; // j'avais le point en pixels, je le sors en coordonnées
	return c ;
}


  
  
  