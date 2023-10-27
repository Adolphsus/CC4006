#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool esValida(double distancia, vector<double> arr, int maxRouters, int arboles) {
    int routers = 1;
    double ultimo = arr[0] + distancia;
    for(int i = 0; i<arboles; i++){
        if ((double) abs(ultimo-arr[i])>distancia) {
            routers++;
            ultimo = arr[i] + distancia;
        }
    }
    return routers <= maxRouters;
}

void solve(){
    int maxRouters, arboles;
    cin >> maxRouters >> arboles;

    vector<double> bosque(arboles); // largo de bosque < 100.000 
    for (int i = 0; i < arboles; i++) {
        cin >> bosque[i];
    } 
    sort(bosque.begin(), bosque.end());

    double ans = 0;
    double l = 0;
    double r = pow(10,6); // la maxima distancia de un arbol a el inicio es 10^6
    double epsilon = 1e-9;
    while(r - l > epsilon) {
        double mid =  (l+r)/2; // se puede usar l+(r-l)/2 para evitar overflow por la suma
        if(esValida(mid, bosque, maxRouters, arboles) == true) r = mid;
        else l = mid;
    }
    ans = r;
    cout.precision(1);
    cout << fixed << ans << endl;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}