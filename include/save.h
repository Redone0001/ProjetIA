#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "ordinateurDeBord.h"

void initialisationCSV(std::string fileName);

void saveToCSV(std::string fileName, ordinateurDeBord ENIAC, long double t);

