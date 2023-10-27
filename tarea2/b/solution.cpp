#include <bits/stdc++.h>
using namespace std;

bool verificarSuma(long long x, long long n, long long k, vector<long long> a) {
    long long maxSuma = 0;  // suma maxima 
    long long subarreglos = 1; // 1<=k<=n<=2*10^5
    long long i = 0; // iterador
    while (i<n){
        if (a[i]>x) return false;
        i++;
    }

    i = 0; // reiniciamos el iteramos
    while(i<n) {
        maxSuma += a[i]; // sumamos a nuestra sumaMax
        if (maxSuma>x) { // si la suma maxima es mayor 
            maxSuma = a[i]; // hacemos que la suma parta el iesimo elemento
            subarreglos++; // sumamos uno a los sub arreglos
        }
        i++;
    }
    if (subarreglos <= k) return true;
    else return false; 
}


int main() {
    long long n, k; // n = longitud del arreglo a
    cin >> n >> k;  // k = numero de subarreglos

    vector<long long> a(n);     // rellenamos el vector
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // busqueda binaria 
    long long l = 1;
    long long r = 2*pow(10,14); // peor caso: un sub arreglos y todos los elementos son 10^9
    while(l < r) {
        long long mid = l+(r-l)/2; // se puede usar l+(r-l)/2 para evitar overflow por la suma
        if(verificarSuma(mid,n,k,a)) r = mid; 
        else l = mid+1;
    }
    cout << l << endl; 
    return 0;
}