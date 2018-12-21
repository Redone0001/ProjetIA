class fusee{

brain Brain;

int gen;
int throttleGeneral = 3;
bool Vivant;
float fit;

vector <module> lanceurVec;
module soyuz(6999,1,0,2.86,0,0);
module etage1(6500,105000,1000000,3.42,350,0);
module etage2(2250,25200,300000,2.78,105,0);
lanceurVec.push_back(soyuz);
lanceurVec.push_back(etage2);
lanceurVec.push_back(etage1);
for (int i=0;i<4; i++){
	module booster(3500,40000,1000000,2.82,333.33,0);
	lanceurVec.push_back(booster);
}
ordinateurDeBord ENIAC;



nextStep(long double t);







};
