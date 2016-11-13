#include <iostream>
#include "Abr.h"
#include "File.h"
using namespace std;

bool Abr::RetirerElement(Arbre * elementARetirer,Arbre * pereElementARetirer)
{
	if(pereElementARetirer==nullptr)
	{
		elementARetirer=this->racine;
		
	}
	if(elementARetirer!=nullptr)
	{
		if(elementARetirer->gauche==nullptr&&elementARetirer->droite==nullptr)
		{
			
			if(pereElementARetirer!=nullptr)
			{
				if(pereElementARetirer->gauche==elementARetirer)
				{
					pereElementARetirer->gauche=nullptr;
				}
				else
				{
					pereElementARetirer->droite=nullptr;
				}
			}
			else
			{
				this->racine=nullptr;
			}
			delete elementARetirer;
			
		}
		else if(elementARetirer->gauche==nullptr)
		{
			//On greffe le droite
			Arbre * tempDroite=elementARetirer->droite;
			elementARetirer->val=elementARetirer->droite->val;
			elementARetirer->gauche=elementARetirer->droite->gauche;
			elementARetirer->droite=elementARetirer->droite->droite;
			delete tempDroite;
			
		}
		else if(elementARetirer->droite==nullptr)
		{
			Arbre * tempGauche=elementARetirer->gauche;
			elementARetirer->val=elementARetirer->gauche->val;
			elementARetirer->gauche=elementARetirer->gauche->gauche;
			elementARetirer->droite=elementARetirer->gauche->droite;
			delete tempGauche;
		}
		else
		{
				//On écrase avec le plus a droite de celui à gauche
				Arbre * elementEnCours=elementARetirer->gauche;
				Arbre * precedent=elementARetirer;
				while(elementEnCours->droite!=nullptr)
				{
					precedent=elementEnCours;
					elementEnCours=elementEnCours->droite;
				}
				if(precedent==elementARetirer)
				{
							Arbre * tempGauche=elementARetirer->gauche;
							elementARetirer->val=elementARetirer->gauche->val;
							elementARetirer->gauche=elementARetirer->gauche->gauche;
							delete tempGauche;
				}
				else
				{
					
					elementARetirer->val=elementEnCours->val;
					precedent->droite=elementEnCours->gauche;
					delete elementEnCours;
					
				}
				
		}
	}
	else
	{
		return false;
	//	cout<<"L'arbre est vide! Il est impossible de retirer des elements."<<endl;
	}
	return true;
}

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
	while(RetirerElement())
	{
		//bloc vide
	}
	
}
Abr::Abr(const Abr &ArbreACopier)
{
	//Todo Either
}