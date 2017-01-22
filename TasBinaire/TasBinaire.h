#ifndef TasBinaire_h
#define TasBinaire_h
#include <iostream>
#define MAP


template <class T>
class TasBinaire
{
	public:
	void Ajuster(T delta);
	void SupprimerTete();
	bool AjouterElement(T valAAjouter);
	void AfficherTas();
	TasBinaire(unsigned int taille=10,T * tabInitialisation=nullptr);
	TasBinaire(const TasBinaire<T> &tasACopier);
	~TasBinaire();
	private:
	void inverse(T &a,T &b);
	T * tas;
	unsigned int tailleTas;
	unsigned int tailleMax;

};
#include "TasBinaire.tpp"
#endif
