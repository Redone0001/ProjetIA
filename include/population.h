#pragma once

#include "fusee.h"
#include "brain.h"
#include "save.h"
#include "ordinateurDeBord.h"
#include <vector>

class Population{
public:
	int taille;
	std::vector<fusee> Fusee;
	long double SumFit;
	int BestFusee;
	int Generation;

	Population(int);
	void darwinPlay();
	bool allDead();
	void CalculFit();
	void NextStep(long double t);
	void mutation();
	int FindBestOne();
	fusee selectionParent();
};

