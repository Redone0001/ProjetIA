#include "../include/ordinateurDeBord.h"
#include "../include/brain.h"
#include "../include/module.h"
#include "../include/save.h"
#include "../include/fusee.h"
#include <vector>
#include <math.h>

using namespace std;

fusee::fusee(int Gen):Brain(300*60/15), gen(Gen) {
	
	//initialisationCSV("gen_"+to_string(gen));
	module soyuz(6930,70,0,2.86,0,0);
	module etage1(6500,105000,1100000,3.42,350,0);
	module etage2(2250,25200,330000,2.78,105,0);
	lanceurVec.push_back(soyuz);
	lanceurVec.push_back(etage2);
	lanceurVec.push_back(etage1);
	for (int i=0;i<4; i++){
		module booster(3500,40000,1200000,2.82,333.33,0);
		lanceurVec.push_back(booster);
	}
	for(int i = 3;i<7;i++){
		lanceurVec.at(i).throttle=1;
	}
	lanceurVec.at(2).throttle=1;
	
//	brain Brain(5*60);
	vivant = true;
	fit =0;
}
void fusee::nextStep(long double t){
	if(vivant){
		for (unsigned int moduleId = 0; moduleId < lanceurVec.size(); moduleId++){
			bool test = ENIAC.checkCarburant(lanceurVec.at(moduleId));
			if (test && (lanceurVec.size()!=1))
				lanceurVec.erase(lanceurVec.begin()+moduleId);
			else
				ENIAC.updateCarburant(lanceurVec.at(moduleId));
		
		}
		int step = t/15;
		if(lanceurVec.size()==3){
			throttleGeneral = 2;
		}
		else if(lanceurVec.size()==2){
			throttleGeneral = 1;
		}
		else if(lanceurVec.size()==1){
			throttleGeneral = 0;
			Brain.Throttle.at(step)=0;
		}
		
		
		ENIAC.updateAngle(Brain.Angle.at(step));
		lanceurVec.at(throttleGeneral).throttle=Brain.Throttle.at(step);
		ENIAC.sumForce(lanceurVec);
		long double masse = ENIAC.checkMasse(lanceurVec);
		ENIAC.updateMouv(0.1,masse);
		if(sqrt(pow(ENIAC.position.first,2)+pow(ENIAC.position.second,2))<6370990){
			vivant=false;
			cout <<"dead"<<endl;;
		}
		if((sqrt(pow(ENIAC.position.first,2)+pow(ENIAC.position.second,2))>6571000) & (sqrt(pow(ENIAC.position.first,2)+pow(ENIAC.position.second,2))<6971000)){
			fit++;
		}
	}

}
void fusee::calculFitness(){
	cout <<fit <<endl;
	fit= fit*ENIAC.checkMasse(lanceurVec)/10000;
}

fusee fusee::gimmeBaby(){
	fusee baby(gen+1);
// brain deuxiemeEssai(premierEssai);
// brain deuxiemeEssai = premierEssai.clone();
	baby.Brain = brain(Brain);//.clone();
	return baby;

}

