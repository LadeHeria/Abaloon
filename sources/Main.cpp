#include "annexe.h"
#include <iostream>
#include <Imagine/Graphics.h>
#include "affiche.h"
using namespace Imagine;
using namespace std ;

//Abalone
//LISSER Marwan
//DONAT-BOUILLUD Benoit
//commit + test


int main()
{

	

  
	
  
	openWindow(500,500);
	
	// cout<<W<<endl;
	
	//cout<<W<<endl;
	click();
	affiche_plateau() ;
	//putColorImage(0,0,r,g,b,W,H) ;
	cases tableau[60];
	generer_places(tableau,48,42,128,30);

	
	cout<<"done"<<endl;
	
	endGraphics();
	return 0;
}
