#include "include/ordinateurDeBord.h"
#include "include/module.h"
#include "include/brain.h"
#include "include/fusee.h"
#include "include/population.h"
#include "include/save.h"
#include <vector>

using namespace std;


int main(){

	Population Batch(100);
	for (int i = 0; i<Batch.Fusee.at(0).Brain.Angle.size();i++){
		if (i<120)
			Batch.Fusee.at(0).Brain.Angle.at(i) = 3.141592/2;
		else 
			Batch.Fusee.at(0).Brain.Angle.at(i) = 0;
	}
	cout <<"angle fait"<<endl;
	for (int i = 0; i<Batch.Fusee.at(0).Brain.Throttle.size();i++){
		Batch.Fusee.at(0).Brain.Throttle.at(i) = 1;
	}
	cout <<"power fait"<<endl;
	for (double long t = 0; t <300*60; t+=0.1){
		if (Batch.allDead()){
			cout <<"batch"<<endl;
			Batch.CalculFit();
			Batch.darwinPlay();
			Batch.mutation();
		}
		else{
			cout <<"step : " << t<<endl;
			Batch.NextStep(t);

		}
	}
}
