#include "../include/module.h"
using namespace std;

module::module(long double Masse,long double Carburant, long double power, long double SurfaceFrot, long double conso, long double modulationPuissance): masse(Masse), carburant(Carburant), puissance(power), surfaceFrot(SurfaceFrot), consomation(conso), throttle(modulationPuissance){}

module::~module(){}


