#include <bits/stdc++.h> //solucion auxiliar comentada
using namespace std;

int main(){
    int t; //aqui nos indican e numero de casos de prueba
    cin>>t;
    while(t--){
        int n;
        cin>>n; //aqui nos dan el largo que tendra el arreglo
        vector<int> a(n);
        for (int i=0;i<n;i++){ //leemos la linea del input y rellenamos nuestro vector
	        cin>>a[i];
        }
        int c0 = 0, c1 = 0; //iniciamos un contador de 0's y 1's
        for (int i=0;i<n;i++){
            if (a[i] == 0) c0++; //si aparece un 0, aumentamos c0
            else c1++; //en caso contrario aumentamos c1
        }
        if (c0 >= n/2){ //si c0 es la mitad o mas del arreglo, basta quitar todos los unos y sumar los ceros
            cout<<c0<<'\n'; // imprimimos las cantidad de ceros
            while (c0--) cout<<0<<' '; // imprimimos los ceros a ser sumados por el arreglo
            cout<<'\n';
        } else{
            if (c1 % 2 == 1) c1--; //si c1 es impar, le sacamos un 1, luego al ser par, la suma intercala siempre sera 0
            cout<<c1<<'\n';
            while (c1--) cout<<1<<' '; //imprimimos la cantidad de 1's que al ser sumados dan ceros
            cout<<'\n';
        }
    }
    return 0;
}