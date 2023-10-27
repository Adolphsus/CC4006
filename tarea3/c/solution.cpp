#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x; // n = miradores, x = maximo numero de metros dispuestos a subir 
    cin >> n >> x; 
    vector<int> a(n); // a = vector que almacena la altura del iesimo mirador
    vector<int> dp(n);

    if (n==1){
        cout<<1<<endl;
        return 0;
    }

    for (int i = 0; i<n; i++){cin >> a[i];}
    for (int i = 0; i<n; i++){dp[i] = 0;}

    for (int i = 0; i<n; i++){ 
        if(a[i+1] - a[i] <= x) {
            dp[i] += 1;
            for (int j = i+1; j<n; j++){
                if (a[j] - a[j-1] <= x) {
                    dp[i] += 1;
                } else {
                    break;
                }
            }
        }
    }

    long long answer = 0;
    for (int i = 0; i<n; i++){
        if(dp[i] > answer) {
            answer = dp[i];
        }
    }
    cout << answer << endl;
    return 0;
}