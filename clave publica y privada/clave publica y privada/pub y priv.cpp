#include <iostream>
using namespace std;

// Función para calcular el MCD (Máximo común divisor) de dos números
long long mcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Función para calcular el phi de n
long long phi(long long p, long long q)
{
    return (p - 1) * (q - 1);
}

// Función para encontrar una clave pública e tal que mcd(φ(n), e) = 1
long long encontrar_e(long long phi_n) {
    long long e = 2; // Comenzamos con un valor pequeño
    while (mcd(phi_n, e) != 1) {
        e++;
    }
    return e;
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

int main()
{
    long long p = 0;
    long long q = 0;

    // Ingreso de los números primos p y q
    cout << "Ingrese un numero primo p: ";
    cin >> p;
    cout << "Ingrese otro numero primo q: ";
    cin >> q;

    // Calcular phi(n)
    long long phideN = phi(p, q);
    cout << "El numero phi de n es: " << phideN << endl;

    // Encontrar la clave pública e
    long long e = encontrar_e(phideN);
    cout << "La clave pública E es: " << e << endl;

    // Encontrar la clave privada d (inverso de e módulo φ(n))
    long long d = inverso_modular(e, phideN);
    cout << "La clave privada D es: " << d << endl;

    return 0;
}