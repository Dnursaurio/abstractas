#include <iostream>
#include <cmath>
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

// Algoritmo extendido de Euclides para encontrar el inverso de e módulo φ(n)
long long inverso_modular(long long e, long long phi) {
    long long t = 0;
    long long new_t = 1;
    long long r = phi;
    long long new_r = e;

    while (new_r != 0) {
        long long quotient = r / new_r;

        // Intercambiamos los valores de t, new_t, r y new_r
        long long temp_t = t;
        t = new_t;
        new_t = temp_t - quotient * new_t;

        long long temp_r = r;
        r = new_r;
        new_r = temp_r - quotient * new_r;
    }

    if (r > 1) {
        cout << "No existe inverso modular!" << endl;
        return -1; // No tiene inverso
    }

    if (t < 0) {
        t = t + phi; // Hacemos que el inverso sea positivo
    }

    return t;
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

int main() {
    long long n, e;

    // Solicitar la entrada de n (módulo) y e (clave pública)
    cout << "Introduce el valor de n (módulo): ";
    cin >> n;
    cout << "Introduce el valor de e (clave pública): ";
    cin >> e;

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

    // Verificar que e sea coprimo con φ(n)
    if (mcd(e, phi_n) != 1) {
        cout << "El valor de e no es válido, ya que no es coprimo con φ(n)." << endl;
        return 1;
    }

    // Calcular la clave privada d
    long long d = inverso_modular(e, phi_n);

    if (d != -1) {
        cout << "La clave privada d es: " << d << endl;
    }

    return 0;
}