#include <iostream>
#include "Abr.h"


using namespace std;
void testCopie()
{
	Abr a;
	a.AjouterVal(10);
	a.AjouterVal(20);
	a.AjouterVal(30);
	a.AjouterVal(40);
	a.AjouterVal(5);
	a.AffichageLargeur();
	{
		Abr b=a;
		b.AffichageLargeur();
	}
	a.AffichageLargeur();
	
}
int main()
{
	testCopie();
/*	Abr a;
	a.AffichageLargeur();
	a.AjouterVal(10);
	a.AffichageLargeur();
	a.AjouterVal(20);
	a.AffichageLargeur();
	a.AjouterVal(30);
	a.AffichageLargeur();
	a.RetirerElement();
	a.AffichageLargeur();
		a.RetirerElement();
	a.AffichageLargeur();
		a.RetirerElement();
	a.AffichageLargeur();
		a.RetirerElement();
	a.AffichageLargeur();
	a.AjouterVal(10);
	a.AffichageLargeur();
	a.AjouterVal(20);
	a.AffichageLargeur();
	a.AjouterVal(30);
a.AffichageLargeur();
	a.AjouterVal(10);
	a.AffichageLargeur();
	a.AjouterVal(20);
	a.AffichageLargeur();
	a.AjouterVal(30);
		a.AffichageLargeur();*/
	/*File b;
	b.Defile();
	b.Enfile(10);
	b.Enfile(20);
	b.AffichageFile();
	cout<<b.Defile()<<endl;
	b.AffichageFile();
	b.Defile();
	b.AffichageFile();
	b.Defile();
	b.AffichageFile();*/
	
	return 0;
}