#include <iostream>
#include <sstream>
#include <vector>
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

// Función para separar una cadena de texto en números enteros
vector<long long> separarNumeros(string texto) {
    vector<long long> numeros;
    stringstream ss(texto);
    long long numero;

    while (ss >> numero) {
        numeros.push_back(numero);  // Agregamos cada número al vector
    }

    return numeros;
}

int main() {
    long long n, e, d, mensaje, resultado;
    int opcion;

    // Solicitar valores de la clave pública y privada
    cout << "Ingrese el valor de n (parte de la clave pública): ";
    cin >> n;
    cout << "Ingrese el valor de e (clave pública para cifrado): ";
    cin >> e;
    cout << "Ingrese el valor de d (clave privada para descifrado): ";
    cin >> d;

    // Limpiar el buffer para leer la línea completa con espacios
    cin.ignore();

    // Leer la opción para cifrar o descifrar
    cout << "Seleccione una opción:\n1. Cifrar\n2. Descifrar\nOpción: ";
    cin >> opcion;

    // Limpiar el buffer nuevamente antes de leer los números
    cin.ignore();

    // Solicitar los números a cifrar o descifrar
    cout << "Ingrese los números (separados por espacio): ";
    string input;
    getline(cin, input);  // Leer la línea completa

    // Separar los números ingresados
    vector<long long> numeros = separarNumeros(input);

    // Procesar los números según la opción seleccionada
    if (opcion == 1) { // Cifrar
        cout << "Números cifrados: ";
        for (long long num : numeros) {
            resultado = exp_mod(num, e, n);
            cout << resultado << " ";  // Imprimir cada número cifrado
        }
        cout << endl;
    }
    else if (opcion == 2) { // Descifrar
        cout << "Números descifrados: ";
        for (long long num : numeros) {
            resultado = exp_mod(num, d, n);
            cout << resultado << " ";  // Imprimir cada número descifrado
        }
        cout << endl;
    }
    else {
        cout << "Opción no válida." << endl;
    }

    return 0;
}
