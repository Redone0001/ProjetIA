#include <iostream>
#include <fstream>
#include <string>

void initialisationCSV(std::string fileName){
	std::ofstream fs(fileName);
	fs<<"t,x,y\n";
	fs.close();

}
void saveToCSV(std::string fileName, ordinateurDeBord ENIAC, long double t){
	std::ofstream fs (fileName, std::fstream::app);
	fs <<t<<","<<ENIAC.position.first<<","<<ENIAC.position.second<<"\n";
	fs.close();
}
