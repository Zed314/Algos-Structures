#include <iostream>
#include "File.h"
using namespace std;

void File::AffichageFile()
{
	if(EstVide())
	{
	
		cout<<"La file est vide"<<endl;
	
	}
	else
	{
		ElementFile * elementEnCours=this->debut;
		while(elementEnCours!=nullptr)
		{
			cout<<elementEnCours->val<<",";
			elementEnCours=elementEnCours->suivant;
		}
		cout<<"FIN FILE"<<endl;
	}
}
void File::Enfile(typeFile elementAEnfiler)
{
	ElementFile * nouvelElementFile= new ElementFile;
	nouvelElementFile->val=elementAEnfiler;
	nouvelElementFile->suivant=nullptr;
	if(EstVide())
	{
		this->debut=nouvelElementFile;
		this->fin=nouvelElementFile;
		
	}
	else
	{
		this->fin->suivant=nouvelElementFile;
		this->fin=nouvelElementFile;
	}
	
	
}
typeFile File::Defile()
{
	if(EstVide())
	{
		return 0;
	}
	typeFile aRetourner=this->debut->val;
	ElementFile * nouveauDebut=this->debut->suivant;
	delete this->debut;
	this->debut=nouveauDebut;
	if(nouveauDebut==nullptr)
	{
		this->fin=nullptr;
	}
	return aRetourner;
	
}
bool File::EstVide()
{
	if(this->debut==nullptr ||this->fin==nullptr  )
	{
		return true;
	}
	return false;
}
File::File():debut(nullptr),fin(nullptr)
{
	#ifdef MAP_FILE
	cout<<"Appel au constructeur de File.."<<endl;
	#endif
}

File::~File()
{
	#ifdef MAP_FILE
	cout<<"Appel au destructeur de File.."<<endl;
	#endif
	while(debut!=nullptr)
	{
		Defile();
	}

}
File::File(const File &fileACopier)
{
	#ifdef MAP_FILE
	cout<<"Appel au constructeur de copie de File.."<<endl;
	#endif
	
	//Todo
}