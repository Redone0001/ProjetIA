#include <vector>
#include <random>
#include <chrono>

class brain{

std::vector <long double> Angle;
std::vector <long double> Throttle;

unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();

std::mt19937 g1 (seed1);
std::uniform_real_distribution < float > uni1 ( 0.0 , 1.0 );   

unsigned seed2 = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 g1 (seed2);
std::uniform_real_distribution < float > uni2 ( 0.0 , 2*3.141592 );  

brain(int);
brain clone();
void mutation();

};
