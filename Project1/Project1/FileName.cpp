#include <iostream>
using namespace std;

// Función para calcular (base^exponente) % modulo de forma eficiente
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;  // Reducir la base si es mayor que el módulo

    while (exp > 0) {
        // Si el exponente es impar, multiplicamos el resultado por la base
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }

        // Exponente se reduce a la mitad y la base se eleva al cuadrado
        exp = exp >> 1;
        base = (base * base) % mod;
    }

    return result;
}

int main() {
    long long base, exponente, modulo;

    // Solicitar la entrada de base, exponente y módulo
    cout << "Introduce la base: ";
    cin >> base;
    cout << "Introduce el exponente: ";
    cin >> exponente;
    cout << "Introduce el modulo: ";
    cin >> modulo;

    // Verificar si el módulo es mayor que 1 para evitar errores
    if (modulo <= 1) {
        cout << "El modulo debe ser mayor que 1." << endl;
        return 1;
    }

    // Calcular base^exponente % modulo utilizando la función de exponenciación modular
    long long resultado = modExp(base, exponente, modulo);

    // Mostrar el resultado
    cout << "El resultado de " << base << "^" << exponente << " % " << modulo << " es: " << resultado << endl;

    return 0;
}