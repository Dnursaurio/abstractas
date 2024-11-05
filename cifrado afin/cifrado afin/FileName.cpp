#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Función para cifrar el mensaje
string encriptar(string mensaje, int a, int k) {
    string mensaje_encriptado = "";

    // Recorremos cada letra del mensaje
    for (char& c : mensaje) {
        if (isalpha(c)) {  // Verificamos si el caracter es una letra
            c = tolower(c);  // Convertimos la letra a minúscula
            int p = c - 'a';  // Obtenemos el índice de la letra (0 para 'a', 25 para 'z')
            char letra_encriptada = ((a * p + k) % 26) + 'a';  // Aplicamos la fórmula de cifrado
            mensaje_encriptado += letra_encriptada;
        }
        else {
            mensaje_encriptado += c;  // Si no es una letra, agregamos el caracter tal cual
        }
    }

    return mensaje_encriptado;
}

// Función para descifrar el mensaje
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

    // Recorremos cada letra del mensaje
    for (char& c : mensaje) {
        if (isalpha(c)) {  // Verificamos si el caracter es una letra
            c = tolower(c);  // Convertimos la letra a minúscula
            int p = c - 'a';  // Obtenemos el índice de la letra (0 para 'a', 25 para 'z')
            char letra_desencriptada = ((a_inverso * (p - k) + 26) % 26) + 'a';  // Aplicamos la fórmula de descifrado
            mensaje_desencriptado += letra_desencriptada;
        }
        else {
            mensaje_desencriptado += c;  // Si no es una letra, agregamos el caracter tal cual
        }
    }

    return mensaje_desencriptado;
}

int main() {
    string mensaje;
    int a, k;
    int opcion;

    cout << "Ingresa el mensaje a encriptar o desencriptar: ";
    getline(cin, mensaje);  // Leemos el mensaje completo

    cout << "Ingresa el valor de 'a' (clave multiplicativa): ";
    cin >> a;

    cout << "Ingresa el valor de 'k' (clave aditiva): ";
    cin >> k;

    cout << "Elige una opción: \n1. Encriptar\n2. Desencriptar\n";
    cout << "Opción: ";
    cin >> opcion;

    // Ejecutamos la opción seleccionada
    if (opcion == 1) {
        string mensaje_encriptado = encriptar(mensaje, a, k);
        cout << "Mensaje encriptado: " << mensaje_encriptado << endl;
    }
    else if (opcion == 2) {
        string mensaje_desencriptado = desencriptar(mensaje, a, k);
        cout << "Mensaje desencriptado: " << mensaje_desencriptado << endl;
    }
    else {
        cout << "Opción no válida." << endl;
    }

    return 0;
}