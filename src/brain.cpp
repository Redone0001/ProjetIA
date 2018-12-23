#include "../include/brain.h"

using namespace std;

brain::brain(int size): // constructeur du cerveau
	g1(rd()), uni1(0.0,1.0), uni2( 0.0 , 2*3.141592 ) //initialisation du générateur de nombre aléatoire et des distributions
{

	for (int i=0;i<size;i++){
		Angle.push_back(uni2(g1)); // on rempli le cerveau avec des angles et des commande de gaz aléatoire
		Throttle.push_back(uni1(g1));
	}
	
}

brain brain::clone(){ // ancienne fonciton qui est remplacé par un constructeur copieur mais conservé pour la rétrocomptabilité (normalement elle pourrait être supprimer)

	brain clone(Angle.size());
	for (long unsigned int i = 0; i< Angle.size(); i++){
		clone.Angle.at(i)=Angle.at(i);
		clone.Throttle.at(i)=Throttle.at(i);
	}
	return clone;

	
}


brain::brain(const brain & b): // constructeur copieur 
	g1(rd()), uni1(0.0,1.0), uni2( 0.0 , 2*3.141592 )
{
	
	for (long unsigned int i = 0; i< b.Angle.size(); i++){
		Angle.push_back(b.Angle.at(i));
		Throttle.push_back(b.Throttle.at(i));
	}
}


brain& brain::operator=(const brain& b) // définition du =  car il semblait qu'il ne soit pas bien définit en réalité c'est la vérification des modifications du makefile qui ne fonctionnait pas bien et qui nous a causé des erreures imprévue
{
	
	for (long unsigned int i = 0; i< b.Angle.size(); i++){
		Angle.push_back(b.Angle.at(i));
		Throttle.push_back(b.Throttle.at(i));
	}
	return *this;
}


void brain::mutation(){ // on modifie 1% des angles et des commande de gaz aléatoirement
	
	float ratioMutation = 0.01;
	for (long unsigned int i=0; i<Angle.size();i++){	
		long double rand = uni1(g1);
		if (rand < ratioMutation){
			Throttle.at(i)= uni1(g1);
		}
	}
	for (long unsigned int i=0; i<Angle.size();i++){	
		long double rand = uni1(g1);
		if (rand < ratioMutation){
			Angle.at(i)= uni1(g1);
		}
	}

}

