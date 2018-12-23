#pragma once
#include "module.h"
#include <vector>
#include <utility>

class ordinateurDeBord{
	public :
	ordinateurDeBord ();
	bool checkCarburant(module); //supprimme les modules dont le carburant est en-dessous de 40L
	void updateCarburant(module &); //calcule la quantité de carburant à partir de la consommation et du carburant restant toutes les 0.1 secondes 
	long double sumPuissance(std::vector <module>); //calcule la puissance combinée de tous les modules et gère la puissance
	void sumForce(std::vector <module>); //calcule la somme des forces sur la fusée dans les deux axes de référence (vertical aligné avec la fusée au décolage et l'origine placée au centre de la Terre)
	void calculGravite(std::vector <module>);  //calcule la force de gravité qui s'exerce sur la fusée en tout point
	long double sumFrottement(std::vector <module>);//calcule la force de frottement qui s'exerce sur la fusée en tout point (devient minime à partir d'une certaine altitude)
	void updateMouv(long double,long double); //calcule la position de la fusée en tout point à partir de l'accélération et de la vitesse dans les deux axes de référence
	long double checkMasse(std::vector <module>); //calule la masse de la fusée à tout instant en prenant en compte le carburant restant
	long double densite(); //calcule la densité de l'air afin de pouvoir calculer la force de frottement
	void updateAngle(long double); //modifcation de l'angle de la poussée de 0° à 90° (0° étant la poussée verticale)
	//les différentes composantes explicitées dans les commentaires ci-dessus
	std::pair <long double,long double> gravite;
	std::pair <long double,long double> position; 
	std::pair <long double,long double> vitesse; 
	std::pair <long double,long double> acceleration; 
	std::pair <long double,long double> SommeForces;
	long double angle; 
	
};




