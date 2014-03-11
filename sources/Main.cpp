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

//COMMIT !


int main()
{

	

  
	
  
	openWindow(500,500);
	//on a trop souvent besoin de passer des pixels aux coordonn�es donc j'ai cr�� deux index pour passer facilement de l'un � l'autre
	cases tpix[61] ;// �a c'est le tableau i->pixels 
	cases tco[61] ; //�a c'est i-> coordonn�es
	int nbcoups=0;
	generer_pix(tpix,48,42,128,30);
	
	generer_co(tco);
	
	
	//cette fonction sert uniquement a verfier que les cases sont rang�es dans le bon ordre, bien plac�es, etc
	
	//for(int i=0; i<61;i++){
	//drawCircle (tpix[i].x,tpix[i].y, 20, RED);
	//milliSleep(10);
	//}
	//milliSleep(100);
	
	
	InitRandom();
	int score_b=14 ; int score_n=14 ;
	int joueur=1; // le joueur qui doit jouer son prochain coup
	plateau p ;
	affiche_t(p,tco,tpix);
	int a;
	cout<<"tapez 1 pour l'IA, 2 pour le jeu a 2, 3 pour le jeu contre l'IA, 4 pour l'IA amelioree, 5 pour defier l'IA amelioree, 6 pour l'IA encore + fut�e"<<endl;
	cin>>a;
	
	
	if(a==1){ //IA VS IA
	  
	  cases boules[15];
	  p.listeboules(joueur,boules);
	  cout<<"Les noirs commencent"<<endl;
	  while(score_n!=8&&score_b!=8) { //la d�faite � 8 boules
			Coup coup = Coup(boules,p,joueur); //premi�re g�n�ration de coup al�atoire
			if(coup.estCorrect(p)==1){ //si coup hasard correct
				p.executeCoup(coup, score_b, score_n); //execute
				nbcoups=nbcoups+1;
				cout<<nbcoups<<endl;
				affiche_t(p,tco,tpix); //mise � jour de l'affichage
				cout<<"score des noirs : "<<score_n<<endl; //nouveaux scores
				cout<<"score des blancs : "<<score_b<<endl;
				if(joueur==1){ //changement de joueur "actif
					joueur=2;
					p.listeboules(joueur,boules);
					cout<<"Aux blancs de jouer"<<endl;

							}
				else{
					joueur=1;
					p.listeboules(joueur,boules);
					cout<<"Aux noirs de jouer"<<endl;
					}
			}
	 }
	}
	
	
	if(a==3){ //joueur VS IA
	cases boules[15];
	p.listeboules(joueur,boules);
	cout<<"Les noirs commencent"<<endl;
	while(score_n!=8&&score_b!=8) {
				if(joueur==1){//le joueur humain commence
					Coup coup = Coup(tpix,tco,p,joueur) ;
					if(coup.estCorrect(p)==1){
						p.executeCoup(coup, score_b, score_n);
						affiche_t(p,tco,tpix);
					cout<<"score des noirs : "<<score_n<<endl;
					cout<<"score des blancs : "<<score_b<<endl;
					joueur=2;
					p.listeboules(joueur,boules);
					cout<<"Aux blancs de jouer"<<endl;

							}
					else{
					affiche_t(p,tco,tpix);
					}
				}
				else{//vient � jouer l'IA
					Coup coup = Coup(boules,p,joueur);
					if(coup.estCorrect(p)==1){
						p.executeCoup(coup, score_b, score_n);
						affiche_t(p,tco,tpix);
						cout<<"score des noirs : "<<score_n<<endl;
						cout<<"score des blancs : "<<score_b<<endl;
					joueur=1;
					p.listeboules(joueur,boules);
					cout<<"Aux noirs de jouer"<<endl;
					}
					else{
						affiche_t(p,tco,tpix);
					}
			}
			
	}
	}

	if(a==4){ // IA ++
	cases boules[15];
	p.listeboules(joueur,boules);
	cout<<"Les noirs commencent"<<endl;
	while(score_n!=8&&score_b!=8) {
				if(joueur==1){
					Coup coup=IA1(1,boules,p,joueur);
						p.executeCoup(coup, score_b, score_n);
						affiche_t(p,tco,tpix);
					cout<<"score des noirs : "<<score_n<<endl;
					cout<<"score des blancs : "<<score_b<<endl;
					joueur=2;
					p.listeboules(joueur,boules);
					cout<<"Aux blancs de jouer"<<endl;
				}
				else{
					Coup coup=IA1(1,boules,p,joueur);
						p.executeCoup(coup, score_b, score_n);
						affiche_t(p,tco,tpix);
						cout<<"score des noirs : "<<score_n<<endl;
						cout<<"score des blancs : "<<score_b<<endl;
					joueur=1;
					p.listeboules(joueur,boules);
					cout<<"Aux noirs de jouer"<<endl;
					
			}
			
	}
	}
	
	if(a==5){ // joueur VS IA ++
	cases boules[15];
	p.listeboules(joueur,boules);
	cout<<"Les noirs commencent"<<endl;
	while(score_n!=8&&score_b!=8) {cout<<"got in"<<endl ;
				if(joueur==1){//le joueur humain commence
					Coup coup = Coup(tpix,tco,p,joueur) ;
					if(coup.estCorrect(p)==1){
						p.executeCoup(coup, score_b, score_n);
						affiche_t(p,tco,tpix);
					cout<<"score des noirs : "<<score_n<<endl;
					cout<<"score des blancs : "<<score_b<<endl;
					joueur=2;
					p.listeboules(joueur,boules);
					cout<<"Aux blancs de jouer"<<endl;
					}

				}
				else{	cout<<"l'IA se lance"<<endl ;
					Coup coup=IA1(1,boules,p,joueur); cout<<"IA a trouve son coup"<<endl ;
						p.executeCoup(coup, score_b, score_n);
						affiche_t(p,tco,tpix);
						cout<<"score des noirs : "<<score_n<<endl;
						cout<<"score des blancs : "<<score_b<<endl;
					joueur=1;
					p.listeboules(joueur,boules);
					cout<<"Aux noirs de jouer"<<endl;
					
				}
			
	      }
	
	
	}
	
	
	if(a==6){ // joueur VS IA ++++
	cases boules[15];
	p.listeboules(joueur,boules);
	cout<<"Les noirs commencent"<<endl;
	while(score_n!=8&&score_b!=8) {cout<<"got in"<<endl ;
	if(joueur==1){			
	Coup coup=IA1(1,boules,p,joueur); cout<<"IA a trouve son coup"<<endl ;
						p.executeCoup(coup, score_b, score_n);
						affiche_t(p,tco,tpix);
						cout<<"score des noirs : "<<score_n<<endl;
						cout<<"score des blancs : "<<score_b<<endl;
						joueur=2;
					p.listeboules(joueur,boules);
					cout<<"Aux noirs de jouer"<<endl;
	}
				else{	cout<<"l'IA se lance"<<endl ;
					Coup coup=IA2(1,boules,p,joueur); cout<<"IA a trouve son coup"<<endl ;
						p.executeCoup(coup, score_b, score_n);
						affiche_t(p,tco,tpix);
						cout<<"score des noirs : "<<score_n<<endl;
						cout<<"score des blancs : "<<score_b<<endl;
					joueur=1;
					p.listeboules(joueur,boules);
					cout<<"Aux noirs de jouer"<<endl;
					
				}
			
	      }
	
	
	}
	
	else{// joueur contre joueur

	cout<<"Les noirs commencent"<<endl;
	while(true||score_n!=8||score_b!=8) { //WUT ?
			Coup coup = Coup(tpix,tco,p,joueur) ; cout<<"la couleur est "<<coup.couleur<<endl;
			
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
	}
	
	endGraphics();
	return 0;

}