#include <iostream>
#include <sstream>
#include <vector>
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

// Funci�n para separar una cadena de texto en n�meros enteros
vector<long long> separarNumeros(string texto) {
    vector<long long> numeros;
    stringstream ss(texto);
    long long numero;

    while (ss >> numero) {
        numeros.push_back(numero);  // Agregamos cada n�mero al vector
    }

    return numeros;
}

int main() {
    long long n, e, d, mensaje, resultado;
    int opcion;

    // Solicitar valores de la clave p�blica y privada
    cout << "Ingrese el valor de n (parte de la clave p�blica): ";
    cin >> n;
    cout << "Ingrese el valor de e (clave p�blica para cifrado): ";
    cin >> e;
    cout << "Ingrese el valor de d (clave privada para descifrado): ";
    cin >> d;

    // Limpiar el buffer para leer la l�nea completa con espacios
    cin.ignore();

    // Leer la opci�n para cifrar o descifrar
    cout << "Seleccione una opci�n:\n1. Cifrar\n2. Descifrar\nOpci�n: ";
    cin >> opcion;

    // Limpiar el buffer nuevamente antes de leer los n�meros
    cin.ignore();

    // Solicitar los n�meros a cifrar o descifrar
    cout << "Ingrese los n�meros (separados por espacio): ";
    string input;
    getline(cin, input);  // Leer la l�nea completa

    // Separar los n�meros ingresados
    vector<long long> numeros = separarNumeros(input);

    // Procesar los n�meros seg�n la opci�n seleccionada
    if (opcion == 1) { // Cifrar
        cout << "N�meros cifrados: ";
        for (long long num : numeros) {
            resultado = exp_mod(num, e, n);
            cout << resultado << " ";  // Imprimir cada n�mero cifrado
        }
        cout << endl;
    }
    else if (opcion == 2) { // Descifrar
        cout << "N�meros descifrados: ";
        for (long long num : numeros) {
            resultado = exp_mod(num, d, n);
            cout << resultado << " ";  // Imprimir cada n�mero descifrado
        }
        cout << endl;
    }
    else {
        cout << "Opci�n no v�lida." << endl;
    }

    return 0;
}
