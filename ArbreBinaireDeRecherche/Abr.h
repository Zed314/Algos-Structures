#ifndef ABR_H
#define ABR_H


typedef struct arbre
{
	int val;
	arbre * droite;
	arbre * gauche;
}Arbre;

class Abr
{
	public:
	void AffichageLargeur(Arbre * depart=nullptr);
	bool AjouterVal(int valAAjouter);
	//Ajoute un element si il n'est pas déjà dans l'arbre
	//Renvoie true si l'ajout a été fait, false sinon
	Abr();
	~Abr();
	Abr(const Abr & ArbreACopier);
	
	private:
	
	Arbre * racine;
	
};

#endif