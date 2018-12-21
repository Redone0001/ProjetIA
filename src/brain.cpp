#include "../include/brain.h"

using namespace std;

brain::brain(int size){

	for (int i=0;i<size();i++){
		Angle.push_back(uni2(gen2));
		Throttle.push_back(uni1(gen1));
	}
	
}

brain brain::clone(){

	brain clone(Angle.size());
	for (int i = 0; i< Angle.size(); i++){
		clone.Angle.at(i)=Angle.at(i);
		clone.Throttle.at(i)=Throttle.at(i);
	}

	
}

void brain::mutation(){
	
	float ratioMutation = 0.05;
	for (int i=0; i<Angle.size();i++){	
		long double rand = uni1(gen1);
		if (rand < ratioMutation){
			Throttle.at(i)= uni1(gen1);
		}
	}
	for (int i=0; i<Angle.size();i++){	
		long double rand = uni1(gen1);
		if (rand < ratioMutation){
			Angle.at(i)= uni2(gen2);
		}
	}

}

