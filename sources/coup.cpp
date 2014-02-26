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


// Il faudra penser à modifier un peu coup à la fin pour que si l'utilisateur fait un coup impossible,
// plutot que de devoir resélectionner juste sa dernière boule ou dernière direction (comme c'est le cas maintenant),
// il doive refaire tout son coup. En effet dans le cas présent, si l'utilisateur se trompe, il sera coincé dans une boucle
//  (par exemple impossible de déplacer une seule boule si par erreur t'as cliqué sur une autre boule trop lointaine)

  

Coup::Coup(cases tpix[61],cases tco[61], plateau p, int joueur) { //règle : direction à partir de la dernière boule cliquée (sur une boule adjacente)
	
	int couleur=0;
	
	cases c;
	
	while(couleur!=joueur){//ici on attend que l'utilisateur sélectionne une boule: les cases vides, on prend pas
		cout<<"clique une case occupee margoulin"<<endl ;
		c = souris(tpix,tco);
		cout<<c.x<<" "<<c.y<<endl; //première case
		b_bouges[0]=c; // got in
		couleur = p.get(c); //maj de la couleur
		//je rentre la première boule, je prends la couleur du groupe à déplacer
		size=1; 
	}
	affiche_boule3(c, tpix, tco,BLUE) ; //affiche en bleue la boule finalement sélectionnée
	//il faut vérifier que les boules selectionnées sont contigues
	
	dboules.x=0;
	dboules.y=0;
	
	c = souris(tpix,tco); //la boule suivante, ou peut-être la case vide vers laquelle la boule seule se dirige
	
	if (p.get(c)==couleur){ //si cette boule est de la même couleur... 
	  
	    while(max(abs(dboules.x),abs(dboules.y))!=1){//on y rentres au premier coup, puis : tant que t'as cliqué trop loin...
		cout<<"un clique adjacent stp"<<endl ;
		dboules = c-b_bouges[0] ;//on donne la direction du groupe
		cout<<"dboules "<<dboules.x<<" "<<dboules.y<<endl ;
		affiche_boule3(c, tpix, tco,BLUE) ; //colore la nouvelle boule sélectionnée
		b_bouges[1]=c ; 
		size=2;
		
		c = souris(tpix,tco); //nouvel essai s'il le faut ; autrement ce sera la case-vide-destination ou la boule suivante
	    }
	}
	
	if (p.get(c)==couleur){ //si cette boule est aussi de la même couleur... 
	    while(dboules != (c-b_bouges[1])){//on y rentres au premier coup, puis : tant que t'as cliqué trop loin...
		cout<<"WUT ?"<<endl ;
		c = souris(tpix,tco);//nouvel essai
		b_bouges[1]=c ; 
		size=2;
		
		 
	    }
	    b_bouges[2]=c ; 
	      affiche_boule3(c, tpix, tco,BLUE) ;
		size=3;
	c = souris(tpix,tco);//case destination
	}
	
	

  cout<<c.x<<" "<<c.y<<endl ;//case suivante cliquée
  
	
  dmove = c-b_bouges[size-1]; 
  cout<<"("<<c.x<<","<<c.y<<") - "<<"("<<b_bouges[size-1].x<<","<<b_bouges[size-1].y<<") ="<<"dmove "<<dmove.x<<" "<<dmove.y<<endl;//la direction du déplacement cout<<"dmove "<<dmove<<endl;
  cout<<"taille :"<<size<<endl;
  while (p.get(c)==(couleur%2 +1)) {
	  sumito.push(c) ; c = c+dmove ; }//tant que de l'autre couleur dans la direction du mouvement, on ajoute (attention foireux quand ça sort du plateau
   
}


bool Coup::estCorrect(plateau p){ //remplir le sumito
	//je suis obligé de dépiler plusieurs fois dans la fonction pour tester les cases si on n'avance pas dans la direction du groupe,
	//donc je pense qu'une pile n'est pas la bonne structure, j'ai considéré que c'était un tableau de 3 cases, il faudrait trouver une notation 
	//pour lorsqu'on ne selectionne que deux elements (pour le troisieme) OU noter dans coup le nombre d'elements sous la forme int size <--MIEUX
//normalement on peut faire des égalités de cases, multiplication par un scalaire
	if(max(abs(dmove.x),abs(dmove.y))!=1){
		cout<<"est pas correct (dmove trop grand)"<<endl ;
					return(0);
	}
	if((dboules==dmove)||(dboules==dmove*(-1))){
		//on regarde ce qu'il y a dans cette direction 
		//et on construit le sumito
		if(dboules==dmove){
					//si la casse est vide, on avance
			//si on veut autoriser le suicide, c'est ici
			for(int j=1;j<size+1;j++){
				if((p.get(b_bouges[size-1]+dmove*(j-1))==couleur)&&(abs((b_bouges[size-1]+dmove*j).x)+(b_bouges[size-1]+dmove*j).y-pos((b_bouges[size-1]+dmove*j).x)>=10) || (abs((b_bouges[size-1]+dmove*j).x)+(b_bouges[size-1]+dmove*j).y-pos((b_bouges[size-1]+dmove*j).x))<=0 || abs((b_bouges[size-1]+dmove*j).x)>4 || (b_bouges[size-1]+dmove*j).y<0){
					cout<<"est pas correct (on se suicide pas)"<<endl ;
					return(0);
				}
				if(p.get(b_bouges[size-1]+dmove*j)==0){
					cout<<"est correct";
					return(1); //si case vide, correct
				}
				if(couleur==p.get(b_bouges[size-1]+dmove*j)){ //si une boule on a la même couleur que le groupe, pas correct
					cout<<"est pas correct (boule de meme couleur dans le sumito)"<<endl ;
					return(0);
				}
				if(p.get(b_bouges[size-1]+dmove*j)==3){
					cout<<"est  correct (bien joue, vous poussez hors du plateau) bon sens"<<endl ;
					return(1);
				}
			}
			cout<<"est pas correct (je sais plus pourquoi)"<<endl ;
			return(0);
		}
		if(dboules==dmove){
					//si la casse est vide, on avance
			//si on veut autoriser le suicide, c'est ici
			for(int j=1;j<size+1;j++){
				if((p.get(b_bouges[size-1]+dmove*(-(j-1)))==couleur)&&(abs((b_bouges[size-1]+dmove*(-j)).x)+(b_bouges[size-1]+dmove*(-j)).y-pos((b_bouges[size-1]+dmove*(-j)).x)>=10) || (abs((b_bouges[size-1]+dmove*(-j)).x)+(b_bouges[size-1]+dmove*(-j)).y-pos((b_bouges[size-1]+dmove*(-j)).x))<=0 || abs((b_bouges[size-1]+dmove*(-j)).x)>4 || (b_bouges[size-1]+dmove*(-j)).y<0){
					cout<<"est pas correct (on se suicide pas)"<<endl ;
					return(0);
				}
				if(p.get(b_bouges[size-1]+dmove*(-j))==0){
					cout<<"est correct";
					return(1); //si case vide, correct
				}
				if(couleur==p.get(b_bouges[size-1]+dmove*(-j))){ //si une boule on a la même couleur que le groupe, pas correct
					cout<<"est pas correct (boule de meme couleur dans le sumito)"<<endl ;
					return(0);
				}
				if(p.get(b_bouges[size-1]+dmove*(-j))==3){
					cout<<"est  correct (bien joue, vous poussez hors du plateau) bon sens"<<endl ;
					return(1);
				}
			}
			cout<<"est pas correct (je sais plus pourquoi)"<<endl ;
			return(0);
		}
	}


	else{
		//il faut aussi verifier qu'on ne sort pas du plateau
		for(int k=0;k<size;k++){
			if(p.get(b_bouges[k]+dmove)!=0){
			cout<<"est pas correct (test truc muche)"<<endl ;
			return(0);
			}
			else{
			cout<<"est correct"<<endl ;
			return(1);
			}
		}
	}
}

Coup::Coup(cases listeboules[14], plateau p, int joueur){
	int bouledepart=Random(0,13);
	couleur=joueur;

	b_bouges[0]=listeboules[bouledepart];
	size=Random(1,3);
	dboules.x=0; dboules.y=0;
	dmove.x=0, dmove.y=0;
	while(dboules.x==0&&dboules.y==0){
		dboules.x=Random(-1,1); dboules.y=Random(-1,1);
	}
	while(dmove.x==0&&dmove.y==0){
		dmove.x=Random(-1,1); dmove.y=Random(-1,1);
	}

   int i=0;
   while(p.get(b_bouges[0]+dboules*i)==joueur&&i<size){
		b_bouges[i]=b_bouges[0]+dboules*i;
		i=i+1;
   }
   cases c=b_bouges[size-1];
   while (p.get(c)==(couleur%2 +1)) {
	  sumito.push(c) ;
	  c = c+dmove ; 
   }
   cout<<"Coup aleatoire bien genere"<<endl;
}


