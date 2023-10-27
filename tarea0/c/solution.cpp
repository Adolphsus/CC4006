#include <bits/stdc++.h> //resolucion vista en aux comentada
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin>>s; //Aqui le pasamos al string la palabra para ver si es producto de ofuscacion
    int last = 'a' - 1; // 
    for(int i=0;i<s.size();i++){ //recorremos la palabra
        if (s[i] > last){ /// si el caracter actual es mayor que "last" tenemos dos casos:
            if (s[i] - last == 1) last = s[i]; //1. Si el caracter es mayor que el actual por la unidad, s[i] pasa a ser last
            else { 
                cout<<"NO\n"; //si la diferencia es mayor, es porque se salto una letra, es decir, no puede ser porducto de la ofuscacion
                return 0;     //Por tanto, printeamos "NO"
            }
        }
    }
    cout<<"YES\n"; //Si pasa el for entonces si es producto de ofuscacion y printeamos "YES"
    return 0;
}