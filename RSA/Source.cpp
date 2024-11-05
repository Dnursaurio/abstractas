#include <iostream>
using namespace std;

//primero detectamos si el numero en cuestion es primo
bool nro_primo(int num)
{
	if (num <= 1)
	{
		return false;
	}
	for (int i = 2; i*i <= num; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

//descompocicion de nen p y q
bool factores_prim_de_n(int n, int &p, int &q)
{
	for (int i = 2; i * i <= n;i++)
	{
		if (n % i == 0)
		{
			int otro_factor = n / i;
			if (nro_primo(i) && nro_primo(otro_factor) && i != otro_factor)
			{
				p = i;
				q = otro_factor;

				if (p * q == n)
				{
					return true;
				}
			}
		}
	}
}

void valor_phi(int n,int p,int q)
{
	int phi = (p - 1) * (q-1);
	cout << "el valor phi de: " << n << " es: " << phi;
}

int main()
{
	/*ecibimoos un numero en que descompondremos un 
	valor p y un q, que son factores primos de n y al
	ser multiplicados los dos den como resultado n*/
	int n;
	cout << "ingrese un numero: ";
	cin >> n;
	int p = 0;
	int q = 0;
	if (factores_prim_de_n(n,p,q))
	{
		cout << "el numero introducido es: " << n << " descompuesto en p y q con p de valor: " << p << " y q de valor: " << q << endl;
	}
	else
	{
		cout << "este numero no cumple con la descompocicion prima" << endl;
	}
	valor_phi(n,p,q);
	return 0;
}