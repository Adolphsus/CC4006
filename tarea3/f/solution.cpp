#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n; 
    vector<char> a(n);
    vector<long long> c(n);
    vector <vector <long long>> dp(n+1, vector <long long> (4));

    if (a.size()<4) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {cin >> a[i];} // lleno mi vector de la palabra
                
    for (int i = 0; i < n; i++) {cin >> c[i];}// lleno mi vector de costos de cada caracter

    char b[5] = {'h','a','r','d'}; // creo un vector que contenga la palabra hard para comparar

    for (int i = 1; i<n+1; i++){
        if (a[i-1] == b[0]){
            dp[i][0] = dp[i-1][0] + c[i-1];
        } else {
            dp[i][0] = dp[i-1][0];
        }
    }

    for (int len = 1; len < 4; len++) {
        for (int cnt = 1; cnt < n+1; cnt++) { //parto desde dp[1][1]
            if (a[cnt-1] != b[len]) { // si el caracter del input coincide con algun caracter de 'hard'
                dp[cnt][len] = dp[cnt-1][len]; // no modificamos nada y seguimos
            } else { // si no es asi:
                dp[cnt][len] = min(dp[cnt-1][len-1], dp[cnt-1][len] + c[cnt-1]);
            }   
        }       
    } 

    long long answer = min(min(dp[n][0], dp[n][1]), min(dp[n][2], dp[n][3]));
    cout << answer << endl;
    return 0; 
}             