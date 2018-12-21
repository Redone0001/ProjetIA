#pragma once
#include <vector>
#include <random>
#include <chrono>

class brain{
public:
	std::vector <long double> Angle;
	std::vector <long double> Throttle;
	
	std::random_device rd;


	std::mt19937 g1;
	std::uniform_real_distribution < long double > uni1;// ( 0.0 , 1.0 );   
	std::uniform_real_distribution < long double > uni2;// ( 0.0 , 2*3.141592 );  

	brain(int);
	brain(const brain & b);
	brain& operator=(const brain & b);
	brain clone();
	void mutation();

};
