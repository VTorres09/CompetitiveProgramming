#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases; cin>>cases;
    while(cases--) {
        int x = 2.5e4+20;
        int a[x],b[x],c[x],d[x];
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            cin>>a[i]>>b[i]>>c[i]>>d[i];
        }

        vector<int> first, second;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                first.push_back(-(a[i] + b[j]));
                second.push_back(c[i] + d[j]);
            }
        }

        sort(second.begin(), second.end());

       long long resp = 0;
        for (int v: first) {
            auto l = lower_bound(second.begin(), second.end(), v);
            auto r = upper_bound(second.begin(), second.end(), v);
            resp += r - l;
        }

        cout << resp << endl;
        if(cases>0){
            cout<<endl;
        }

    }
    return 0;
}
