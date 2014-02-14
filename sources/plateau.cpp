#include "annexe.h"
#include "plateau.h"

using namespace std ;
plateau::plateau(){
	generer_co(tco[61]);
	boules_b=14;
	boules_n=14;
	for(int i=0; i<11;i++){
		t[i]=1;
		t[60-i]=2;
	}
	t[12]=t[13]=t[14]=0;
	t[60-12]=t[60-13]=t[60-14]=0;
}

int plateau::get(cases c, cases tco[61]){
	if(abs(c.x)+c.y>10){
		return(3);
	}
  	else{
 		int j ;
  		for (int i=0; i<61&&(c!=tco[i]); i++) {
 			j=i;
 			}
 		return(t[j]);
 	}
 
 }
 
 void plateau::set(cases c, int v, cases tco[61]) {
 	int j ;
 	for (int i=0; i<61&&(c!=tco[i]); i++) {
 			j=i;
 			}
 	t[j]=v ;
 }
 

 
 void plateau::deplacement(cases c,cases d, int &score_b, int &score_n, cases tco[61]){
 	if(abs((c+d).x)+(c+d).y>=10){
 	if (get(c,tco[61])==1) score_n++ ; if(get(c,tco[61])==2) score_b++ ;
 	set(c,0) ;
 	}
 	else {set(c+d,get(c, tco[61])) ; set(c,0);};
 }
 
 
 void plateau::executeCoup(Coup coup, int &score_b, int &score_n, cases tco[61]){
 	while((!coup.sumito.empty())){
 		deplacement(coup.sumito.top(), coup.dmove, score_b, score_n, tco[61]) ; coup.sumito.pop ;
 	}
 	for(int i=0; i<coup.sumito.size() ; i++){
 		deplacement(coup.b_bouges[i],coup.dmove,score_b,score_n, tco[61]) ;
 	}
 	
 }
		