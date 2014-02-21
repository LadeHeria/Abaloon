#include "plateau.h"
#include "coup.h"
#include "annexe.h"
#include "affiche.h"
#include <stack>
#include <cmath>
using namespace std ;

cases min(cases a, cases b){ 
  if (abs(a.x)+abs(a.y)<abs(b.x)+abs(b.y)) return a ;
  else return b ;
}




  

Coup::Coup(cases tpix[61],cases tco[61], plateau p) { //r�gle : direction � partir de la derni�re boule cliqu�e (sur une boule adjacente)
  cases c = souris(tpix,tco); //premi�re case
  b_bouges[0]=c; int couleur = p.get(c);
  affiche_boule3(b_bouges[0],tpix,tco,BLUE);//je rentre la premi�re boule, je prends la couleur du groupe � d�placer
  c = souris(tpix,tco);//case suivante cliqu�e
  for (int i=0; (i<2)&&(p.get(c)==couleur); i++) {b_bouges[i+1]=c ;  c = souris(tpix,tco); size = i+1 ; affiche_boule3(c,tpix,tco,BLUE);}//tant qu'on clique de la m�me couleur je rentre dans le tableau (jusqu'� deux)
  dboules = b_bouges[1]-b_bouges[0] ;//on donne la direction du groupe
  dmove = c-b_bouges[size-1];//la direction du d�placement
  while (p.get(c)==(couleur%2 +1)) {sumito.push(c) ; c = c+dmove ;
  affiche_boule3(b_bouges[0],tpix,tco,BLUE);}//tant que de l'autre couleur dans la direction du mouvement, on ajoute (attention foireux quand �a sort du plateau
   
}


bool Coup::estCorrect(plateau p){ //remplir le sumito
	cout<<"lancement de est correct";
	int nb_couleur_c=0;
	//je suis oblig� de d�piler plusieurs fois dans la fonction pour tester les cases si on n'avance pas dans la direction du groupe,
	//donc je pense qu'une pile n'est pas la bonne structure, j'ai consid�r� que c'�tait un tableau de 3 cases, il faudrait trouver une notation 
	//pour lorsqu'on ne selectionne que deux elements (pour le troisieme) OU noter dans coup le nombre d'elements sous la forme int size <--MIEUX
//normalement on peut faire des �galit�s de cases, multiplication par un scalaire
	if((dboules==dmove)||(dboules==dmove*(-1))){
		//on regarde ce qu'il y a dans cette direction 
		//et on construit le sumito
		if(dboules==dmove){
					//si la casse est vide, on avance
			//si on veut autoriser le suicide, c'est ici
			for(int j=0;j<size+1;j++){
				if(abs((b_bouges[size-1]+dmove*j).x)+(b_bouges[size-1]+dmove*j).y>=10){return(1);}
				if(p.get(b_bouges[size-1]+dmove*j)==0){
					cout<<"est correct";
					return(1); //si case vide, correct
				}
				if(couleur==p.get(b_bouges[size-1]+dmove*j)){ //si une boule on a la m�me couleur que le groupe, pas correct
					cout<<"est pas correct";
					return(0);
				}
				
			}
			cout<<"est pas correct";
			return(0);
		}
		if(dboules==dmove*(-1)){
						//si la casse est vide, on avance
			//si on veut autoriser le suicide, c'est ici
			for(int j=0;j<size+1;j++){
				if(p.get(b_bouges[size-1]+dmove)==0){
					cout<<"est correct";
					return(1); //si case vide, correct
				}
				if(couleur==p.get(b_bouges[size-1]+dmove*(-j))){ //si une boule on a la m�me couleur que le groupe, pas correct
					cout<<"est pas correct";
					return(0);
				}
				
			}
			cout<<"est pas correct";
			return(0);
		}

	}


	else{
		//il faut aussi verifier qu'on ne sort pas du plateau
		for(int k=0;k<size;k++){
			if(p.get(b_bouges[k]+dmove)!=0){
			cout<<"est pas correct";
			return(0);
			}
			else{
			cout<<"est correct";
			return(1);
			}
		}
	}
}

 //idem en C

    //d�piler le sumito + sortir ce qui doit sortir
    //d�piler i 



