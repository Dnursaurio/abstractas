#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

// Función para cifrar el mensaje usando el alfabeto inglés
string encriptar(string mensaje, int a, int k) {
    string mensaje_encriptado = "";

    // Recorremos cada carácter del mensaje
    for (char& c : mensaje) {
        if (isalpha(c)) {  // Solo ciframos letras
            char base = (isupper(c)) ? 'A' : 'a';  // Determinamos si la letra es mayúscula o minúscula
            int p = c - base;  // Obtenemos el índice de la letra (0 para 'a' o 'A', 25 para 'z' o 'Z')
            char letra_encriptada = ((a * p + k) % 26) + base;  // Aplicamos la fórmula de cifrado
            mensaje_encriptado += letra_encriptada;
        }
        else {
            mensaje_encriptado += c;  // Si no es una letra, la dejamos tal cual
        }
    }

    return mensaje_encriptado;
}

// Función para descifrar el mensaje usando el alfabeto inglés
string desencriptar(string mensaje, int a, int k) {
    string mensaje_desencriptado = "";

    // Calculamos el inverso de a mod 26
    int a_inverso = 0;
    for (int i = 1; i < 26; ++i) {
        if ((a * i) % 26 == 1) {
            a_inverso = i;
            break;
        }
    }

    if (a_inverso == 0) {
        return "No se pudo encontrar el inverso de a mod 26. La clave 'a' no es válida.";
    }

    // Recorremos cada carácter del mensaje
    for (char& c : mensaje) {
        if (isalpha(c)) {  // Solo desciframos letras
            char base = (isupper(c)) ? 'A' : 'a';  // Determinamos si la letra es mayúscula o minúscula
            int p = c - base;  // Obtenemos el índice de la letra (0 para 'a' o 'A', 25 para 'z' o 'Z')
            char letra_desencriptada = ((a_inverso * (p - k + 26)) % 26) + base;  // Aplicamos la fórmula de descifrado
            mensaje_desencriptado += letra_desencriptada;
        }
        else {
            mensaje_desencriptado += c;  // Si no es una letra, la dejamos tal cual
        }
    }

    return mensaje_desencriptado;
}

// Función para procesar varias palabras o números separados por espacios
vector<string> separarTexto(string texto) {
    vector<string> palabras;
    stringstream ss(texto);
    string palabra;

    while (getline(ss, palabra, ' ')) {
        palabras.push_back(palabra);  // Agregar cada "palabra" al vector
    }

    return palabras;
}

int main() {
    string mensaje;
    int a, k;
    int opcion;

    cout << "Ingresa el mensaje a encriptar o desencriptar (puede incluir múltiples palabras separadas por espacio): ";
    getline(cin, mensaje);  // Leemos el mensaje completo

    // Procesamos la entrada y separamos las "palabras"
    vector<string> palabras = separarTexto(mensaje);

    cout << "Ingresa el valor de 'a' (clave multiplicativa): ";
    cin >> a;

    cout << "Ingresa el valor de 'k' (clave aditiva): ";
    cin >> k;

    cout << "Elige una opción: \n1. Encriptar\n2. Desencriptar\n";
    cout << "Opción: ";
    cin >> opcion;

    // Procesamos cada palabra del mensaje
    if (opcion == 1) {
        for (string& palabra : palabras) {
            string mensaje_encriptado = encriptar(palabra, a, k);
            cout << "Palabra encriptada: " << mensaje_encriptado << endl;
        }
    }
    else if (opcion == 2) {
        for (string& palabra : palabras) {
            string mensaje_desencriptado = desencriptar(palabra, a, k);
            cout << mensaje_desencriptado<<" ";
        }
    }
    else {
        cout << "Opción no válida." << endl;
    }

    return 0;
}
