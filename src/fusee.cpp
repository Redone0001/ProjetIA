#include "../include/ordinateurDeBord.h"
#include "../include/brain.h"
#include "../include/module.h"
#include "../include/save.h"
#include "../include/fusee.h"
#include <vector>
#include <math.h>

using namespace std;

fusee::fusee(int Gen, int BrainSize):Brain(BrainSize), gen(Gen) {
	
	//initialisationCSV("gen_"+to_string(gen));
	module soyuz(6930,70,0,2.86,0,0);
	module etage1(6500,205000,1200000,3.42,350,0);
	module etage2(2250,252000,400000,2.78,105,0);
	lanceurVec.push_back(soyuz);
	lanceurVec.push_back(etage2);
	lanceurVec.push_back(etage1);
	for (int i=0;i<4; i++){
		module booster(3500,44000,1200000,2.82,333.33,0);
		lanceurVec.push_back(booster);
	}
	for(int i = 3;i<7;i++){
		lanceurVec.at(i).throttle=1;
	}
	lanceurVec.at(2).throttle=1;
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
		//cout<<"test0"<<endl;
		int step = t/15;
		if(lanceurVec.size()==3){
			throttleGeneral = 2;
		}
		else if(lanceurVec.size()==2){
			throttleGeneral = 1;
		}
		else if(lanceurVec.size()==1){
			throttleGeneral = 0;
			
		}
		//cout<<"test1"<<endl;
		int longeur = Brain.Angle.size();
		bool test = step < longeur;
		//cout <<test<<endl;
		if (test){
			if (throttleGeneral == 0)
				Brain.Throttle.at(step)=0;
			ENIAC.angle = Brain.Angle.at(step);
			lanceurVec.at(throttleGeneral).throttle=Brain.Throttle.at(step);
		}
		//cout<<"test2"<<endl;
		ENIAC.sumForce(lanceurVec);
		long double masse = ENIAC.checkMasse(lanceurVec);
		ENIAC.updateMouv(0.1,masse);
		//cout<<"test2"<<endl;
		if(sqrt(pow(ENIAC.position.first,2)+pow(ENIAC.position.second,2))<6370990){
			vivant=false;
			//cout <<"dead"<<endl;;
		}
		/*if((sqrt(pow(ENIAC.position.first,2)+pow(ENIAC.position.second,2))>6571000) & (sqrt(pow(ENIAC.position.first,2)+pow(ENIAC.position.second,2))<6971000)){
			fit++;
		}*/
	}

}
void fusee::calculFitness(){
	//cout <<fit <<endl;
	//fit= fit*ENIAC.checkMasse(lanceurVec)/10000;
	fit = (sqrt(pow(ENIAC.position.first,2)+pow(ENIAC.position.second,2))-6371000);
}

fusee fusee::gimmeBaby(){
	fusee baby(gen+1, Brain.Angle.size());
// brain deuxiemeEssai(premierEssai);
// brain deuxiemeEssai = premierEssai.clone();
	baby.Brain = brain(Brain);//.clone();
	return baby;

}

