#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); //optimización de la entrada y salida
  int casos;
  cin >> casos; //leemos el número de casos de prueba
  while (casos--) { //iteramos sobre cada caso de prueba
    string s;
    cin >> s; //leemos la cadena s
    int respuesta = 1e9; //inicializamos la respuesta con un número muy grande
    map<char, int> m;
    for (char letra = 'a'; letra <= 'z'; letra++) { //iteramos sobre cada letra del alfabeto
      int pasos = 0;
      m.clear();
      for (char d: s) { //iteramos sobre cada letra de la cadena s
        if (d == letra) { //si encontramos la letra letra
          for (auto p: m) {
            pasos = max(pasos, __lg(p.second)+1); //actualizamos el número de pasos
          }
          m.clear(); //reiniciamos el mapa
        }
        else {
          m[d]++; //incrementamos el contador de letras
        }
      }
      for (auto p: m) {
        pasos = max(pasos, __lg(p.second)+1); //actualizamos el número de pasos
      }
      respuesta = min(respuesta, pasos); //actualizamos la respuesta
    }
    cout << respuesta << '\n'; //imprimimos la respuesta
  }
}
