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
int main()
{

testsAjouts();
	//cout<<"jeej"<<endl;
	return 0;
}
