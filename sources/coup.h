#include <stack>
#include "plateau.h"
using namespace std ;


class Coup
{
   cases b_bouges[3] ; // coordonnées des billes à déplacer
   int size ;
   stack<cases> sumito ;
   cases dmove ; // direction du déplacement
   cases dboules ; //direction des boules
   int couleur ; //1 noir 2 blanc
   
public :
  Coup(cases tpix[61],cases tco[61]) ;
  bool estCorrect() ;
  
};



