#include <stack>
#include "plateau.h"
using namespace std ;


class Coup
{
   stack<cases> i ; // coordonnées des billes à déplacer
   cases dmove ; // direction du déplacement
   
public :
  Coup(cases tpix[61],cases tco[61]) ;
  bool estCorrect() ;
  void executeCoup(plateau p) ;
  
};


