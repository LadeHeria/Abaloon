#include "plateau.h"
#include "coup.h"
#include "annexe.h"
#include "affiche.h"
#include <stack>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std ;

bool operator<(IA IA1, IA IA2){
    return (IA1.valeur<IA2.valeur);
	 }

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
		//cout<<"clique une case occupee margoulin"<<endl ;
		c = souris(tpix,tco);
		//cout<<c.x<<" "<<c.y<<endl; //première case
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
		  cases c2 = {-1,-1} ; //stocke une éventuelle boule mal cliquée
	    while(max(abs(dboules.x),abs(dboules.y))!=1||(dboules.x*dboules.y==-1)){//on y rentres au premier coup, puis : tant que t'as cliqué trop loin...
		if (c2.y!=(-1)) affiche_boule3(c2, tpix, tco,RED) ; //efface la mal cliquée
		//cout<<"un clique adjacent stp"<<endl ;
		dboules = c-b_bouges[0] ;//on donne la direction du groupe
		//cout<<"dboules "<<dboules.x<<" "<<dboules.y<<endl ;
		affiche_boule3(c, tpix, tco,BLUE) ; //colore la nouvelle boule sélectionnée
		b_bouges[1]=c ; 
		size=2;
		c2 =c ;
		c = souris(tpix,tco); //nouvel essai s'il le faut ; autrement ce sera la case-vide-destination ou la boule suivante
	    }
	}
	
	if (p.get(c)==couleur){ //si cette boule est aussi de la même couleur... 
	    while(dboules != (c-b_bouges[1])){//on y rentres au premier coup, puis : tant que t'as cliqué trop loin...
		//cout<<"WUT ?"<<endl ;
		c = souris(tpix,tco);//nouvel essai
		b_bouges[2]=c ;  
		size=2;
		
		 
	    }
	    b_bouges[2]=c ; 
	      affiche_boule3(c, tpix, tco,BLUE) ;
		size=3;
	c = souris(tpix,tco);//case destination
	}
	
	

  //cout<<c.x<<" "<<c.y<<endl ;//case suivante cliquée
  
	
  dmove = c-b_bouges[size-1]; 
  //cout<<"("<<c.x<<","<<c.y<<") - "<<"("<<b_bouges[size-1].x<<","<<b_bouges[size-1].y<<") ="<<"dmove "<<dmove.x<<" "<<dmove.y<<endl;//la direction du déplacement //cout<<"dmove "<<dmove<<endl;
  //cout<<"taille :"<<size<<endl;
  while (p.get(c)==couleurop(couleur)) {
	  sumito.push(c) ; c = c+dmove ; }
	  //cout<<"la couleur est "<<couleur<<endl;//tant que de l'autre couleur dans la direction du mouvement, on ajoute (attention foireux quand ça sort du plateau
	  
   
}


bool Coup::estCorrect(plateau p) const { //remplir le sumito
	//je suis obligé de dépiler plusieurs fois dans la fonction pour tester les cases si on n'avance pas dans la direction du groupe,
	//donc je pense qu'une pile n'est pas la bonne structure, j'ai considéré que c'était un tableau de 3 cases, il faudrait trouver une notation 
	//pour lorsqu'on ne selectionne que deux elements (pour le troisieme) OU noter dans coup le nombre d'elements sous la forme int size <--MIEUX
//normalement on peut faire des égalités de cases, multiplication par un scalaire
 
	if(max(abs(dmove.x),abs(dmove.y))!=1){
		//cout<<"est pas correct (dmove trop grand)"<<endl ;
					return(0);
	}
	if((dboules==dmove)||(dboules==dmove*(-1))){
		//on regarde ce qu'il y a dans cette direction 
		//et on construit le sumito
		if(dboules==dmove){
					//si la casse est vide, on avance
			//si on veut autoriser le suicide, c'est ici
			for(int k=1;k<size+1;k++){
				if((p.get(b_bouges[size-1]+dmove*((k-1)))==couleur)&&p.estdedans(b_bouges[size-1]+dmove*(k))==0){
					//cout<<"est pas correct (on se suicide pas)"<<endl ;
					return(0);
				}
				if(p.get(b_bouges[size-1]+dmove*k)==0){
					//cout<<"est correct bon sens";
					return(1); //si case vide, correct
				}
				if(couleur==p.get(b_bouges[size-1]+dmove*k)){ //si une boule on a la même couleur que le groupe, pas correct
					//cout<<"est pas correct (boule de meme couleur dans le sumito)"<<endl ;
					return(0);
				}
				//cout<<"ici teest"<<p.get(b_bouges[size-1]+dmove*k)<<" "<<p.get(b_bouges[size-1]+dmove*(k-1))<<" "<<couleur<<" "<<couleurop(couleur)<<endl ;
				if(p.get(b_bouges[size-1]+dmove*k)==3&&p.get(b_bouges[size-1]+dmove*(k-1))==couleurop(couleur)){
					//cout<<"est  correct (bien joue, vous poussez hors du plateau) bon sens"<<endl ;
					return(1);
				}
			}
			//cout<<"est pas correct (je sais plus pourquoi 2)"<<endl ;
			return(0);
		}
		if(dboules==dmove*(-1)){
					//si la casse est vide, on avance
			//si on veut autoriser le suicide, c'est ici
			for(int k=1;k<size+1;k++){
				if((p.get(b_bouges[0]+dmove*((k-1)))==couleur)&&p.estdedans(b_bouges[0]+dmove*(k))==0){
					//cout<<"est pas correct (on se suicide pas)"<<endl ;
					return(0);
				}
				if(p.get(b_bouges[0]+dmove*(k))==0){
					//cout<<"est correct mauvais sens";
					return(1); //si case vide, correct              
				}
				if(couleur==p.get(b_bouges[0]+dmove*(k))){ //si une boule on a la même couleur que le groupe, pas correct
					//cout<<"est pas correct (boule de meme couleur dans le sumito)"<<endl ;
					return(0);
				}
				if(p.get(b_bouges[0]+dmove*(k))==3&&p.get(b_bouges[0]+dmove*(k-1))==couleurop(couleur)){
					//cout<<"est  correct (bien joue, vous poussez hors du plateau) mauvais sens"<<endl ;
					return(1);
				}
			}
			//cout<<"est pas correct (je sais plus pourquoi)"<<endl ;
			return(0);
		}
	}


	else{
		//il faut aussi verifier qu'on ne sort pas du plateau
		int a=0;
		for(int k=0;k<size;k++){
			if(p.estdedans(b_bouges[k]+dmove)==1&&p.get(b_bouges[k]+dmove)==0){
				a=a;
			}
			else{
				//cout<<"est pas correct pousse sur le travers"<<endl;
			a=a+1;
			}
		}
		if(a==0){
		//cout<<"est correct, vous poussez en dehors (sur le travers)"<<endl;
		return(1);
		}
		else{
		return(0);
		}
	}
}

Coup::Coup(cases listeboules[15], plateau p, int joueur){ // constructeur de coup aléatoire
  
	int bouledepart=Random(0,listeboules[14].x);
	couleur=joueur;
	cases direction[6];
	direction[0].x=1; direction[0].y=0;
	direction[1].x=1; direction[1].y=1;
	direction[2].x=0; direction[2].y=1;
	direction[3].x=-1; direction[3].y=0;
	direction[4].x=-1; direction[4].y=-1;
	direction[5].x=0; direction[5].y=-1;

	b_bouges[0]=listeboules[bouledepart];
	size=Random(1,4);
	dboules=direction[Random(0,6)];
	dmove=dboules*(-1);
	while(dmove==dboules*(-1)){
		dmove=direction[Random(0,6)];
	}

   int i=0;
   
   while(p.get(b_bouges[0]+dboules*i)==joueur&&i<size){
		b_bouges[i]=b_bouges[0]+dboules*i;
		i=i+1;
   }
   size=i;

   //construction du sumito
   if(dboules==dmove){
	   cases c=b_bouges[size-1]+dmove;
		while (p.get(c)==couleurop(couleur)) {
			sumito.push(c) ;
			c = c+dmove;
		}
   }
   else if(dboules==dmove*(-1)){
	   cases c=b_bouges[0]+dmove;
		while (p.get(c)==couleurop(couleur)) {
			sumito.push(c) ;
			c = c+dmove;
		}
   }
  // else{
	//   for(int i=0; i<size; i++){
		//sumito.push(b_bouges[i]+dmove);
	   //}
   //}
   //cout<<"Coup aleatoire bien genere"<<endl;
}

Coup::Coup(plateau p, cases bouledep, cases adboules, int asize, cases admove, int ajoueur){
	couleur=ajoueur;
	b_bouges[0]=bouledep;
	dboules=adboules;
	dmove=admove;
	size=asize;
	int i=0;
   
   while(p.get(b_bouges[0]+dboules*i)==ajoueur&&i<size){
		b_bouges[i]=b_bouges[0]+dboules*i;
		i=i+1;
   }
   size=i;
   //construction du sumito
   if(dboules==dmove){
	   cases c=b_bouges[size-1]+dmove;
		while (p.get(c)==couleurop(couleur)) {
			sumito.push(c) ;
			c = c+dmove;
		}
   }
   else if(dboules==dmove*(-1)){
	   cases c=b_bouges[0]+dmove;
		while (p.get(c)==couleurop(couleur)) {
			sumito.push(c) ;
			c = c+dmove;
		}
   }
}

Coup::Coup(){
	size=0 ;
	couleur=1;
}
IA::IA(){
	valeur=0;

}

Coup IA1(int profondeur, cases listeboules[15], plateau p, int joueur){
	vector <IA> tcoup; 
	cases direction[6];
	direction[0].x=1; direction[0].y=0;
	direction[1].x=1; direction[1].y=1;
	direction[2].x=0; direction[2].y=1;
	direction[3].x=-1; direction[3].y=0;
	direction[4].x=-1; direction[4].y=-1;
	direction[5].x=0; direction[5].y=-1;
	int d=0;
	for(int i=0; i<listeboules[14].x; i++){//parcours de toutes les boules
		for(int j=0; j<6; j++){// .... de toutes les directions du groupe à déplacer
			for(int k=1; k<3; k++){//... de toutes les tailles de groupe
				for(int l=0; l<6&&l!=j+3%6;l++){//toutes les directions de déplacement du groupe sauf colinéaire de sens opposé au vecteur groupe (pk ?)
					Coup coup=Coup(p, listeboules[i], direction[j], k, direction[l], joueur); // construction du coup en question
					IA IA11;
					if(coup.estCorrect(p)==1){
						IA11.coup=coup;
						//cout<<"coucou"<<endl;
						if(p.evalCoup(coup)==1){
							//cout<<"coucou1"<<endl;
							IA11.valeur=IA11.valeur+1;
						}
						//cout<<"coucou2"<<endl;
					tcoup.push_back(IA11);
					
					}
					
				}
			}
		}
	}
	sort(tcoup.begin(), tcoup.end());
	//cout<<"taille tabeau"<<tcoup.size()<<endl;
	int compteur=0;
	for(int j=0; j<tcoup.size()&&tcoup[j].valeur==tcoup[tcoup.size()-1].valeur; j++){
		compteur=j;
	}
	//cout<<"compteur"<<compteur<<endl;
	//delete[] tcoup;
	//Coup coup=Coup(p, listeboules[0], direction[0], 1, direction[0], 1);
	return(tcoup[Random(tcoup.size()-compteur-1,tcoup.size())].coup);
	//return(tcoup.back().coup);
}

Coup exetest (Coup coup, cases d){ 
  Coup c ;
  for(int j=0; j<coup.size ; j++){
	c.b_bouges[j] = coup.b_bouges[j]+ d ;	
	}
return c ;
}

bool aubord (cases c, plateau p) {
  bool b =1 ; 
  cases direction[6];
	direction[0].x=1; direction[0].y=0;
	direction[1].x=1; direction[1].y=1;
	direction[2].x=0; direction[2].y=1;
	direction[3].x=-1; direction[3].y=0;
	direction[4].x=-1; direction[4].y=-1;
	direction[5].x=0; direction[5].y=-1;
  
  for(int l=0; l<6 ;l++){
    b = b && p.estdedans(c+direction[l]) ;
  }
   return !b ;
}

int aubords (Coup coup, plateau p){
  int n =0 ;
  for(int i=0; i<coup.size; i++){
    if(aubord(coup.b_bouges[i],p)) n++ ;
  }
  return n ;
}

int valeur (Coup coup, plateau p) {
  return -aubords(exetest(coup,coup.dmove),p)+aubords(coup,p);
}

int bords(vector <IA> tcoup, int borneinf, int bornesup, plateau p){
  int score = valeur (tcoup[borneinf].coup,p) ; 
  int indice = borneinf ;
  for(int j=0; j<(bornesup-borneinf) ; j++){
	if (valeur (tcoup[borneinf+j].coup,p)>score) {
	  score = valeur (tcoup[borneinf+j].coup,p);
	  indice = borneinf+j;
	}
  }
  return indice ;
}


Coup IA2(int profondeur, cases listeboules[15], plateau p, int joueur){
	vector <IA> tcoup; 
	cases direction[6];
	direction[0].x=1; direction[0].y=0;
	direction[1].x=1; direction[1].y=1;
	direction[2].x=0; direction[2].y=1;
	direction[3].x=-1; direction[3].y=0;
	direction[4].x=-1; direction[4].y=-1;
	direction[5].x=0; direction[5].y=-1;
	int d=0;
	for(int i=0; i<listeboules[14].x; i++){//parcours de toutes les boules
		for(int j=0; j<6; j++){// .... de toutes les directions du groupe à déplacer
			for(int k=1; k<3; k++){//... de toutes les tailles de groupe
				for(int l=0; l<6&&l!=j+3%6;l++){//toutes les directions de déplacement du groupe sauf colinéaire de sens opposé au vecteur groupe (pk ?)
					Coup coup=Coup(p, listeboules[i], direction[j], k, direction[l], joueur); // construction du coup en question
					IA IA11;
					if(coup.estCorrect(p)==1){
						IA11.coup=coup;
						//cout<<"coucou"<<endl;
						IA11.valeur=p.evalCoup2(coup);
					tcoup.push_back(IA11);
					
					}
					
				}
			}
		}
	}
	sort(tcoup.begin(), tcoup.end());
	//cout<<"taille tabeau"<<tcoup.size()<<endl;
	int compteur=0;
	for(int j=0; j<tcoup.size()&&tcoup[j].valeur==tcoup[tcoup.size()-1].valeur; j++){
		compteur=j;
	}
	return(tcoup[Random(tcoup.size()-compteur-1,tcoup.size())].coup);
}

/*Coup IA3(int profondeur, cases listeboules[15], plateau p, int joueur){
	vector <IA> tcoup; 
	cases direction[6];
	direction[0].x=1; direction[0].y=0;
	direction[1].x=1; direction[1].y=1;
	direction[2].x=0; direction[2].y=1;
	direction[3].x=-1; direction[3].y=0;
	direction[4].x=-1; direction[4].y=-1;
	direction[5].x=0; direction[5].y=-1;
	for(int i=0; i<listeboules[14].x; i++){//parcours de toutes les boules
		for(int j=0; j<6; j++){// .... de toutes les directions du groupe à déplacer
			for(int k=1; k<3; k++){//... de toutes les tailles de groupe
				for(int l=0; l<6&&l!=j+3%6;l++){//toutes les directions de déplacement du groupe sauf colinéaire de sens opposé au vecteur groupe (pk ?)
					Coup coup=Coup(p, listeboules[i], direction[j], k, direction[l], joueur); // construction du coup en question
					IA IA11;
					if(coup.estCorrect(p)==1){
						IA11.coup=coup;
						//cout<<"coucou"<<endl;
						IA11.valeur=p.evalCoup2(coup);
					tcoup.push_back(IA11);
					
					}
					
				}
			}
		}
	}
	sort(tcoup.begin(), tcoup.end());
	//cout<<"taille tabeau"<<tcoup.size()<<endl;
	int compteur=0;
	for(int j=0; j<tcoup.size()&&tcoup[j].valeur==tcoup[tcoup.size()-1].valeur; j++){
		compteur=j;
	}
	return(tcoup[Random(tcoup.size()-compteur-1,tcoup.size())].coup);
}

int Minf(int profondeur, IA IA33){
	if(profondeur==0){
		return(IA33.p.evalCoup2(IA33.coup));
	}
	cases direction[6];
	direction[0].x=1; direction[0].y=0;
	direction[1].x=1; direction[1].y=1;
	direction[2].x=0; direction[2].y=1;
	direction[3].x=-1; direction[3].y=0;
	direction[4].x=-1; direction[4].y=-1;
	direction[5].x=0; direction[5].y=-1;
	for(int i=0; i<listeboules[14].x; i++){//parcours de toutes les boules
		for(int j=0; j<6; j++){// .... de toutes les directions du groupe à déplacer
			for(int k=1; k<3; k++){//... de toutes les tailles de groupe
				for(int l=0; l<6&&l!=j+3%6;l++){//toutes les directions de déplacement du groupe sauf colinéaire de sens opposé au vecteur groupe (pk ?)
					Coup coup=Coup(p, listeboules[i], direction[j], k, direction[l], joueur); // construction du coup en question
}
*/