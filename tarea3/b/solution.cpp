#include <bits/stdc++.h>
using namespace std;

// problema de dos dimensiones, necesitare una matriz

int main(){
	int n; // n = tamanno de la grilla
	cin >> n;
	
	vector <vector <char>> dp(n, vector <char> (n, 0)); // trabajo con dos matrices
    vector <vector <unsigned long long>> ans(n, vector <unsigned long long> (n, 0)); // una para copiar el input y otra para contar los caminos

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++) { // llenamos la primera matriz con inputs
			cin >> dp[i][j];
		}
	}

	for(int i = 0; i < n; i++){        // la matriz respuesta rellenamos la 1ra fila con 1's si es que
        if (dp[i][0] == '.') ans[i][0] = 1;  // es que la misma possicion el dp posee un '.'
        else {
			for (int j=i; j<n;j++){
				ans[j][0] = 0;
			}
			break;
		}
	}
	
	for(int j = 0; j < n; j++){        // lo mismo aqui
        if (dp[0][j] == '.') ans[0][j] = 1;
		else {
			for (int k=j; k<n;k++){
				ans[0][k] = 0;
			}
			break;
		}
	}

    const unsigned long long m = 1000000007;

    for(int i = 1; i < n; i++){
		for(int j = 1; j < n; j++){
            if (dp[i][j] == '*') ans[i][j] = 0; // si dp[i][j] hay un punto, entonces no hay forma de llegar a ese punto en la respuesta
            else {                              // y ponemos un cero
                ans[i][j] = ((((ans[i-1][j])%m) + ((ans[i][j-1])%m))%m); // si no aplicamos a suma del de arriba con el de la izquierda
				ans[i][j] %= m;
            }
        }
    }

    unsigned long long answer = (ans[n-1][n-1] % m);
	answer%=m;
	cout << answer << endl;
	return 0;
}