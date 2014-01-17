#include "annexe.h"
#include <iostream>
#include <Imagine/Graphics.h>
#include "affiche.h"
using namespace Imagine;
using namespace std ;

//Abalone
//LISSER Marwan
//DONAT-BOUILLUD Benoit


int main()
{

	

  
	
  
	openWindow(500,500);
	//on a trop souvent besoin de passer des pixels aux coordonn�es donc j'ai cr�� deux index pour passer facilement de l'un � l'autre
	cases tpix[61] ;// �a c'est le tableau i->pixels 
	cases tco[61] ; //�a c'est i-> coordonn�es
	
	generer_pix(tpix,48,42,128,30);
	generer_co(tco);
	
	
	//cette fonction sert uniquement a verfier que les cases sont rang�es dans le bon ordre, bien plac�es, etc
	for(int i=0; i<61;i++){
	drawCircle (tpix[i].x,tpix[i].y, 20, RED);
	milliSleep(10);
	}
	milliSleep(100);
	
	
	affiche_boules2(H,7, tpix);
	
	//affiche_boule3({E,2}, tpix,tco); 
	
	cases c;
	while (true) {// pour tester souris. Clique sur un cercle, il le met en bleu.
	
	c = souris(tpix,tco);
	cout<<c.x<<" "<<c.y<<endl ;
	affiche_boule3(c, tpix, tco) ;
	};
	// cout<<W<<endl;
	
	//cout<<W<<endl;
	click();
	affiche_plateau() ;
	//putColorImage(0,0,r,g,b,W,H) ;

	
	cout<<"done"<<endl;
	
	endGraphics();
	return 0;
}