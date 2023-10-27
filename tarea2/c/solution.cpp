#include <bits/stdc++.h>

using namespace std;

bool bateriaGastada(long long x, long long n, long long k, long long a, long long b) {
    if (((x*(a-b)+n*b)<k) && x<=n) {
        return true;
    } else {
        return false;
    }
}

void solve(){
    long long k, n, a, b; // k = bateria al comenzar; n=turnos por jugar;
    cin >> k >> n >> a >> b; // a=bateria que consume cada turno con el pc desconectado; 
                             // b=bateria que consume cada turno con el pc conectado; (a>b)
    //queremos un numero x tal que: si jugamos x turnos con el pc desconectado y (n-x) conectado, podamos
    //jugar los n turnos. Esto es una funcion de g(x) = x*a+(n-x)*b = x*(a-b)+n*b;
    long long l = 0;
    long long r = pow(10,18);
    while(l < r){
        long long mid = (l+r)/2;
        if(bateriaGastada(mid,n,k,a,b) == false) r = mid; // La función es creciente: la condición se cumple
        else l = mid+1;
    }
    cout << l-1 << endl;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int q; cin >> q; // q = cantidad de consultas
    while (q--) solve();
    return 0;
}