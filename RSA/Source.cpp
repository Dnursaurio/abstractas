#include <iostream>
using namespace std;

// Funci�n para realizar la exponenciaci�n modular: (base^exp) % mod
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

    cout << "Ingrese el valor de n (parte de la clave p�blica): ";
    cin >> n;
    cout << "Ingrese el valor de e (clave p�blica para cifrado): ";
    cin >> e;
    cout << "Ingrese el valor de d (clave privada para descifrado): ";
    cin >> d;

    cout << "Seleccione una opci�n:\n1. Cifrar\n2. Descifrar\nOpci�n: ";
    cin >> opcion;

    if (opcion == 1) { // Cifrar
        cout << "Ingrese el n�mero a cifrar: ";
        cin >> mensaje;
        resultado = exp_mod(mensaje, e, n);
        cout << "N�mero cifrado: " << resultado << endl;
    }
    else if (opcion == 2) { // Descifrar
        cout << "Ingrese el n�mero cifrado: ";
        cin >> mensaje;
        resultado = exp_mod(mensaje, d, n);
        cout << "N�mero descifrado: " << resultado << endl;
    }
    else {
        cout << "Opci�n no v�lida." << endl;
    }

    return 0;
}
