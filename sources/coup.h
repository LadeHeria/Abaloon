#include <stack>
#include "plateau.h"
using namespace std ;


class Coup
{
   cases b_bouges[3] ; // coordonn�es des billes � d�placer
   int size ;
   stack<cases> sumito ;
   cases dmove ; // direction du d�placement
   cases dboules ; //direction des boules
   int couleur ; //1 noir 2 blanc
   
public :
  Coup(cases tpix[61],cases tco[61]) ;
  bool estCorrect() ;
  
};



