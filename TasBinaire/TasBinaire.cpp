#include "TasBinaire.h"
#include <iostream>
using namespace std;
TasBinaire::TasBinaire(unsigned int taille,int *tabInit):tailleMax(taille),tailleTas(taille)
{
	#ifdef MAP
	cout<<"Appel au constructeur de TasBinaire.."<<endl;
	#endif
	tas = new int[taille];
	if (tabInit!=nullptr)
	{

		unsigned int i;
		for(i=0;i<taille;i++)
		{
			tas[i]=tabInit[i];
		}
	}
}
TasBinaire::~TasBinaire()
{
	#ifdef MAP
	cout<<"Appel au déstructeur de TasBinaire.."<<endl;
	#endif
	
}
