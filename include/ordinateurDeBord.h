#pragma once
#include "module.h"
#include <vector>
#include <utility>

class ordinateurDeBord{
	public :
	ordinateurDeBord ();
	bool checkCarburant(module); //suprimme les modules dont le carburant est en dessous de 40L
	void updateCarburant(module &); //calcule le carburant à partir de la consommation et du carburant restant toute les 0.1 secondes 
	long double sumPuissance(std::vector <module>); //calcule la puissance combiné de tout les modules et gère la puissance
	void sumForce(std::vector <module>); //calcule la somme des forces sur la fusée dans les deux axes de références (vertical et horizontal par rapport à la surface de la terre là où on décolle dont l'origine est placé au centre de la terre)
	void calculGravite(std::vector <module>);  //calcule la force de gravité qui s'exerce sur la fusée en tout point
	long double sumFrottement(std::vector <module>);//calcule la force de frottement qui s'exerce sur la fusée en tout point (devient minime à partir d'une certaine altitude)
	void updateMouv(long double,long double); //calcule la position de la fusée en tout point à partir de l'accélération et de la vitesse dans les deux axes de référence
	long double checkMasse(std::vector <module>); //calule la masse de la fusée à tout instant en prenant en compte le carburant restant
	long double densite(); //calcule la densité de l'air afin de pouvoir calculer la force de frottement
	void updateAngle(long double); //modifcation dans l'angle de la poussée de 0° à 90° (0° étant la poussée verticale)
	//les differentes composantes explicité des les commentaires ci-dessus
	std::pair <long double,long double> gravite;
	std::pair <long double,long double> position; 
	std::pair <long double,long double> vitesse; 
	std::pair <long double,long double> acceleration; 
	std::pair <long double,long double> SommeForces;
	long double angle; 
	
};



