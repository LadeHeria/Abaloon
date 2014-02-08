#include "annexe.h"
#include "plateau.h"

using namespace std ;
plateau::plateau(){
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
		for (int i=0; i<61&&(c!=tco[i]); i++) {
			return(t[i]);

		}
	}
}

