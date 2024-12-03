#include <iostream>
using namespace std;

const int n = 6; // Tama�o de las palabras
const int m = 2 * n; // Tama�o de las palabras codificadas
int A[n][n] =
{
    {1, 1, 0, 0, 0, 0},
    {1, 1, 1, 0, 0, 0},
    {0, 1, 1, 1, 0, 0},
    {0, 0, 1, 1, 1, 0},
    {0, 0, 0, 1, 1, 1},
    {0, 0, 0, 0, 1, 1}
};

// Multiplica un vector por la matriz A en m�dulo 2
void multiplyModulo2(int w[], int result[])
{
    for (int i = 0; i < n; i++)
    {
        result[i] = 0;
        for (int j = 0; j < n; j++)
        {
            result[i] += w[j] * A[j][i];
        }
        result[i] %= 2; // Reducir m�dulo 2
    }
}

// Calcula la distancia de Hamming entre dos vectores
int hammingDistance(int v1[], int v2[], int size)
{
    int distance = 0;
    for (int i = 0; i < size; i++)
    {
        if (v1[i] != v2[i])
        {
            distance++;
        }
    }
    return distance;
}

int main()
{
    // Generar todas las palabras posibles en Z2^n
    int words[256][n]; // Hay 2^n palabras posibles (256 para n = 8)
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            words[i][j] = (i >> j) & 1; // Extraer cada bit
        }
    }

    // Codificar todas las palabras con G = [I|A]
    int encodedWords[256][m];
    for (int i = 0; i < (1 << n); i++)
    {
        // Copiar la palabra original (I)
        for (int j = 0; j < n; j++)
        {
            encodedWords[i][j] = words[i][j];
        }
        // Calcular la parte de paridad (A)
        int parity[n];
        multiplyModulo2(words[i], parity);
        for (int j = 0; j < n; j++)
        {
            encodedWords[i][n + j] = parity[j];
        }
    }

    // Calcular la distancia m�nima entre palabras codificadas
    int minDistance = m; // M�xima distancia posible
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = i + 1; j < (1 << n); j++)
        {
            int distance = hammingDistance(encodedWords[i], encodedWords[j], m);
            if (distance < minDistance)
            {
                minDistance = distance;
            }
        }
    }

    // Imprimir la distancia m�nima
    cout << "La distancia m�nima entre las palabras codificadas es: " << minDistance << endl;

    return 0;
}