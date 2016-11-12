#ifndef TasBinaire_h
#define TasBinaire_h
#include <iostream>
#define MAP



class TasBinaire
{
	public:
	void Ajuster(int delta);
	void SupprimerTete();
	bool AjouterElement(int valAAjouter);
	void AfficherTas();
	TasBinaire(unsigned int taille=10,int * tabInitialisation=nullptr);
	~TasBinaire();
	private:
	void inverser(int &a,int &b);
	int * tas;
	unsigned int tailleTas;
	unsigned int tailleMax;

};
#endif
