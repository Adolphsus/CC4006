#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int n; // n es el tamanno de mi arreglo y x el valor que busco
    int x;
    cin >> n;
    cin >> x;
    map<int, int> m; //creo un mapa
    vector<int> a(n);// creo un vector

    int digit;
    for (int i = 0; i < n; i++) { // lleno mi vector
        cin >> digit;
        a[i] = digit;
    }
    
    for (int i = 0; i < n; i++) { //iteramos
        int c = x - a[i]; //sacamos la diferencia que buscamos
        if (m.find(c) != m.end() && m[c] != i) {  // buscamos que el puntero sea distinto de .end() y que el termino que entrega el mapa sea distinto al que estamos iterando
            cout << i+1 << " " << m[c]+1 << endl; // de ser entregamos la posicion (sumando 1 ya que estamos en un arreglo y un mapa respectivamente)
            return 0; // finalizamos aca
        } else {
            m[a[i]] = i; // si no encontro el valor, lo alamacena en el mapa con el valor del indice
        }
    }
    cout << "IMPOSSIBLE" << endl; // si paso los for, es por que no hay ningun par de valores que cumpla con que sumados sean igual a x
    return 0;
}