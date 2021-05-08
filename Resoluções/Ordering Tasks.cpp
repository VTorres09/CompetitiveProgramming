#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m, !(n == 0 && m == 0)) {
            vector<int> g[n + 1];
            vector<int> ans;
        for (int k = 0; k < m; ++k){
                int i, j;
                cin>>i>>j;
                g[i].push_back(j);
            }

          //toposort
            vector<int> degree(n + 1);
            for (int i = 0; i < n + 1; i++) {
                for (int j = 0; j < g[i].size(); j++) {
                    int u = i;
                    int v = g[i][j];

                    degree[v]++;
                }
            }


            queue<int> q;

            for (int i = 0; i < n + 1; i++) {
                if (degree[i] == 0) q.push(i);
            }

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                ans.push_back(u);
                for (auto v : g[u]) {
                    degree[v]--;
                    if (degree[v] == 0) {
                        q.push(v);
                    }
                }
            }

            for (int i = 1; i < ans.size(); i++) {
                cout << ans[i] << " ";
            }
            cout<<endl;
        }
    return 0;
}