#include <stack>
#include "plateau.h"
using namespace std ;


class Coup
{
   stack<cases> i ; // coordonn�es des billes � d�placer
   cases dmove ; // direction du d�placement
   
public :
  Coup(cases tpix[61],cases tco[61]) ;
  bool estCorrect() ;
  void executeCoup(plateau p) ;
  
};


