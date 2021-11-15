#include <iostream>
#include <random>
using namespace std;
//#define n = 10

/*bool verifica(int valor1[], int tam, int valor2)
{
	for (int i = 0; i < tam; i++)
	{
		if (valor1[i] == valor2)
			return true;
	}
	return false;
}*/

int gerador()
{
  random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(1, 25);
  return dist(mt);
}

int main()
{
	//int numerotemp = 0;
	int valores[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int v0 = NULL;

	for (static int i = 0; i< sizeof(valores) / sizeof(int); i++)
	{
		/*v0 = dist(mt);
		if (!verifica(valores, i, v0))
			valores[i] = v0;
		cout << valores[i] << "\n";*/
		if (i == 0)
		{
			v0 = gerador();
			valores[i] = v0;
			
		}
		if (i > 0)
		{
			int tam = i;
			v0 = gerador();
			/*if (v0 != valores[i] - 1)
			{
				valores[i] = v0;
				cout << valores[i] << "\n";
			}*/
			while (tam>0)
			{
				if (v0 != valores[tam])
				{
					valores[i] = v0;
					tam--;
					
				}
				else
				{
					v0 = gerador();
				}
				
			}
		}
	}
	for (int j = 0; j < sizeof(valores) / sizeof(int); j++)
	{
		cout << valores[j] << "\n";
	}
	int teste = 1;
	
  
	cout << endl;
}
