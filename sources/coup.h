#include <stack>
#include "plateau.h"
using namespace std ;


class Coup
{
   stack<cases> i ; // coordonnées des billes à déplacer
   stack<cases> sumito ;
   cases dmove ; // direction du déplacement
   cases dboules ; //direction des boules
   int couleur ; //1 noir 2 blanc
   
public :
  Coup(cases tpix[61],cases tco[61]) ;
  bool estCorrect() ;
  void executeCoup(plateau p) ;
  
};


