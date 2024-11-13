#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "---------------------------------\n"
        << "NUMEROS A LETRAS Y AL REVES\n"
        << "---------------------------------\n";

    int opcion = 0;
    cout << "Escoge una opcion:\n 1.(letras a numeros ASCII)\n 2.(numeros ASCII a letras)" << endl;
    cin >> opcion;
    cin.ignore();  // Limpiamos el buffer para poder leer la frase después

    if (opcion == 1) {
        cout << "Usted ha elegido convertir letras a numeros ASCII" << endl;

        string frase;
        cout << "Ingrese una frase: ";
        getline(cin, frase);  // Leemos una línea completa de texto

        cout << "Su frase en numeros ASCII es: ";
        for (char c : frase) {
            cout << static_cast<int>(c) << " ";  // Convertimos el carácter a su valor ASCII
        }
        cout << endl;

    }
    else if (opcion == 2) {
        cout << "Usted ha elegido convertir numeros ASCII a letras" << endl;

        cout << "Ingrese una serie de numeros ASCII separados por espacios: ";
        string numeros;
        cin.ignore();
        getline(cin, numeros);

        cout << "La frase convertida es: ";

        int num;
        size_t pos = 0;
        while ((pos = numeros.find(" ")) != string::npos) {
            num = stoi(numeros.substr(0, pos));
            cout << static_cast<char>(num);
            numeros.erase(0, pos + 1);
        }
        // Convertir el último número
        if (!numeros.empty()) {
            num = stoi(numeros);
            cout << static_cast<char>(num);
        }
        cout << endl;
    }
    return 0;
}