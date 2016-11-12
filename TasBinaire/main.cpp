#include <iostream>
#include "TasBinaire.h"

using namespace std;
void testsAjouts()
{
	TasBinaire a(3);
	a.AfficherTas();
	a.AjouterElement(2);
	a.AfficherTas();
	a.AjouterElement(3);
	a.AfficherTas();
	a.AjouterElement(1);
	a.AfficherTas();
	a.AjouterElement(4);
	a.AfficherTas();
	int tab[4]={2,5,8,2};
	TasBinaire b(4,tab);
	b.AfficherTas();
		
}
void testAjust()
{
	int tab[4]={2,5,8,2};
	TasBinaire b(4,tab);
	b.AfficherTas();
	b.Ajuster(4);
	b.AfficherTas();
	b.Ajuster(-3);
	b.AfficherTas();
	b.Ajuster(-20);
	b.AfficherTas();
	
}
void testSuppr()
{
	int tab[4]={2,5,8,2};
	TasBinaire b(4,tab);
	b.AfficherTas();
	b.SupprimerTete();
	b.AfficherTas();
	b.SupprimerTete();
	b.AfficherTas();
	b.SupprimerTete();
	b.AfficherTas();
	b.SupprimerTete();
	b.AfficherTas();
	b.SupprimerTete();
	b.AfficherTas();
	
}
void sousTest(TasBinaire w)
{
	w.AfficherTas();
}
void testCopie()
{
	int tab[4]={2,5,8,2};
	TasBinaire b(4,tab);
	b.AfficherTas();
	/*{
		TasBinaire c (b);
		c.AfficherTas();
	}
	b.AfficherTas();*/
	cout<<"Test"<<endl;
	sousTest(b);
	b.AfficherTas();
	
	
	

}


int main()
{

//testsAjouts();
//testSuppr();
testCopie();
	//cout<<"jeej"<<endl;
	return 0;
}
