#include "../include/ordinateurDeBord.h"
#include "../include/module.h"
#include <math.h>
#include <iostream>

using namespace std;
ordinateurDeBord::ordinateurDeBord (){
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

bool ordinateurDeBord::checkCarburant(module x){
	if (x.carburant<40){
		x.~module();
		return(true);
	}
	else {
		return(false);
	}
}

void ordinateurDeBord::updateCarburant(module & x){
	x.carburant = x.carburant-(x.consomation*x.throttle*0.1);
	//cout <<x.carburant<<endl;
}

long double ordinateurDeBord::sumPuissance(vector <module> lanceurVec){
	long double sum=0;	
	for (auto x:lanceurVec){
		sum += (x.puissance*x.throttle);
	}
	return sum;
}
void ordinateurDeBord::calculGravite(vector <module> lanceurVec){
	long double masseTot=0;
	for (auto x:lanceurVec){
	masseTot+=x.masse;
	masseTot+=x.carburant;
		
	}
	long double vecR = sqrt(pow(position.first,2)+pow(position.second,2));
	gravite.first = -39.857128E13*masseTot*position.first/pow(vecR,3);
	gravite.second = -39.857128E13*masseTot*position.second/pow(vecR,3);
	//cout <<gravite.first<<","<<gravite.second<<","<<masseTot<<","<<position.first<<","<<position.second<<endl;
}

long double ordinateurDeBord::densite(){
	long double altitude = sqrt(pow(position.first,2)+pow(position.second,2))-3371000.0;
	long double pres =0;
	if (altitude<350000){
		
		pres = 101325*pow(1-(0.0065*altitude/288.15),(sqrt(pow(gravite.first,2)*pow(gravite.second,2)))*0.0289644/(8.31447*0.0065));
	}
	else{
		pres = 0;
	}
	return pres;
}

long double ordinateurDeBord::sumFrottement(vector <module> lanceurVec){
	long double surfaceTot=0;
	for (auto x:lanceurVec){
		surfaceTot+=x.surfaceFrot;
	}
	long double forceFrot=0;
	forceFrot = pow(vitesse.first,2)*pow(vitesse.second,2)*densite()*surfaceTot;
		
	return forceFrot;
	
}

void ordinateurDeBord::sumForce(vector <module> lanceurVec){
//cout <<"calcul des forces"<<endl;	
	calculGravite(lanceurVec);
//cout <<"gravite done"<<endl;
	long double power = sumPuissance(lanceurVec); 		// ATTENTION ceci ne fonctionne que si on décolle "vers le haut" si on part de l'autre côté de la terre on va avoir des soucis
//cout <<"puissance done"<<endl;
	long double frot = sumFrottement(lanceurVec);	
	//cout<<angle<<endl;		// il est nécéssaire de bien gérer l'angle de la fusée
	SommeForces.first = gravite.first+power * cos(angle)-frot *cos(angle)*0;
	SommeForces.second = gravite.second+power * sin(angle)-frot * sin(angle)*0;
	
}
long double ordinateurDeBord::checkMasse(vector <module> lanceurVec){
	long double masseTot=0;
	for (auto x:lanceurVec){
	masseTot+=x.masse;
	masseTot+=x.carburant;	
	}
	return masseTot;
}

void ordinateurDeBord::updateMouv(long double t,long double masse){
	//cout <<"vit :"<<vitesse.first<<","<<vitesse.second<<"#"<<t<<endl;
	acceleration.first=SommeForces.first/masse;
	acceleration.second=SommeForces.second/masse;
	vitesse.first += acceleration.first*t;
	vitesse.second += acceleration.second*t;
	position.first += vitesse.first*t;
	position.second+=vitesse.second*t;
	//cout <<"SF: "<<SommeForces.first<<","<<SommeForces.second<<endl;
	
		
}
void ordinateurDeBord::updateAngle(long double Angle){
	
	//angle = (1/(1+exp(-0.05*(temps-120))*1.570796)+1.570796);	
	/*if (temps <2*60){
		angle = 3.141592/2;
	}
	else {
		angle = 0;
	}*/
	angle=Angle;	
}
