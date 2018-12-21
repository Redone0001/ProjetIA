#include "../include/brain.h"

using namespace std;

brain::brain(int size):
	g1(rd()), uni1(0.0,1.0), uni2( 0.0 , 2*3.141592 )
{

	for (int i=0;i<size;i++){
		Angle.push_back(uni1(g1));
		Throttle.push_back(uni1(g1));
	}
	
}

brain brain::clone(){

	brain clone(Angle.size());
	for (long unsigned int i = 0; i< Angle.size(); i++){
		clone.Angle.at(i)=Angle.at(i);
		clone.Throttle.at(i)=Throttle.at(i);
	}
	return clone;

	
}


// brain deuxiemeEssai(premierEssai);
// brain deuxiemeEssai = premierEssai.clone();

brain::brain(const brain & b):
	g1(rd()), uni1(0.0,1.0), uni2( 0.0 , 2*3.141592 )
{
	
	for (long unsigned int i = 0; i< b.Angle.size(); i++){
		Angle.push_back(b.Angle.at(i));
		Throttle.push_back(b.Throttle.at(i));
	}
}


brain& brain::operator=(const brain& b)
{
	
	for (long unsigned int i = 0; i< b.Angle.size(); i++){
		Angle.push_back(b.Angle.at(i));
		Throttle.push_back(b.Throttle.at(i));
	}
	return *this;
}


void brain::mutation(){
	
	float ratioMutation = 0.05;
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

