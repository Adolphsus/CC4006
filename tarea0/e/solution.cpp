#include <bits/stdc++.h> //resolucion en aux comentada
using namespace std;

int main(){
    int t; //este t corrersponde al numero de casos de prueba que se haran
    cin>>t;
    while (t--){
        int n,m; //n indica el numero de B's y m indica el numero de R's
        string s1, s2; //s2 corresponde a la primera torre y s2 a la segunda torre
        cin>>n>>m>>s1>>s2; //luego se los pasamos por el input
        reverse(s2.begin(), s2.end()); //lo damos vuelta la torre 2
        string s = s1 + s2; //esto es equivalente a apilar la torre dos sobre la torre uno sacando uno a uno de la torre dos
        int c = 0; //inicializamos un contador
        for (int i=1;i<s.size();i++){  //recorremos la torre apilada
            if (s[i] == s[i-1]) c++; //Si el anterior es igual al bloque actual aumentamos el contador
        }
        if (c<=1) cout<<"YES\n"; //si el contador es 1 o menos el porque son bellisimas las torres
        else cout<<"NO\n"; //si no, significa que sobra un bloque (ya sea B o R) y no podran ser bellisimas las torres
    }                      // pues no quedaran intercalados los colores (se repite uno)
    return 0;
}