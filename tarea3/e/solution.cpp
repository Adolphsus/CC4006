#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, a, b, c;
    cin >> n >> a >> b >> c;
    vector <long long> DP(n+1, -127128937);
    vector <long long> pieces(3);

    //caso base
    DP[0] = 0; 

    if (n==1) {
        cout << 1 << endl;
        return 0;
    }

    pieces[0] = a;
    pieces[1] = b;
    pieces[2] = c;

    for(int i = 1; i<n+1; i++){
        for(int j = 0; j < 3; j++) {
            if(i >= pieces[j] && DP[i-pieces[j]] !=  -127128937) { 
                DP[i] = max(DP[i], DP[i-pieces[j]] + 1);
            }
        }
    }
    cout << DP[n] << endl;
    return 0;
}