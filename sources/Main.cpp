#include "annexe.h"
#include <iostream>
#include <Imagine/Graphics.h>
#include "affiche.h"
#include "plateau.h"
using namespace Imagine;
using namespace std ;

//Abalone
//LISSER Marwan
//DONAT-BOUILLUD Benoit


int main()
{

	

  
	
  
	openWindow(500,500);
	//on a trop souvent besoin de passer des pixels aux coordonnées donc j'ai créé deux index pour passer facilement de l'un à l'autre
	cases tpix[61] ;// ça c'est le tableau i->pixels 
	cases tco[61] ; //ça c'est i-> coordonnées
	
	generer_pix(tpix,48,42,128,30);
	
	generer_co(tco);
	
	
	//cette fonction sert uniquement a verfier que les cases sont rangées dans le bon ordre, bien placées, etc
	
	//for(int i=0; i<61;i++){
	//drawCircle (tpix[i].x,tpix[i].y, 20, RED);
	//milliSleep(10);
	//}
	//milliSleep(100);
	
	plateau p ;
	
	affiche_t(p,tco,tpix);
	
	
	
	
	click();	
	
	cout<<"done"<<endl;
	
	endGraphics();
	return 0;
}