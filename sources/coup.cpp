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

cases mins(stack<cases> s){
  if (empty(s)) return 0 ; 
  stack<cases> t = stack<cases> s ;
  cases m=t.pop() ;
  return min(m,mins(t));
}


  

Coup::Coup(cases tpix[61],cases tco[61]) { //r�gle : direction � partir de la derni�re boule cliqu�e (sur une boule adjacente)
  i.push(souris(tpix,tco)) ; //on rentre la premi�re case
  cases n=souris(tpix,tco) ;
  i.push(souris(tpix,tco)) ;
  if(plateau.get(n)==plateau.get(i.pop));
  else{}
  
  //tant que c'est des cases de la m�me couleur, on les met...//� v�rifier le i[0]
    n=souris(tpix,tco)  ; i.push(n) ; 
  }
  //attention faut rempli dmove et dboules
  //on peut pas cliquer n'importe o�

  
}



int estCorrect(Coup coup, plateau p){} //remplir le sumito


void Coup::executeCoup(plateau p) //idem en C
{
    //d�piler le sumito + sortir ce qui doit sortir
    //d�piler i 
}



