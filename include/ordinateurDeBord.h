#pragma once
#include "module.h"
#include <vector>
#include <utility>

class ordinateurDeBord{
	public :
	ordinateurDeBord ();
	bool checkCarburant(module); //vérifie que le carburant est pas trop bas et si c'est à un niveau critique éjecte(supprime) le module
	void updateCarburant(module &);//update le carburant 
	long double sumPuissance(std::vector <module>);// dans le sens du mouvement
	void sumForce(std::vector <module>); // modifie la pair de long double Somme des forces
	void calculGravite(std::vector <module>);  // modifie la pair de long double gravite
	long double sumFrottement(std::vector <module>);//dans le sens opposé au mouvement
	void updateMouv(long double,long double);
	long double checkMasse(std::vector <module>);
	long double densite();
	void updateAngle(long double);
	std::pair <long double,long double> gravite;
	std::pair <long double,long double> position; // la possition de la fussée est repéré dans un référentiel placé au centre de la terre et immobile
	std::pair <long double,long double> vitesse; // la vitesse est dans le même repère que la possition 
	std::pair <long double,long double> acceleration; //idem
	std::pair <long double,long double> SommeForces;
	long double angle; // angle de la fusée / à la verticale
	
};



