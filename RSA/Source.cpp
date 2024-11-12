#include <iostream>
using namespace std;

// Función para realizar la exponenciación modular: (base^exp) % mod
long long exp_mod(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) // Si exp es impar, multiplicamos el resultado por la base
            result = (result * base) % mod;
        exp = exp >> 1; // Dividimos exp entre 2
        base = (base * base) % mod; // Elevamos la base al cuadrado
    }
    return result;
}

int main() {
    long long n, e, d, mensaje, resultado;
    int opcion;

    cout << "Ingrese el valor de n (parte de la clave pública): ";
    cin >> n;
    cout << "Ingrese el valor de e (clave pública para cifrado): ";
    cin >> e;
    cout << "Ingrese el valor de d (clave privada para descifrado): ";
    cin >> d;

    cout << "Seleccione una opción:\n1. Cifrar\n2. Descifrar\nOpción: ";
    cin >> opcion;

    if (opcion == 1) { // Cifrar
        cout << "Ingrese el número a cifrar: ";
        cin >> mensaje;
        resultado = exp_mod(mensaje, e, n);
        cout << "Número cifrado: " << resultado << endl;
    }
    else if (opcion == 2) { // Descifrar
        cout << "Ingrese el número cifrado: ";
        cin >> mensaje;
        resultado = exp_mod(mensaje, d, n);
        cout << "Número descifrado: " << resultado << endl;
    }
    else {
        cout << "Opción no válida." << endl;
    }

    return 0;
}
