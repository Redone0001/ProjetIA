#include "include/ordinateurDeBord.h"
#include "include/module.h"
#include "include/save.h"
#include <vector>
#include <math.h>

using namespace std;

fusee::lancement(int Gen):gen(Gen){
	
	initialisationCSV("gen_"+to_string(gen));
	
	for(int i = 3;i<7;i++){
		lanceurVec.at(i).throttle=1;
	}
	lanceurVec.at(2).throttle=1;
	
	brain Brain(5*60);
	vivant = true;
	fit =0;
}
void fusee::nextStep(long double t){
	if(vivant){
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
			//lanceurVec.at(2).throttle=1;
			throttleGeneral = 2;
		}
		else if(lanceurVec.size()==2){
			//cout<<"séparation du 1er étage"<<endl;
			//lanceurVec.at(1).throttle=1;
			throttleGeneral = 1;
		}
		else if(lanceurVec.size()==1){
			//cout<<"séparation du 2eme étage"<<endl;
		}
		//cout <<"test2"<<endl;
		int step = t;
		ENIAC.updateAngle(Brain.Angle.at(step));
		lanceurVec.at(throttleGeneral).throttle=Brain.Throttle.at(step);
		//cout <<"test3"<<endl;
		ENIAC.sumForce(lanceurVec);
		long double masse = ENIAC.checkMasse(lanceurVec);
		//cout <<masse<<endl;
		ENIAC.updateMouv(deltaT,masse);
		saveToCSV("save.csv",ENIAC,t);
		if(sqrt(pow(ENIAC.position.first,2)+pow(ENIAC.position.second,2))<6370990){
			vivant=false
		}
		if(sqrt(pow(ENIAC.position.first,2)+pow(ENIAC.position.second,2))>6571000 & sqrt(pow(ENIAC.position.first,2)+pow(ENIAC.position.second,2))<6971000){
			fit++;
		}
	}

}
void fusee::calculFitness(){
	fit= fit*Eniac.checkMasse(lanceurVec);
}

fusee fusee::grimmmeBaby(){
	fusee baby();
	baby.Brain = Brain.clone();
	return baby;

}

