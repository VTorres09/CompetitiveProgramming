#include<iostream>

using namespace std;

int main() {

    long p[200005];
    long q[200005];
    bool used[200005];

    long tam, i, minimo;
    cin >> tam;

    p[0] = 0;
    minimo = p[0];
    for (i = 0; i < tam - 1; ++i) {
        cin >> q[i];
        p[i + 1] = p[i] + q[i];
        minimo = min(minimo, p[i + 1]);
    }

    minimo = 1 - minimo;
    bool ver = false;
    for (i = 0; i < tam; ++i) {
        p[i] = p[i] + minimo;
        if (p[i] > tam || p[i] <= 0) {
            ver = true;
            break;
        } else if (used[p[i]]) {
            ver = true;
            break;
        }

        used[p[i]] = true;
    }

    if (ver) {
        cout << "-1" << endl;
    } else {
        for (i = 0; i < tam; ++i){
            cout << p[i] << ' ';
        }
    }

    return 0;
}