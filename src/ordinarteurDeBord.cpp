#include "../include/ordinateurDeBord.h"
#include "../include/module.h"
#include <math.h>
#include <iostream>

using namespace std;
ordinateurDeBord::ordinateurDeBord (){ // création de l'ordi de bord
	angle = 3.141592;
	position.first = 0;
	position.second=6371000.0;
	vitesse.first=0;
	vitesse.second=0;
	acceleration.first=0;
	acceleration.second=0;
	gravite.first=0;
	gravite.second=0;

}

bool ordinateurDeBord::checkCarburant(module x){ // on vérifie que le carburant est en quantité suffisante
	if (x.carburant<40){
		return(true);
	}
	else {
		return(false);
	}
}

void ordinateurDeBord::updateCarburant(module & x){
	x.carburant = x.carburant-(x.consomation*x.throttle*0.1);// met à jour le carburant
}

long double ordinateurDeBord::sumPuissance(vector <module> lanceurVec){// fait la somme de la puissance dégagée par tous les moteurs allumés
	long double sum=0;	
	for (auto x:lanceurVec){
		sum += (x.puissance*x.throttle);
	}
	return sum;
}
void ordinateurDeBord::calculGravite(vector <module> lanceurVec){// calcule la gravité à l'endroit où se trouve la fusée
	long double masseTot=0;
	for (auto x:lanceurVec){
	masseTot+=x.masse;
	masseTot+=x.carburant;
		
	}
	long double vecR = sqrt(pow(position.first,2)+pow(position.second,2));
	gravite.first = -39.857128E13*masseTot*position.first/pow(vecR,3);
	gravite.second = -39.857128E13*masseTot*position.second/pow(vecR,3);
}

long double ordinateurDeBord::densite(){// calcule la densité de l'air à l'endroit où se trouve la fusée
	long double altitude = sqrt(pow(position.first,2)+pow(position.second,2))-3371000.0;
	long double pres =0;
	if (-0.0065*altitude+288.15 > 0){
		pres = 101325*pow(288.15/(-0.0065*altitude+288.15),1+(9.80665*0.0034836177811575927)/-0.0065);
	}
	else{
		pres = 0;
	}
	return pres;
}

long double ordinateurDeBord::sumFrottement(vector <module> lanceurVec){ // fait la somme des frottements
	long double surfaceTot=0;
	for (auto x:lanceurVec){
		surfaceTot+=x.surfaceFrot;
	}
	long double forceFrot=0;
	forceFrot = pow(vitesse.first,2)*pow(vitesse.second,2)*densite()*surfaceTot;
	
	return forceFrot;
	
}

void ordinateurDeBord::sumForce(vector <module> lanceurVec){ // calcul de la somme des forces
	calculGravite(lanceurVec);
	long double power = sumPuissance(lanceurVec); 
	long double frot = sumFrottement(lanceurVec);	
	SommeForces.first = gravite.first+power * cos(angle)-frot *cos(angle)*0; // l'angle est un angle dans le repère de la terre
	SommeForces.second = gravite.second+power * sin(angle)-frot * sin(angle)*0;
}
long double ordinateurDeBord::checkMasse(vector <module> lanceurVec){// retourne la masse totale carburant compris
	long double masseTot=0;
	for (auto x:lanceurVec){
	masseTot+=x.masse;
	masseTot+=x.carburant;	
	}
	return masseTot;
}

void ordinateurDeBord::updateMouv(long double t,long double masse){ //bouge la fusée
	acceleration.first=SommeForces.first/masse;
	acceleration.second=SommeForces.second/masse;
	vitesse.first += acceleration.first*t;
	vitesse.second += acceleration.second*t;
	position.first += vitesse.first*t;
	position.second+=vitesse.second*t;	
}
void ordinateurDeBord::updateAngle(long double temps){//ancienne fonction qui donnait l'angle en fonction du temps
	if (temps <2*60){
		angle = 3.141592/2;
	}
	else {
		angle = 0;
	}	
}
