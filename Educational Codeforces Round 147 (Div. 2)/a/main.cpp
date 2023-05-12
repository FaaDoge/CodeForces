/* explicacion

El ejercicio consiste en contar el número de enteros positivos (estrictamente mayores a cero)
que pueden coincidir con una plantilla de enteros que se da como entrada. Una plantilla es una
cadena de caracteres que consiste en dígitos y/o signos de interrogación. Cada signo de interrogación
puede ser reemplazado por un dígito (del 0 al 9) para formar un número entero. Sin embargo, no se
permiten ceros a la izquierda. Por lo tanto, la plantilla "?0" no tiene solución.

El algoritmo lee la plantilla de enteros como una cadena de caracteres y usa un bucle para recorrer
cada carácter de la cadena. Para cada signo de interrogación, se multiplicará la respuesta por 10,
ya que hay 10 opciones posibles para reemplazarlo. Si el primer carácter de la cadena es un signo de
interrogación, se multiplicará la respuesta por 9, ya que no se puede utilizar el dígito 0 como primer dígito.

Finalmente, la respuesta se imprimirá por pantalla. El algoritmo se ejecutará para el número de casos de prueba que se indique.

*/
#include <bits/stdc++.h>
using namespace std;

int count_matches(string s) {
    int count = 0; // contador de coincidencias
    for (int i = 1; i <= 1000; i++) { // probar todas las posibles combinaciones de dígitos de 1 a 3 cifras
        string num = to_string(i); // convertir el número en una cadena
        while (num.size() < s.size()) { // agregar ceros iniciales si es necesario
            num = "0" + num;
        }
        bool match = true; // supongamos que hay una coincidencia
        for (int j = 0; j < s.size(); j++) { // comparar cada dígito o signo de interrogación
            if (s[j] != '?' && s[j] != num[j]) { // si el dígito o signo de interrogación no coincide, entonces no hay coincidencia
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
    int t; // número de casos de prueba
    cin >> t;
    while (t--) { // para cada caso de prueba
        string s; // cadena de dígitos y signos de interrogación
        cin >> s;
        cout << count_matches(s) << endl; // contar y mostrar el número de coincidencias
    }
    return 0;
}
