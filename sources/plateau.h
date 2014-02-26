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
	int get(cases c);
	void set(cases c, int v);
	void deplacement(cases c,cases d, int &score_b, int &score_n);
	void executeCoup(Coup coup, int &score_b, int &score_n);
	void listeboules(int joueur, cases boules[15]);
};
