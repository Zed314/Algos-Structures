#include <iostream>
#include "Abr.h"
#include "File.h"
using namespace std;

void Abr::AffichageLargeur(Arbre * depart)
{
	if(depart==nullptr)
	{
		depart=this->racine;
	}
	if(depart==nullptr)
	{
		cout<<"L'arbre est vide!"<<endl;
	}
	else
	{
		File file;
		Arbre * elementEnCours=depart;
		file.Enfile(elementEnCours);
		while(!file.EstVide())
		{
			elementEnCours=file.Defile();
			cout<<elementEnCours->val<<endl;
			if(elementEnCours->gauche!=nullptr)
			{
				cout<<"\tGauche"<<"->"<<elementEnCours->gauche->val<<endl;
				file.Enfile(elementEnCours->gauche);
			}	
			if(elementEnCours->droite!=nullptr)
			{
				cout<<"\tDroite"<<"->"<<elementEnCours->droite->val<<endl;
				file.Enfile(elementEnCours->droite);
			}	
		}
		cout<<endl;
	}
	
}
bool Abr::AjouterVal(int valAAjouter)
{

	if(racine==nullptr)
	{
			racine=new Arbre;
			racine->val=valAAjouter;
			racine->gauche=nullptr;
			racine->droite=nullptr;
			
			return true;
	}
	else
	{
		Arbre * precedent;
		Arbre * elementEnCours=racine;
		while(elementEnCours!=nullptr && elementEnCours->val!=valAAjouter)
		{
			precedent=elementEnCours;
			if(elementEnCours->val>valAAjouter)//Si la valeur à ajouter est plus petite
			{
				elementEnCours=elementEnCours->gauche;
			}		
			else
			{
				elementEnCours=elementEnCours->droite;
			}
		}
		if(elementEnCours==nullptr)
		{
			Arbre * ajout=new Arbre;
			ajout->gauche=nullptr;
			ajout->droite=nullptr;
			ajout->val=valAAjouter;
			if(precedent->val>valAAjouter)//Si on a tourné à gauche en dernier
			{
				precedent->gauche=ajout;
			}
			else
			{
				precedent->droite=ajout;
			}
			return true;
		}
		else
		{
			return false;
		}
	}

}
Abr::Abr()
{
	racine=nullptr;//arbre vide
	
}
Abr::~Abr()
{
	//Todo
}
Abr::Abr(const Abr &ArbreACopier)
{
	//Todo Either
}