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
	
	generer_pix(tpix,48,42,128,30);
	
	generer_co(tco);
	
	
	//cette fonction sert uniquement a verfier que les cases sont rang�es dans le bon ordre, bien plac�es, etc
	
	//for(int i=0; i<61;i++){
	//drawCircle (tpix[i].x,tpix[i].y, 20, RED);
	//milliSleep(10);
	//}
	//milliSleep(100);
	
	int score_b=14 ; int score_n=14 ;
	int joueur=1;
	
	plateau p ;
	
	affiche_t(p,tco,tpix);
	cout<<"Les noirs commencent"<<endl;
	while(true||score_n!=8||score_b!=8) {
			Coup coup = Coup(tpix,tco,p,joueur) ;
			if(coup.estCorrect(p)==1){
				p.executeCoup(coup, score_b, score_n);
				affiche_t(p,tco,tpix);
			cout<<"score des noirs : "<<score_n<<endl;
			cout<<"score des blancs : "<<score_b<<endl;
			if(joueur==1){
				joueur=2;
				cout<<"Aux blancs de jouer"<<endl;

			}
			else{
			joueur=1;
			cout<<"Aux noirs de jouer"<<endl;
			}
			}
			else{
			affiche_t(p,tco,tpix);
			}
	}

	
	
	affiche_t(p,tco,tpix);
	
	
	
	
	click();	
	
	cout<<"done"<<endl;
	
	endGraphics();
	return 0;
}