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
	//on a trop souvent besoin de passer des pixels aux coordonn�es donc j'ai cr�� deux index pour passer facilement de l'un � l'autre
	cases tpix[61] ;// �a c'est le tableau i->pixels 
	cases tco[61] ; //�a c'est i-> coordonn�es
	
	int score_b=0;
	int score_n=0;
	generer_pix(tpix,48,42,128,30);
	
	generer_co(tco);
	
	
	//cette fonction sert uniquement a verfier que les cases sont rang�es dans le bon ordre, bien plac�es, etc
	
	//for(int i=0; i<61;i++){
	//drawCircle (tpix[i].x,tpix[i].y, 20, RED);
	//milliSleep(10);
	//}
	//milliSleep(100);
	
	plateau p ;
	
	affiche_t(p,tco,tpix);
	
	Coup C(tpix,tco,p);
	if(C.estCorrect(p)==true){
		p.executeCoup(C,score_b,score_n);
	}
	milliSleep(5000);
	affiche_t(p,tco,tpix);

	
	
	click();	
	
	cout<<"done"<<endl;
	
	endGraphics();
	return 0;
}