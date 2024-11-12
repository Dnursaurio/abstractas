#include <iostream>
using namespace std;

long long mcd(long long a, long long b)
{
	while (b != 0)
	{
		long long temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

void nros_correctos(long long& a, long long& b)
{
	if (a > b)
	{
		long long rpta1 = a / b;
		long long rpta2 = a % b;

		cout << "el cociente de la division de a y b: " << rpta1 << endl;
		cout << "el residuo de la division de a y b: " << rpta2 << endl;
	}
	else
	{
		cout << "Z fuera de rango: " << endl;
		long long corregir1 = b / a;
		long long corregir2 = b % a;
		cout << "el cociente corregido de la division es: " << corregir1 << endl;
		cout << "el residuo corregido de la division es: " << corregir2 << endl;
	}
}

void ecuaciones(long long a, long long b)
{
	if (a > b)
	{
		cout << "la ecuacion es: " << "-> " << "y su despeje es: " << endl;
		while (b != 1)
		{
			long long cociente = a / b;
			long long residuo = a % b;
			cout << a << "=" << b << "*" << cociente << "+" << residuo << " -> " << residuo << "=" << a << "-" << b << "*" << cociente << endl;

			a = b;
			b = residuo;
		}
	}
	else 
	{
		cout << "la ecuacion es: " << "-> " << "y su despeje es: " << endl;
		while (a != 1)
		{
			long long cociente = b / a;
			long long residuo = b % a;
			cout << b << "=" << a << "*" << cociente << "+" << residuo << " -> " << residuo << "=" << b << "-" << a << "*" << cociente << endl;

			b = a;
			a = residuo;
		}
	}
}

long long inverso_modular(long long a, long long m)
{
	long long m0 = m, t, q;
	long long x0 = 0, x1 = 1;

	if (m == 1) return 0;

	// Algoritmo extendido de Euclides para encontrar el inverso
	while (a > 1) {
		q = a / m;
		t = m;

		m = a % m;
		a = t;
		t = x0;

		x0 = x1 - q * x0;
		x1 = t;
	}

	// Asegurarse de que x1 sea positivo
	if (x1 < 0) x1 += m0;

	return x1;
}

int main()
{
	long long a = 0;
	long long b = 0;
	
	cout << "INVERSOS MODULO N" << endl;
	cout << "--------------------------------------------\n" << "nota: siempre: a < b\n" <<"caso contrario saldra otro resultado\n" << "--------------------------------------------\n";
	cout << "ingrese los numeros a y b: " << endl;
	cout << "a (numero modulo n): ";
	cin >> a;
	cout << endl;
	cout << "b: ";
	cin >> b;
	cout << endl;
	if (mcd(a,b) == 1)
	{
		nros_correctos(a, b);
		cout <<"los valores de a y b son: " << a << ", " << b << " respectivamente" << endl;
		cout << "---------------------------------\n" << "las ecuaciones de " << a << " y " << b << " son: \n" << "---------------------------------\n";
		ecuaciones(a, b);
		if (a > b)
		{
			cout << "---------------------------------\n" << "el inveros modular de es: \n" << "---------------------------------- \n";
			cout << inverso_modular(a, b) << endl;
		}
		else
		{
			cout << "---------------------------------\n" << "el inveros modular de es: \n" << "---------------------------------- \n";
			cout << inverso_modular(a, b) << endl;
		}
	}
	else
	{
		cout << "numero no invertible mano, pina pues";
	}
	return 0;
}