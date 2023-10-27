#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long numcards; cin >> numcards; // recibimos el numero de cartas
    long long sum = 0;
    priority_queue<int> pq; // creamos una priority queque

    for (int i=0;i<numcards;i++) {
        int carta; 
        cin>>carta; // recibimos las cartas y las vamos apilando en nuestro stack
        if (carta != 0) {
            pq.push(carta);
        } else {
            if (pq.empty() != true) {
                sum += pq.top();
                pq.pop();
            } else {
                continue;
            }
        }
    }
    cout<<sum<<endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;
    while (t--) solve();
    return 0;
}