#include "../include/population.h"
#include <random>
using namespace std;
/*

Ceci est le coeur de l'IA que j'ai voulu implémenté mais elle ne doit pas encore être utilisée

le projet sera encore mis à jour dans le futur et ces commentaires seront modifiés

*/
Population::Population(int size, int BrainSize):taille(size),BestFusee(0),Generation(0){
		
	for(int i=0;i<taille;i++){
		Fusee.push_back(fusee(0,BrainSize));
	}
	initialisationCSV("save"+to_string(Generation)+".csv");
}


void Population::NextStep(long double t){
	for (int i = 0;i<taille;i++){
		Fusee.at(i).nextStep(t);
	}
	saveToCSV("save"+to_string(Generation)+".csv",Fusee.at(0).ENIAC,t);
	
}
void Population::CalculFit(){
	SumFit=0;
	for (int i =0;i<taille;i++){
		Fusee.at(i).calculFitness();
		SumFit+=Fusee.at(i).fit;
	}
}
bool Population::allDead(){
	for (int i =0;i<taille;i++){
		if (Fusee.at(i).vivant)
			return false;
	}
	cout <<"tous mort"<<endl;
	return true;
}

fusee Population::selectionParent(){
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution < long double > uni ( 0.0 , SumFit );

	long double rand = uni(gen);
	long double sommeEnCours=0;

	for (int i = 0; i<taille;i++){
		sommeEnCours+=Fusee.at(i).fit;
		if(sommeEnCours>rand)
			return Fusee.at(i);
	}
	cout<<"bug dans la selection des parents ne pas continuer la simulation"<<endl;
	return Fusee.at(0);

}

void Population::darwinPlay(){
	vector <fusee> NewGen(Fusee);
	int bestOne = FindBestOne();
	NewGen.at(0)=Fusee.at(bestOne);
	for (int i =1; i<taille;i++){
		fusee maman(selectionParent());
		NewGen.at(i)= maman.gimmeBaby();
	}
	Fusee= NewGen;
	Generation++;
}

void Population::mutation(){

	for (int i = 1; i< taille;i++){
		Fusee.at(i).Brain.mutation();
		Fusee.at(i).vivant=true;

	}

}


int Population::FindBestOne(){
	long double max=0;

	int maxIndex =0;

	for(int i = 0;i<taille;i++){
		if (Fusee.at(i).fit>max){
			max = Fusee.at(i).fit;
			maxIndex = i;
		}
	}
	return maxIndex;

}
