#include <vector>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int t,n,r;
    cin >> t;
    for (int cases = 1; cases < t+1; ++cases) {
        cin>>n>>r;
        vector<int> g[n];
        bool visited[n];
        vector<pair<int, int>> ans;
        for(int i = 0;i < n; i++){
            visited[i] = false;
            g[i].clear();
        }


        for (int k = 0; k < r; ++k) {
            int i, j;
            cin >> i >> j;
            g[j].push_back(i);
        }

        //TOPOSORT
        vector<int> degree(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < g[i].size(); j++) {;
                int v = g[i][j];
                degree[v]++;
            }
        }

        set<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            if (degree[i] == 0){
                q.insert(make_pair(i,1));
                visited[i] = true;
            }

        }

        while (!q.empty()) {
            pair<int,int> u = *(q.begin());
            q.erase(q.begin());

            ans.push_back(u);
            int currValue = u.first;
            int currLevel = u.second;
            for(int j = 0;j < g[currValue].size(); j++){
                if(!visited[g[currValue][j]]){
                    degree[g[currValue][j]]--;
                    if(degree[g[currValue][j]] == 0){
                        q.insert(make_pair(g[currValue][j], currLevel+1));
                        visited[g[currValue][j]] = 1;
                    }
                }
            }
        }
        vector<pair<int, int>> resp;
        cout << "Scenario #" <<cases<<":"<< endl;
        for (int i = 0; i < ans.size(); i++) {
            resp.push_back(make_pair(ans[i].second, ans[i].first));
        }

        sort(resp.begin(), resp.end());
        for (int i = 0; i < ans.size(); i++) {
            cout << resp[i].first << " " << resp[i].second << endl;
        }
    }
    return 0;
}