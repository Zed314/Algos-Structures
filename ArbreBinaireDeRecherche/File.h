#ifndef FILE_H
#define FILE_H
#include "Abr.h"
#define MAP_FILE
//class Abr;
typedef Arbre* typeFile;
//typedef int typeFile;
typedef struct elementFile
{
	typeFile val;
	elementFile * suivant;
	
} ElementFile;

class File
{
	public:
	void AffichageFile();
	bool EstVide();
	typeFile Defile();
	//Renvoie l'élément retiré
	//Si la file est vide, renvoie 0
	//Comme le type de File peut-être varié, penser à vérifier si la file est vide avant de defiler
	void Enfile(typeFile elementAEnfiler);
	File();
	~File();
	File(const File & fileACopier);
	private:
	ElementFile * debut;
	ElementFile * fin;


};




#endif