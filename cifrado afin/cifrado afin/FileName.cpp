#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

// Funci�n para cifrar el mensaje usando el alfabeto ingl�s
string encriptar(string mensaje, int a, int k) {
    string mensaje_encriptado = "";

    // Recorremos cada car�cter del mensaje
    for (char& c : mensaje) {
        if (isalpha(c)) {  // Solo ciframos letras
            char base = (isupper(c)) ? 'A' : 'a';  // Determinamos si la letra es may�scula o min�scula
            int p = c - base;  // Obtenemos el �ndice de la letra (0 para 'a' o 'A', 25 para 'z' o 'Z')
            char letra_encriptada = ((a * p + k) % 26) + base;  // Aplicamos la f�rmula de cifrado
            mensaje_encriptado += letra_encriptada;
        }
        else {
            mensaje_encriptado += c;  // Si no es una letra, la dejamos tal cual
        }
    }

    return mensaje_encriptado;
}

// Funci�n para descifrar el mensaje usando el alfabeto ingl�s
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
        return "No se pudo encontrar el inverso de a mod 26. La clave 'a' no es v�lida.";
    }

    // Recorremos cada car�cter del mensaje
    for (char& c : mensaje) {
        if (isalpha(c)) {  // Solo desciframos letras
            char base = (isupper(c)) ? 'A' : 'a';  // Determinamos si la letra es may�scula o min�scula
            int p = c - base;  // Obtenemos el �ndice de la letra (0 para 'a' o 'A', 25 para 'z' o 'Z')
            char letra_desencriptada = ((a_inverso * (p - k + 26)) % 26) + base;  // Aplicamos la f�rmula de descifrado
            mensaje_desencriptado += letra_desencriptada;
        }
        else {
            mensaje_desencriptado += c;  // Si no es una letra, la dejamos tal cual
        }
    }

    return mensaje_desencriptado;
}

// Funci�n para procesar varias palabras o n�meros separados por espacios
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

    cout << "Ingresa el mensaje a encriptar o desencriptar (puede incluir m�ltiples palabras separadas por espacio): ";
    getline(cin, mensaje);  // Leemos el mensaje completo

    // Procesamos la entrada y separamos las "palabras"
    vector<string> palabras = separarTexto(mensaje);

    cout << "Ingresa el valor de 'a' (clave multiplicativa): ";
    cin >> a;

    cout << "Ingresa el valor de 'k' (clave aditiva): ";
    cin >> k;

    cout << "Elige una opci�n: \n1. Encriptar\n2. Desencriptar\n";
    cout << "Opci�n: ";
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
        cout << "Opci�n no v�lida." << endl;
    }

    return 0;
}
