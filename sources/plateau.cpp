#include "annexe.h"
#include "plateau.h"

using namespace std ;
plateau::plateau(){
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



int plateau::get(cases c){
	if((abs(c.x)+c.y-pos(c.x)>10)||(abs(c.x)+c.y-pos(c.x)<0)){
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
 
 void plateau::set(cases c, int v) {
 	int j ;
 	for (int i=0; i<61&&(c!=tco[i]); i++) {
 			j=i+1;
 			}
 	t[j]=v ;
 }
 

 
 void plateau::deplacement(cases c,cases d, int &score_b, int &score_n){
 	//if((abs((c+d).x)+(c+d).y-pos((c+d).x)>10) || (abs((c+d).x)+(c+d).y-pos((c+d).x))<0){
	//  if (get(c)==1) score_n++ ; if(get(c)==2) score_b++ ;
	//  set(c,0) ;
 	//}
	if (0) {} 
 	else {set(c+d,get(c)) ; set(c,0); cout<<c.x<<" "<<c.y<<" to "<<(c+d).x<<" "<<(c+d).y<<endl;};
 }
 
 
 void plateau::executeCoup(Coup coup, int &score_b, int &score_n){
 	while((!coup.sumito.empty())){
 		deplacement(coup.sumito.top(), coup.dmove, score_b, score_n) ; coup.sumito.pop() ; cout<<"sumito"<<endl ;
 	}
 	//for(int i=0; i<coup.sumito.size() ; i++){// partie sur le mouvement du sumito à refaire !!
 	//	deplacement(coup.b_bouges[i],coup.dmove,score_b,score_n) ;
 	//}
 	for(int i=0; i<coup.size +1 ; i++){
 		deplacement(coup.b_bouges[coup.size-i],coup.dmove,score_b,score_n) ;
 	}
 	
 }
		