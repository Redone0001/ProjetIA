#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "ordinateurDeBord.h"

//on initialise les fonctions qui vont nous permettre d'enregistrer nos données dans un CSV

void initialisationCSV(std::string fileName); 

void saveToCSV(std::string fileName, ordinateurDeBord ENIAC, long double t);

