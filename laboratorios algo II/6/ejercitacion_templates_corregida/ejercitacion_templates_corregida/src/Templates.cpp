#include<string>

using namespace std;

// Ejercicio 1: Pasar a templates
int cuadrado(int x) {
  return x * x;
}

// Ejercicio 2: Pasar a templates
bool contiene(string s, char c) {
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == c) {
      return true;
    }
  }
  return false;
}

// Ejercicio 3: Funcion es prefijo con un template contenedor
template<class Contenedor>
bool esPrefijo(Contenedor a, Contenedor b){
    if(a.size()>b.size()){
        return false;
    }
    bool res = true;
    for(int i = 0; i < a.size(); i++){
        res = res && a[i]==b[i];
    }
    return res;
}
// Ejercicio 4: Función maximo con un template contenedor y uno elemento
template<class Contenedor, class Elem>
Elem maximo(Contenedor c){
    Elem max = c[0];
    for(Elem i : c){
        if(max < i )
            max = i;
    }
    return max;
}