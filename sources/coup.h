#include <stack>
#include "plateau.h"
using namespace std ;


class Coup
{
   stack<cases> i ; // coordonn�es des billes � d�placer
   stack<cases> sumito ;
   cases dmove ; // direction du d�placement
   cases dboules ; //direction des boules
   int couleur ; //1 noir 2 blanc
   
public :
  Coup(cases tpix[61],cases tco[61]) ;
  bool estCorrect() ;
  void executeCoup(plateau p) ;
  
};


