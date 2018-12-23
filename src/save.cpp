#include "../include/save.h"

//enregistre nos données dans un dossier CSV avec comme première colonne le temps et comme deuxième et troisième colonne la position dans l'axe x (horizontal) et y (vertical), dans le repère fixe lié au centre de la terre et alligné par rapport à la fusée au décolage  

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
