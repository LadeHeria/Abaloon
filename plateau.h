#pragma once
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
public:
	plateau();
	int get(cases c);
	void set(cases c, int v);
	void deplacement(cases c,cases d);
	void plateau::executeCoup(Coup coup);
};
