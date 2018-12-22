#include "include/ordinateurDeBord.h"
#include "include/module.h"
#include "include/brain.h"
#include "include/fusee.h"
#include "include/population.h"
#include "include/save.h"
#include <vector>

using namespace std;


int main(){

	Population Batch(10);
	ofstream fs("tempsDeVolMax.csv");
	fs<<"Gen,Temps max\n";
	fs.close();
	for (int j = 0; j<Batch.taille;j++){
		for (long unsigned int i = 0; i<Batch.Fusee.at(j).Brain.Angle.size();i++){
			if (i<120/15)
				Batch.Fusee.at(j).Brain.Angle.at(i) = 3.141592/2;
			else 
				Batch.Fusee.at(j).Brain.Angle.at(i) = 0;
		}
		for (long unsigned int i = 0; i<Batch.Fusee.at(0).Brain.Throttle.size();i++){
			Batch.Fusee.at(0).Brain.Throttle.at(i) = 1;
		}
	}
	long double t = 0;
	while (t<120*60){
		if (Batch.allDead()){
			Batch.CalculFit();
			Batch.darwinPlay();
			Batch.mutation();
			ofstream fs ("tempsDeVolMax.csv",fstream::app);
			fs <<Batch.Generation<<","<<t<<"\n";
			fs.close();
			t=0;
		}
		else{
			cout <<"step : " << t <<" et gen : " << Batch.Generation<<endl;
			Batch.NextStep(t);
		}
	t+=0.1;
	}
}
