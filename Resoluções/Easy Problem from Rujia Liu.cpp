#include <vector>
#include <map>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m) {
        map<int, vector<int>> g;
        vector<int> ans;
        for (int k = 1; k < n+1; ++k) {
            int num;
            cin >> num;
            g[num].push_back(k);
        }

        for (int z = 0; z < m; ++z) {
            int i, j;
            cin >> i >> j;
            if(g[j].size()>=i){
                cout<<g[j][i-1]<<endl;
            } else {
                cout<<0<<endl;
            }


        }
    }
    return 0;
}