#include "annexe.h"
#include "plateau.h"

using namespace std ;
plateau::plateau(){//constructeur de plateau
	generer_co(tco);
	boules_b=14;
	boules_n=14;
	for(int i=0; i<61;i++){
		t[i]=0 ; 
	}
	for(int i=0; i<11;i++){
		t[i]=1;
		t[60-i]=2;
	}
	t[13]=t[15]=t[14]=1;
	
	t[60-15]=t[60-13]=t[60-14]=2;
}



int plateau::get(cases c){//rend la couleur (convention habituelle) de la boule en c
	if(estdedans(c)==0){
		return(3);
	}
  	else{
		//c'est ici d'ici que venait l'erreur sur l'indice j
		//je l'ai changé en f pour la trouver et j'ai rajouté "f=0", (au lieu de juste "int f" mais ça marche toujours pas
 		int f=0 ;
  		for (int i=0; i<61&&(c!=tco[i]); i++) {
 			f=i+1; //erreur ici, c'est i+1...
 			}
 		return(t[f]);
 	}
 
 }
 
 void plateau::set(cases c, int v) {// donne la couleur v à la case c
 	int i=0 ;
 	//for (int i=0; i<61&&(c!=tco[i]); i++) {
 	//j=i+1;
 	//		}
 	//t[j]=v ;
	while(c!=tco[i]&&i<61){
		i=i+1;
	}
	t[i]=v;
 }
 

 
 void plateau::deplacement(cases c,cases d, int &score_b, int &score_n){//déplacement de ce qu'il y a en c suivant la direction d ; maj des scores
	
 	if(estdedans(c+d)==0){
		if (get(c)==1) {
			score_n=score_n-1 ;
		}
		if(get(c)==2) {
			score_b=score_b-1 ;
		}
	  set(c,0) ;
 	}
 	else {set(c+d,get(c)) ; set(c,0); //cout<<c.x<<" "<<c.y<<" to "<<(c+d).x<<" "<<(c+d).y<<endl;
	};
 }
 
 
 void plateau::executeCoup(Coup coup, int &score_b, int &score_n){//exécution d'un coup (préalablement validé par estCorrect) et maj des scores
	 		while((!coup.sumito.empty())){
 		deplacement(coup.sumito.top(), coup.dmove, score_b, score_n) ; coup.sumito.pop() ; //cout<<"sumito"<<endl ;
			}
	if(coup.dboules==coup.dmove){
	   for(int i=0; i<coup.size ; i++){
 			deplacement(coup.b_bouges[coup.size-i-1],coup.dmove,score_b,score_n) ;
	   }
   }
   else if(coup.dboules==coup.dmove*(-1)){
		for(int i=0; i<coup.size ; i++){
 			deplacement(coup.b_bouges[i],coup.dmove,score_b,score_n) ;
		}
 	
 	}
   else{
   for(int i=0; i<coup.size ; i++){
 			deplacement(coup.b_bouges[i],coup.dmove,score_b,score_n) ;
	   }
   }
 	
 }

 void plateau::listeboules(int joueur, cases boules[15]){//crée un tableau de 15 cases contenant les coordonnées de chaque boule ; en 15ème position le nombre de boules <15
	 int j=0;
	 cases c;
	 for(int i=0; i<61; i++){
		 if(t[i]==joueur){
			boules[j]=tco[i];
			j=j+1;
		 }
	 }
	 c.x=j;
	 c.y=j;
	boules[14]=c; // info nombre de boules contenue dans la 15ème case (numérotée 14)
 }

 bool plateau::estdedans(cases c){ //test si une case existe sur le plateau <=> si des coordonnées quelconques se réfèrent à une case
	 if(abs(c.x)>4){
		return(0);
	 }
	 else if((c.x==-4)&&(c.y<1||c.y>5)){
		return(0);
	 }
	 else if((c.x==-3)&&(c.y<1||c.y>6)){
		return(0);
	 }
	 else if((c.x==-2)&&(c.y<1||c.y>7)){
		return(0);
	 }
	 else if((c.x==-1)&&(c.y<1||c.y>8)){
		return(0);
	 }
	 else if((c.x==0)&&(c.y<1||c.y>9)){
		return(0);
	 }
	 else if((c.x==1)&&(c.y<2||c.y>9)){
		return(0);
	 }
	 else if((c.x==2)&&(c.y<3||c.y>9)){
		return(0);
	 }
	 else if((c.x==3)&&(c.y<4||c.y>9)){
		return(0);
	 }
	 else if((c.x==4)&&(c.y<5||c.y>9)){
		return(0);
	 }
	 else{
	 return(1);
	 }
 }

 int plateau::evalCoup(Coup coup){ //donne le nombre de "points" que rapporte le coup, basé seulement sur le nombre de billes adverses sorties
	 
	 if(!(coup.sumito.empty())&&estdedans(coup.sumito.top()+coup.dmove)==0){
		return(1);
	 }
	 else{
	 return(0);
	 }
 }

  int plateau::evalCoup2(Coup coup){ //donne le nombre de "points" que rapporte le coup : sortir une boule vaut +1000, être au centre vaut
	 int valeur=0;// valeur à déterminer du coup
	 if(!(coup.sumito.empty())&&estdedans(coup.sumito.top()+coup.dmove)==0){// si tu sors une boule : +1000
		valeur=valeur+1000; //valeur du coup lorsqu'on pousse dehors
	 }
	 //for(int i=0; i<coup.size;i++){
	//	valeur=valeur+4-abs((coup.b_bouges[i]+coup.dmove).x)+4-abs(5-(coup.b_bouges[i]+coup.dmove).y);//on privilegie des coups qui mettent des boules au centre
	 //}
	 plateau q; // plateau fictif où on exécute à blanc le coup
	 int a=14; 
	 int b=14;
	 for(int j=0; j<61; j++){//ici on copie le plateau présent sur le plateau où sera exéctué le coup
		q.t[j]=t[j];
	 }
	 q.executeCoup(coup, a,b); // on exécute le coup sur ce nouveau tableau
	 cases boules[15]; // dans ce tableau on va mettre les positions de toutes les boules après exécution
	 q.listeboules(coup.couleur,boules); //ci-fait
	 for(int k=0; k<boules[14].x;k++){//on parcourt toutes les boules
		valeur=valeur+4-abs(boules[k].x)+4-abs(5-boules[k].y)+Random(0,9);//plus proche du centre => plus de point ; facteur aléatoire pour éviter les attracteurs
	  
		if(abs(boules[k].x)==4||abs(5-boules[k].y)==4||((boules[k].x<1)&&(abs(boules[k].x)+boules[k].y))||(boules[k].x=boules[k].y-1)){// pénalité de 40 si boule au bord
		valeur=valeur-40;
		}
	  }

	 return(valeur);

 }
  
