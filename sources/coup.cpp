#include "plateau.h"
#include "coup.h"
#include "annexe.h"
#include <stack>
#include <cmath>
using namespace std ;

cases min(cases a, cases b){ 
  if (abs(a.x)+abs(a.y)<abs(b.x)+abs(b.y)) return a ;
  else return b ;
}




  

Coup::Coup(cases tpix[61],cases tco[61]) { //r�gle : direction � partir de la derni�re boule cliqu�e (sur une boule adjacente)
  cases c = souris(tpix,tco); //premi�re case
  b_bouges[0]=c; couleur = plateau.get(c,tco[61]); //je rentre la premi�re boule, je prends la couleur du groupe � d�placer
  c = souris(tpix,tco);//case suivante cliqu�e
  for (int i=0; (i<2)&&(plateau.get(c,tco[61])==couleur); i++) {b_bouges[i+1]=c ;  c = souris(tpix,tco); size = i+1 ;}//tant qu'on clique de la m�me couleur je rentre dans le tableau (jusqu'� deux)
  dboules = b_bouges[1]-b_bouges[0] ;//on donne la direction du groupe
  dmove = c-b_bouges[size-1];//la direction du d�placement
  while (get(c,tco[61])==(couleur%2 +1)) {sumito.push(c) ; c = c+dmove ; }//tant que de l'autre couleur dans la direction du mouvement, on ajoute (attention foireux quand �a sort du plateau
   
}


int Coup::estCorrect(plateau p){ //remplir le sumito
	int nb_couleur_c=0;
	//je suis oblig� de d�piler plusieurs fois dans la fonction pour tester les cases si on n'avance pas dans la direction du groupe,
	//donc je pense qu'une pile n'est pas la bonne structure, j'ai consid�r� que c'�tait un tableau de 3 cases, il faudrait trouver une notation 
	//pour lorsqu'on ne selectionne que deux elements (pour le troisieme) OU noter dans coup le nombre d'elements sous la forme int size <--MIEUX
//normalement on peut faire des �galit�s de cases, multiplication par un scalaire
	if((dboules==dmove))||(dboules==(-1)*dmove)){
		//on regarde ce qu'il y a dans cette direction 
		//et on construit le sumito
		if(dboules==.dmove){
					//si la casse est vide, on avance
			//si on veut autoriser le suicide, c'est ici
			if((plateau.get(i[size-1]+dmove,tco)==0){
			return(1);
			}
			for(int j=1;j<size+1;j++){
				if(plateau.get(i[size-1],tco)==plateau.get(i[size-1]+j*dmove,tco){ //si une boule on a la m�me couleur que le groupe, pas correct
					return(0);
				}
				else if((nb_couleur_op<size)&&(j<size)){
					return(1);
				}
				else if(plateau.get(i[size-1]+j*dmove,tco)+plateau.get(i[size-1],tco)==3){
					nb_couleur_c=0;
				}
			}
		}


	}
	else{
		//il faut aussi verifier qu'on ne sort pas du plateau
		for(int k=0;k<coup.size,k++){
			if(plateau.get(coup.i[k]+coup.dmove,tco)!=0){
			return(0);
			}
			else{
			return(1);
			}
		}
	}
}

 //idem en C
{
    //d�piler le sumito + sortir ce qui doit sortir
    //d�piler i 
}



