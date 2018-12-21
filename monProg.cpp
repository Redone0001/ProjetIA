#include "include/ordinateurDeBord.h"
#include "include/module.h"
#include "include/save.h"
#include <vector>

using namespace std;


int main(){
//initialisation 
	vector <module> lanceurVec;
	module soyuz(6999,1,0,2.86,0,0);
	module etage1(6500,105000,1000000,3.42,350,0);
	module etage2(2250,25200,300000,2.78,105,0);
	lanceurVec.push_back(soyuz);
	lanceurVec.push_back(etage2);
	lanceurVec.push_back(etage1);
	for (int i=0;i<4; i++){
		module booster(3500,40000,1000000,2.82,333.33,0);
		lanceurVec.push_back(booster);
	}
	ordinateurDeBord ENIAC;
//vol
	initialisationCSV("save.csv");
	long double deltaT = 0.1;
	long double t = 0;
	for(int i = 3;i<7;i++){
		lanceurVec.at(i).throttle=1;
	}
	lanceurVec.at(2).throttle=1;
	while(t<=(5*60)){
		//cout <<"test"<<endl;

		for (unsigned int moduleId = 0; moduleId < lanceurVec.size(); moduleId++){
			bool test = ENIAC.checkCarburant(lanceurVec.at(moduleId));
			if (test)
				lanceurVec.erase(lanceurVec.begin()+moduleId);
			else
				ENIAC.updateCarburant(lanceurVec.at(moduleId));
			
		}
		if(lanceurVec.size()==3){
			//cout <<"les boosters ont été largué"<<endl;
			//on doit passer l'étage 1 à 100%
			lanceurVec.at(2).throttle=1;
		}
		else if(lanceurVec.size()==2){
			//cout<<"séparation du 1er étage"<<endl;
			lanceurVec.at(1).throttle=1;
		}
		else if(lanceurVec.size()==1){
			//cout<<"séparation du 2eme étage"<<endl;
		}
		//cout <<"test2"<<endl;
		ENIAC.updateAngle(t);
		//cout <<"test3"<<endl;
		ENIAC.sumForce(lanceurVec);
		long double masse = ENIAC.checkMasse(lanceurVec);
		//cout <<masse<<endl;
		ENIAC.updateMouv(deltaT,masse);

		saveToCSV("save.csv",ENIAC,t);

		t+= deltaT;

	}
	for(auto & x : lanceurVec){
		x.throttle=0;
	}

	while(t<=(450*60)){
	ENIAC.sumForce(lanceurVec);
	long double masse = ENIAC.checkMasse(lanceurVec);
	ENIAC.updateMouv(deltaT,masse);
	saveToCSV("save.csv",ENIAC,t);	
	t+= deltaT;
	}
	

}
