#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cases, n; cin>>cases;
    while (cases--){
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << (i == j || (i + 1) % n == j) << " ";
            }
            cout << endl;
        }
    }
    return 0;
}