#include "TasBinaire.h"
#include <iostream>
using namespace std;
void inverse(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
void TasBinaire::SupprimerTete()
{
	if(tailleTas!=0)
	{
		
		tas[0]=tas[tailleTas-1];
		tailleTas--;
		bool finish=false;
		int i=0;
		while(!finish)
		{
			if(2*i+2<tailleTas)//Si il a deux fils
			{
				if(tas[i]>tas[2*i+1])
				{
					if(tas[i]>tas[2*i+2])
					{
						finish=true;
					}
					else
					{
						inverse(tas[2*i+2],tas[i]);
						i=2*i+2;
					}
				}
				else//pere plus petit que l'un de ses fils
				{
					if(tas[2*i+1]>tas[2*i+2])//Fils gauche plus grand que le droit
					{
						inverse(tas[2*i+1],tas[i]);
						i=2*i+1;
					}
					else
					{
						inverse(tas[2*i+2],tas[i]);
						i=2*i+2;
					}
				}
				
			}
			else if(2*i+1<tailleTas)//Un fils, obligatoirement le gauche
			{
				if(tas[2*i+1]>tas[i])
				{
					inverse(tas[2*i+1],tas[i]);
					finish=true;//La structure du tas nous indique que nous avons terminé
				}
				else
				{
					finish=true;
				}
			}
			else //Aucun fils
			{
				finish=true;
			}
		}
	}
	
}
void TasBinaire::Ajuster(int delta)
{
	if(delta!=0)
	{
	
		if(delta<0)
		{
			if(-delta>(this->tailleMax-this->tailleTas))
			{
				int tempTailleMax=this->tailleMax;
				delta=this->tailleTas-tempTailleMax;
			}
		}
		int * newTas=new int[tailleMax+delta];
		for(unsigned int i=0;i<this->tailleTas;i++)
		{
			newTas[i]=tas[i];
		}
		delete[] tas;
		tailleMax+=delta;
		tas=newTas;
	}
	
	
}
bool TasBinaire::AjouterElement(int valAAjouter)
{
	if(tailleTas==tailleMax)
	{
		return false;
	}
	tas[tailleTas]=valAAjouter;
	int i=tailleTas;//Pas unsigned int pour éviter les soucis avec le calcul du père
	int temp;
	while(i>0&&tas[i]>tas[(i-1)/2])
	{	
		temp=tas[i];
		tas[i]=tas[(i-1)/2];
		tas[(i-1)/2]=temp;
		i=(i-1)/2;
	}
	
	tailleTas++;
	return true;
}
void TasBinaire::AfficherTas()
{
	cout<<"La taille du tas est de "<<tailleTas<<endl;
	cout<<"La taille allouée est de "<<tailleMax<<endl;
	if(tailleTas!=0)
	{
	
		for(unsigned int i=0;i<this->tailleTas;i++)
		{
			cout<<tas[i];
			if(i!=this->tailleTas-1)
			{
				cout<<",";
			}
		}
	}
	else
	{
		cout<<"Le tas est vide..";
	}
	cout<<endl;
	
}
TasBinaire::TasBinaire(unsigned int taille,int *tabInit):tailleMax(taille)
{
	#ifdef MAP
	cout<<"Appel au constructeur de TasBinaire.."<<endl;
	#endif
	tailleTas=0;
	tas = new int[tailleMax];
	if (tabInit!=nullptr)
	{

		unsigned int i;
		for(i=0;i<taille;i++)
		{
			
			AjouterElement(tabInit[i]);
			
		}
	}
	
}
TasBinaire::~TasBinaire()
{
	#ifdef MAP
	cout<<"Appel au déstructeur de TasBinaire.."<<endl;
	#endif
	delete[] tas;
	
}
