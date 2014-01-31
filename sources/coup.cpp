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


  

Coup::Coup(cases tpix[61],cases tco[61]) { //règle : direction à partir de la dernière boule cliquée (sur une boule adjacente)
  i.push(souris(tpix,tco)) ; //on rentre la première case
  cases n=souris(tpix,tco) ;
  i.push(souris(tpix,tco)) ;
  if(plateau.get(n)==plateau.get(i.pop));
  else{}
  
  //tant que c'est des cases de la même couleur, on les met...//à vérifier le i[0]
    n=souris(tpix,tco)  ; i.push(n) ; 
  }
  //attention faut rempli dmove et dboules
  //on peut pas cliquer n'importe où

  
}



int estCorrect(Coup coup, plateau p){} //remplir le sumito


void Coup::executeCoup(plateau p) //idem en C
{
    //dépiler le sumito + sortir ce qui doit sortir
    //dépiler i 
}



