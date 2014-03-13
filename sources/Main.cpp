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
////////////////////////////////////////////////////////////ATTENTION///////////////////////////////////////////////////////////////////////////
///////////LES COUT SUR WINDOWS PRENNENT UN TEMPS FOU, ON GAGNE A PEU PRES UN FACTEUR 10000 SUR EN LES DESACTIVANT//////////////////////////////


int main()
{

	

  
	
  
	openWindow(500,500);
	//on a trop souvent besoin de passer des pixels aux coordonn�es donc j'ai cr�� deux index pour passer facilement de l'un � l'autre
	cases tpix[61] ;// �a c'est le tableau i->pixels 
	cases tco[61] ; //�a c'est i-> coordonn�es
	int nbcoups=0;
	generer_pix(tpix,48,42,128,30);
	
	generer_co(tco);
	
	
	InitRandom();
	int score_b=14 ; int score_n=14 ;
	int joueur=1; // le joueur qui doit jouer son prochain coup
	plateau p ;
	affiche_t(p,tco,tpix);
	int a;
	cout<<"tapez "<<endl ;
	cout<<"1 pour l'IA aleatoire contre elle-m�me"<< endl ;
	cout<<"2 pour le jeu a 2"<<endl;
	cout<<"3 pour le jeu contre l'IA al�atoire, 4 pour l'IA1 contre elle meme"<<endl ; 
	cout<<"5 pour defier l'IAborophobe"<<endl ;
	cout<<"6 pour l'IA1 (qui pousse une boule quand elle peut) contre l'IA2 contre-straege"<<endl;
	cout<<"7 pour l'IA qui fuie les bords contre l'IA2 centre-straege"<<endl;
	cin>>a;
	
	if(a==1){ //IA VS IA
	  
	    cases boules[15];
	    p.listeboules(joueur,boules);
	    //cout<<"Les noirs commencent"<<endl;
	  
	    while(score_n!=8&&score_b!=8) { //la d�faite � 8 boules
	    
			Coup coup = Coup(boules,p,joueur); //premi�re g�n�ration de coup al�atoire
			if(coup.estCorrect(p)==1){ //si coup hasard correct
				p.executeCoup(coup, score_b, score_n); //execute
				nbcoups=nbcoups+1;
				//cout<<nbcoups<<endl;
				affiche_t(p,tco,tpix); //mise � jour de l'affichage
				//cout<<"score des noirs : "<<score_n<<endl; //nouveaux scores
				//cout<<"score des blancs : "<<score_b<<endl;
				if(joueur==1){ //changement de joueur "actif
					joueur=2;
					p.listeboules(joueur,boules);
					//cout<<"Aux blancs de jouer"<<endl;

				}
				else{
					joueur=1;
					p.listeboules(joueur,boules);
					//cout<<"Aux noirs de jouer"<<endl;
				}
			}
	      }
	}
	
	
	if(a==3){ //joueur VS IA al�atoire
	    cases boules[15];
	    p.listeboules(joueur,boules);
	    //cout<<"Les noirs commencent"<<endl;
	    while(score_n!=8&&score_b!=8) {
				if(joueur==1){//le joueur humain commence
					Coup coup = Coup(tpix,tco,p,joueur) ;
					if(coup.estCorrect(p)==1){
						p.executeCoup(coup, score_b, score_n);
						affiche_t(p,tco,tpix);
					//cout<<"score des noirs : "<<score_n<<endl;
					//cout<<"score des blancs : "<<score_b<<endl;
					joueur=2;
					p.listeboules(joueur,boules);
					//cout<<"Aux blancs de jouer"<<endl;

					}
					else{
					affiche_t(p,tco,tpix);
					}
				}
				else{//vient � jouer l'IA al�atoire
					Coup coup = Coup(boules,p,joueur);
					if(coup.estCorrect(p)==1){
						p.executeCoup(coup, score_b, score_n);
						affiche_t(p,tco,tpix);
						//cout<<"score des noirs : "<<score_n<<endl;
						//cout<<"score des blancs : "<<score_b<<endl;
					joueur=1;
					p.listeboules(joueur,boules);
					//cout<<"Aux noirs de jouer"<<endl;
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
	    //cout<<"Les noirs commencent"<<endl;
	    while(score_n!=8&&score_b!=8) {
				if(joueur==1){
					Coup coup=IA1(1,boules,p,joueur);
						p.executeCoup(coup, score_b, score_n);
						affiche_t(p,tco,tpix);
					//cout<<"score des noirs : "<<score_n<<endl;
					//cout<<"score des blancs : "<<score_b<<endl;
					joueur=2;
					p.listeboules(joueur,boules);
					//cout<<"Aux blancs de jouer"<<endl;
				}
				else{
					Coup coup=IA1(1,boules,p,joueur);
						p.executeCoup(coup, score_b, score_n);
						affiche_t(p,tco,tpix);
						//cout<<"score des noirs : "<<score_n<<endl;
						//cout<<"score des blancs : "<<score_b<<endl;
					joueur=1;
					p.listeboules(joueur,boules);
					//cout<<"Aux noirs de jouer"<<endl;
					
				}
			
	    }
	}
	
	if(a==5){ // joueur VS IA ++
	    cases boules[15];
	    p.listeboules(joueur,boules);
	     //cout<<"Les noirs commencent"<<endl;
	    while(score_n!=8&&score_b!=8) {//cout<<"got in"<<endl ;
				if(joueur==1){//le joueur humain commence
					Coup coup = Coup(tpix,tco,p,joueur) ;
					if(coup.estCorrect(p)==1){
						p.executeCoup(coup, score_b, score_n);
						affiche_t(p,tco,tpix);
					//cout<<"score des noirs : "<<score_n<<endl;
					//cout<<"score des blancs : "<<score_b<<endl;
					joueur=2;
					p.listeboules(joueur,boules);
					//cout<<"Aux blancs de jouer"<<endl;
					}

				}
				else{	//cout<<"l'IA se lance"<<endl ;
					Coup coup=IAborophobe(1,boules,p,joueur); //cout<<"IA a trouve son coup"<<endl ;
						p.executeCoup(coup, score_b, score_n);
						affiche_t(p,tco,tpix);
						//cout<<"score des noirs : "<<score_n<<endl;
						//cout<<"score des blancs : "<<score_b<<endl;
					joueur=1;
					p.listeboules(joueur,boules);
					//cout<<"Aux noirs de jouer"<<endl;
					
				}
			
	      }
	
	
	}
	
	
	if(a==6){ // IA++ VS IA ++++
		  cases boules[15];
		  p.listeboules(joueur,boules);
		  //cout<<"Les noirs commencent"<<endl;
		  while(score_n!=8&&score_b!=8) {//cout<<"got in"<<endl ;
				if(joueur==1){			
						  Coup coup=IA1(1,boules,p,joueur); //cout<<"IA a trouve son coup"<<endl ;
						p.executeCoup(coup, score_b, score_n);
						affiche_t(p,tco,tpix);
						//cout<<"score des noirs : "<<score_n<<endl;
						//cout<<"score des blancs : "<<score_b<<endl;
						joueur=2;
						p.listeboules(joueur,boules);
						nbcoups=nbcoups+1;
						  //cout<<"Aux noirs de jouer"<<endl;
				}
				else{	//cout<<"l'IA se lance"<<endl ;
					Coup coup=IA2(1,boules,p,joueur); //cout<<"IA a trouve son coup"<<endl ;
						p.executeCoup(coup, score_b, score_n);
						affiche_t(p,tco,tpix);
						//cout<<"score des noirs : "<<score_n<<endl;
						//cout<<"score des blancs : "<<score_b<<endl;
					joueur=1;
					p.listeboules(joueur,boules);
					//cout<<"Aux noirs de jouer"<<endl;
					
				}
			
		  }
	
	
	}
	
	
	if(a==7){ // IAborophobe VS IA ++++
		  cases boules[15];
		  p.listeboules(joueur,boules);
		  //cout<<"Les noirs commencent"<<endl;
		  while(score_n!=8&&score_b!=8) {//cout<<"got in"<<endl ;
				if(joueur==1){			
						  Coup coup=IAborophobe(1,boules,p,joueur); //cout<<"IA a trouve son coup"<<endl ;
						p.executeCoup(coup, score_b, score_n);
						affiche_t(p,tco,tpix);
						//cout<<"score des noirs : "<<score_n<<endl;
						//cout<<"score des blancs : "<<score_b<<endl;
						joueur=2;
						p.listeboules(joueur,boules);
						nbcoups=nbcoups+1;
						  //cout<<"Aux noirs de jouer"<<endl;
				}
				else{	//cout<<"l'IA se lance"<<endl ;
					Coup coup=IA2(1,boules,p,joueur); //cout<<"IA a trouve son coup"<<endl ;
						p.executeCoup(coup, score_b, score_n);
						affiche_t(p,tco,tpix);
						//cout<<"score des noirs : "<<score_n<<endl;
						//cout<<"score des blancs : "<<score_b<<endl;
					joueur=1;
					p.listeboules(joueur,boules);
					//cout<<"Aux noirs de jouer"<<endl;
					
				}
			
		  }
	
	
	}
	
	else{// joueur contre joueur

	      //cout<<"Les noirs commencent"<<endl;
	      while(score_n!=8&&score_b!=8) {
			Coup coup = Coup(tpix,tco,p,joueur) ; //cout<<"la couleur est "<<coup.couleur<<endl;
			
			  if(coup.estCorrect(p)==1){
				p.executeCoup(coup, score_b, score_n);
				affiche_t(p,tco,tpix);
				//cout<<"score des noirs : "<<score_n<<endl;
				 //cout<<"score des blancs : "<<score_b<<endl;
				if(joueur==1){
				    joueur=2;
				    //cout<<"Aux blancs de jouer"<<endl;

				}
				else{
				    joueur=1;
				    //cout<<"Aux noirs de jouer"<<endl;
				}
			  }
			  else{
				    affiche_t(p,tco,tpix);
			  }
	      }
	
	
	
	}
	
	cout<<"score des noirs : "<<score_n<<endl;
	cout<<"score des blancs : "<<score_b<<endl;
	cout<<"nombre de coups joues :"<<nbcoups<<endl;
	
	
	
	
	
	
	click();	
	
	//cout<<"done"<<endl;
	  
	
	

	
	endGraphics();
	return 0;

}