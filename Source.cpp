#include <iostream>
#include <random>
using namespace std;
//#define n = 10

bool verifica(int valor1[], int tam, int valor2)
{
	for (int i = 0; i < tam; i++)
	{
		if (valor1[i] == valor2)
			return true;
	}
	return false;
}

int main()
{
	//int numerotemp = 0;
	int valores[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(1, 25);
	int v0;

	for (static int i = 0; i< sizeof(valores) / sizeof(int); i++)
	{
		v0 = dist(mt);
		if (!verifica(valores, i, v0))
			valores[i] = v0;
		cout << valores[i] << "\n";
		
		

	}
	
	
	cout << endl;
}