#include <bits/stdc++.h> // librer�a est�ndar que incluye todas las librer�as de C++
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0); // optimizaci�n de las funciones de entrada y salida
    cin.tie(0); // optimizaci�n de la entrada
    cout.tie(0); // optimizaci�n de la salida

    int t; // variable para el n�mero de casos de prueba
    cin >> t;
    for (int i = 0; i < t; ++i) { // ciclo para cada caso de prueba
        int n; // variable para la longitud de los vectores
        cin >> n;
        vector<int> a(n), b(n); // declaraci�n de dos vectores a y b de longitud n
        for (int i = 0; i < n; ++i) { // ciclo para ingresar los elementos del vector a
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) { // ciclo para ingresar los elementos del vector b
            cin >> b[i];
        }
        int l = n; // variable para el �ndice izquierdo que se inicializa con n
        int r = 0; // variable para el �ndice derecho que se inicializa con 0
        for (int i = 0; i < n; ++i) { // ciclo para encontrar los �ndices m�nimo y m�ximo donde a[i] es diferente de b[i]
            if (a[i] != b[i]) {
                l = min(i, l); // actualizar l con el m�nimo valor de i y l
                r = max(i, r); // actualizar r con el m�ximo valor de i y r
            }
        }
        while (l > 0 && b[l - 1] <= b[l]) { // ciclo para encontrar el �ndice izquierdo m�s grande posible
            l--;
        }
        while (r < n - 1 && b[r] <= b[r + 1]) { // ciclo para encontrar el �ndice derecho m�s peque�o posible
            r++;
        }
        cout << l + 1 << ' ' << r + 1 << '\n'; // salida de los �ndices izquierdo y derecho encontrados
    }
}
