#include <bits/stdc++.h>
using namespace std;

#define fast_io cin.tie(0);ios_base::sync_with_stdio(0)
#define endl "\n"

typedef long long int ll;
const ll MOD = 1e9+7;
struct Matriz{
    ll mat[20][20];
};
struct Vetor{
    ll vet[20];
};

Matriz MatMult(Matriz A, Matriz B) {
    Matriz C;
    ll soma = 0LL;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            soma = 0LL;
            for (int k = 0; k < 20; k++) {
                soma += A.mat[i][k] * B.mat[k][j];
                soma %= MOD;
            }
            C.mat[i][j] = soma;
        }
    }
    return C;
}

Matriz MatExpo(Matriz B, int expo) {
    Matriz C;
    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 20; j++){
            C.mat[i][j] = (i==j);
        }
    }
    while (expo > 0LL) {
        if (expo & 1)
            C = MatMult(C, B);
        B = MatMult(B, B);
        expo >>= 1;
    }
    return C;
}

Vetor MatVet(Matriz A, Vetor v) {
    Vetor x;
    ll soma;
    for (int i = 0; i < 20; i++) {
        soma = 0LL;
        for(int j = 0; j < 20; j++) {
            soma += A.mat[i][j] * v.vet[j];
            soma %= MOD;
        }
        x.vet[i] = soma;
    }
    return x;
}

ll somaVet(Vetor v) {
    ll soma = 0LL;
    for (int i = 0; i < 20; i++) {
        soma += v.vet[i];
        soma %= MOD;
    }
    return soma;
}

ll solve(int n) {
    Matriz C;
    for (int i = 0; i<20;i++){
        for(int j=0;j<20;j++){
            if (i == 0){
                C.mat[i][j] = 3LL*((j==5)||(j==9)||(j==13)||(j==17));
            }
            else{
                C.mat[i][j] = (j==(i-1));
            }
        }
    }

    C = MatExpo(C, n-1);
    Vetor a;
    for (int i = 0; i < 20; i++) {
        a.vet[i] = (i==0);
    }
    a = MatVet(C, a);
    return somaVet(a);
}

int main() {
    fast_io;
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << solve(n+1) << endl;
    }

    return 0;
}