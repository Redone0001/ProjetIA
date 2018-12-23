#pragma once
#include "brain.h"
#include "module.h"
#include "save.h"
#include "ordinateurDeBord.h"
#include <vector>

class fusee{
public:
brain Brain;

int gen;
int throttleGeneral = 3;
bool vivant;
float fit;

std::vector <module> lanceurVec;

ordinateurDeBord ENIAC;


fusee(int,int);
void nextStep(long double t);
void calculFitness();
fusee gimmeBaby();



};
