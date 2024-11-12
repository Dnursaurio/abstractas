#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// Función para calcular el MCD (Máximo Común Divisor)
long long mcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Función para factorizar n en dos números primos p y q
void factorizar_n(long long n, long long& p, long long& q) {
    for (long long i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            p = i;
            q = n / i;
            return;
        }
    }
}

// Función para hallar todos los valores de e que son coprimos con φ(n)
vector<long long> encontrar_e(long long phi_n) {
    vector<long long> posibles_e;
    for (long long e = 2; e < phi_n; e++) {
        if (mcd(e, phi_n) == 1) {
            posibles_e.push_back(e);
        }
    }
    return posibles_e;
}

int main() {
    long long n;

    // Solicitar la entrada de n (módulo)
    cout << "Introduce el valor de n (módulo): ";
    cin >> n;

    // Factorizar n para obtener p y q
    long long p = 0, q = 0;
    factorizar_n(n, p, q);

    if (p == 0 || q == 0) {
        cout << "No se pudo factorizar n en dos primos." << endl;
        return 1;
    }

    cout << "Los factores primos de n son p = " << p << " y q = " << q << endl;

    // Calcular φ(n)
    long long phi_n = (p - 1) * (q - 1);
    cout << "El valor de φ(n) es: " << phi_n << endl;

    // Encontrar todos los valores de e que son coprimos con φ(n)
    vector<long long> posibles_e = encontrar_e(phi_n);

    // Imprimir los valores de e
    cout << "Los valores posibles de e son: ";
    for (long long e : posibles_e) {
        cout << e << " "; //cone sto contamos todos los valores posibles mas el 1
    }
    cout << endl;

    // Imprimir la cantidad de valores posibles de e
    cout << "Cantidad de valores posibles de e: " << posibles_e.size() << endl;
    cout << "nota: a este resultado sumale 1 ya que el 1 tambien se incluye, pero no es efectivo en RSA pos eso no es incluido como valor posible" << endl;
    return 0;
}