#ifndef ABR_H
#define ABR_H


typedef struct arbre
{
	int val;
	arbre * droite;
	arbre * gauche;
} Arbre;

class Abr
{
	public:
	bool RetirerElement(Arbre * elementARetirer=nullptr,Arbre * pereElementARetirer=nullptr);
	//Retire l'élément pointé de l'arbre binaire de recherche
	//Si le père est inconnu, on retire la racine
	//Si rien n'est spécifié, on retire la racine
	//Si l'arbre est vide, renvoie false et true sinon
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