#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int cases;
    cin>>cases;
    for(int i =1; i<cases+1; i++) {
        int n, m;
        cin >> n >> m;
        vector<int> g[n+1];
        for (int k = 0; k < m; ++k) {
            int i, j;
            cin >> i >> j;
            g[i].push_back(j);
            g[j].push_back(i);
        }

        vector<int> side(n+1, -1);
        bool is_bipartite = true;
        queue<int> q;
        for (int st = 0; st < n+1; ++st) {
            if (side[st] == -1) {
                q.push(st);
                side[st] = 0;
                while (!q.empty()) {
                    int v = q.front();
                    q.pop();
                    for (int u : g[v]) {
                        if (side[u] == -1) {
                            side[u] = side[v] ^ 1;
                            q.push(u);
                        } else {
                            is_bipartite &= side[u] != side[v];
                        }
                    }
                }
            }
        }

        if(is_bipartite){
            cout<<"Scenario #"<< i<<":"<<endl;
            cout<<"No suspicious bugs found!"<<endl;
        } else{
            cout<<"Scenario #"<< i<<":"<<endl;
            cout<<"Suspicious bugs found!"<<endl;
        }

    }
    return 0;
}