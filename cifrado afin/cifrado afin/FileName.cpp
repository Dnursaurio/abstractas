#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Función para encriptar un carácter usando la fórmula (n * k1 + k2) % 256
int encriptar(int n, int k1, int k2) {
    return (n * k1 + k2) % 256;
}

int main() {
    string input;
    cout << "Introduce el mensaje a encriptar (puede contener letras, números y símbolos): ";
    getline(cin, input);

    // Claves proporcionadas
    int k1 = 7, k2 = 3;

    // Vector para almacenar los números cifrados
    vector<int> cifrado;

    // Encriptar el mensaje
    for (char c : input) {
        int ascii_value = static_cast<int>(c);  // Obtener el valor ASCII del carácter
        int numero_cifrado = encriptar(ascii_value, k1, k2);  // Encriptar
        cifrado.push_back(numero_cifrado);  // Almacenar el número cifrado
    }

    // Mostrar los números cifrados separados por espacio
    cout << "El mensaje encriptado es: ";
    for (int num : cifrado) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}

