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
	cases tableau[60];
	generer_places(tableau,48,42,128,30);
	//cette fonction sert uniquement a verfier que les cases sont rang�es dans le bon ordre, bien plac�es, etc
	for(int i=0; i<61;i++){
	drawCircle (tableau[i].x,tableau[i].y, 20, RED);
	milliSleep(10);
	}
	milliSleep(100);
	affiche_boules(-4,5, tableau);
	affiche_boules(3,7, tableau);
	
	// cout<<W<<endl;
	
	//cout<<W<<endl;
	click();
	affiche_plateau() ;
	//putColorImage(0,0,r,g,b,W,H) ;

	
	cout<<"done"<<endl;
	
	endGraphics();
	return 0;
}
