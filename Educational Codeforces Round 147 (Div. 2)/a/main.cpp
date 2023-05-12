/* explicacion

El ejercicio consiste en contar el n�mero de enteros positivos (estrictamente mayores a cero)
que pueden coincidir con una plantilla de enteros que se da como entrada. Una plantilla es una
cadena de caracteres que consiste en d�gitos y/o signos de interrogaci�n. Cada signo de interrogaci�n
puede ser reemplazado por un d�gito (del 0 al 9) para formar un n�mero entero. Sin embargo, no se
permiten ceros a la izquierda. Por lo tanto, la plantilla "?0" no tiene soluci�n.

El algoritmo lee la plantilla de enteros como una cadena de caracteres y usa un bucle para recorrer
cada car�cter de la cadena. Para cada signo de interrogaci�n, se multiplicar� la respuesta por 10,
ya que hay 10 opciones posibles para reemplazarlo. Si el primer car�cter de la cadena es un signo de
interrogaci�n, se multiplicar� la respuesta por 9, ya que no se puede utilizar el d�gito 0 como primer d�gito.

Finalmente, la respuesta se imprimir� por pantalla. El algoritmo se ejecutar� para el n�mero de casos de prueba que se indique.

*/
#include <bits/stdc++.h>
using namespace std;

int count_matches(string s) {
    int count = 0; // contador de coincidencias
    for (int i = 1; i <= 1000; i++) { // probar todas las posibles combinaciones de d�gitos de 1 a 3 cifras
        string num = to_string(i); // convertir el n�mero en una cadena
        while (num.size() < s.size()) { // agregar ceros iniciales si es necesario
            num = "0" + num;
        }
        bool match = true; // supongamos que hay una coincidencia
        for (int j = 0; j < s.size(); j++) { // comparar cada d�gito o signo de interrogaci�n
            if (s[j] != '?' && s[j] != num[j]) { // si el d�gito o signo de interrogaci�n no coincide, entonces no hay coincidencia
                match = false;
                break;
            }
        }
        if (match) { // si hay coincidencia, incrementar el contador
            count++;
        }
    }
    return count;
}

int main() {
    int t; // n�mero de casos de prueba
    cin >> t;
    while (t--) { // para cada caso de prueba
        string s; // cadena de d�gitos y signos de interrogaci�n
        cin >> s;
        cout << count_matches(s) << endl; // contar y mostrar el n�mero de coincidencias
    }
    return 0;
}
