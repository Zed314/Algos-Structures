
#include <iostream>

using namespace std;

template <typename T>
void TasBinaire<T>::inverse(T &a,T &b)

{
	T temp=a;
	a=b;
	b=temp;
}
template <typename T>
void TasBinaire<T>::SupprimerTete()
{
	if(tailleTas!=0)
	{
		
		tas[0]=tas[tailleTas-1];
		tailleTas--;
		bool finish=false;
		unsigned int i=0;
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
template <typename T>
void TasBinaire<T>::Ajuster(T delta)
{
	if(delta!=0)
	{
	
		if(delta<0)
		{
			int tempTailleMaxMoinsTaille=this->tailleMax-this->tailleTas;
			if(-delta>(tempTailleMaxMoinsTaille))
			{
				delta=-tempTailleMaxMoinsTaille;
			}
		}
		T * newTas=new T[tailleMax+delta];
		for(unsigned int i=0;i<this->tailleTas;i++)
		{
			newTas[i]=tas[i];
		}
		delete[] tas;
		tailleMax+=delta;
		tas=newTas;
	}
	
	
}
template <typename T>
bool TasBinaire<T>::AjouterElement(T valAAjouter)
{
	if(tailleTas==tailleMax)
	{
		return false;
	}
	tas[tailleTas]=valAAjouter;
	T i=tailleTas;//Pas unsigned int pour éviter les soucis avec le calcul du père
	T temp;
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
template <typename T>
void TasBinaire<T>::AfficherTas()
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
template <typename T>
TasBinaire<T>::TasBinaire(const TasBinaire<T> & tasACopier)//:tailleMax(tasACopier.tailleMax),tailleTas(tasACopier.tailleTas)
{
	#ifdef MAP
	cout<<"Appel au constructeur de copie de TasBinaire.."<<endl;
	#endif
	this->tailleMax=tasACopier.tailleMax;
	this->tailleTas=tasACopier.tailleTas;
//:tailleMax(tasACopier.tailleMax),tailleTas(tasACopier.tailleTas)
	this->tas= new T[tasACopier.tailleMax];
	for(unsigned int i=0;i<tasACopier.tailleTas;i++)
	{
		this->tas[i]=tasACopier.tas[i];
	}
	
}
template <typename T>
TasBinaire<T>::TasBinaire(unsigned int taille,T *tabInit):tailleMax(taille)
{
	#ifdef MAP
	cout<<"Appel au constructeur de TasBinaire.."<<endl;
	#endif
	tailleTas=0;
	tas = new T[tailleMax];
	if (tabInit!=nullptr)
	{

		unsigned int i;
		for(i=0;i<taille;i++)
		{
			
			AjouterElement(tabInit[i]);
			
		}
	}
	
}
template <typename T>
TasBinaire<T>::~TasBinaire()
{
	#ifdef MAP
	cout<<"Appel au destructeur de TasBinaire.."<<endl;
	#endif
	delete[] tas;
	
}
