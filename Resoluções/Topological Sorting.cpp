#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> g[n];
    vector<int> ans;
        for (int k = 0; k < m; ++k){
                int i, j;
                cin>>i>>j;
                g[i].push_back(j);
            }

            //TOPOSORT
            vector<int> degree(n);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < g[i].size(); j++) {
                    int u = i;
                    int v = g[i][j];

                    degree[v]++;
                }
            }


            queue<int> q;

            for (int i = 0; i < n; i++) {
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

            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i] <<endl;
            }
    return 0;
}