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
    for (char letra = 'a'; letra <= 'z'; letra++) { //iteramos sobre cada letra del alfabeto
      int contador = 0; //inicializamos un contador de letras
      int pasos = 0; //inicializamos un contador de pasos
      for (char d: s) { //iteramos sobre cada letra de la cadena s
        if (d == letra) { //si encontramos la letra letra
          pasos = max(pasos, contador ? __lg(contador)+1 : 0); //actualizamos el número de pasos
          contador = 0; //reiniciamos el contador de letras
        }
        else contador++; //incrementamos el contador de letras
      }
      pasos = max(pasos, contador ? __lg(contador)+1 : 0); //actualizamos el número de pasos
      respuesta = min(respuesta, pasos); //actualizamos la respuesta
    }
    cout << respuesta << '\n'; //imprimimos la respuesta
  }
}
