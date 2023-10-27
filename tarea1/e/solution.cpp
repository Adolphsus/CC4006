#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	set<int> posiciones;
    multiset<int> espacios;
    int x, n;
    cin >> x >> n;
    posiciones = {0,x};
    espacios = {x};
    for (int i = 0; i < n; i++){
        int semaforo;
        cin >> semaforo;
        auto itr=posiciones.lower_bound(semaforo);
        auto itl=prev(itr);
        int espacio = *itr-*itl;
        espacios.erase(espacios.find(espacio)); // probar esto
        espacios.insert(*itr-semaforo);
        espacios.insert(semaforo-*itl);
        posiciones.insert(semaforo);
        auto itf = --espacios.end();
        cout << *itf << " ";
    }
	return 0;
}