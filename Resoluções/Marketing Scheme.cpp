#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int cases;
    cin>>cases;
    while(cases>0){
        int l, r;
        cin >> l >> r;
        if (l * 2 > r)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
        cases--;
    }
    

    return 0;
}