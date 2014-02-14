#pragma once
#include <Imagine/Graphics.h>
using namespace Imagine;
using namespace std ;
#include "annexe.h"
#include "coup.h"


//O case vide
//1 case noire
//2 cases blanche
class plateau {
	int t[61];
	int boules_b;
	int boules_n;
	cases tco[61];
public:
	plateau();
	int get(cases c,cases tco[61]);
	void set(cases c, int v, cases tco[61]);
	void deplacement(cases c,cases d, int &score_b, int &score_n, cases tco[61]);
	void executeCoup(Coup coup, int &score_b, int &score_n, cases tco[61]);
};
