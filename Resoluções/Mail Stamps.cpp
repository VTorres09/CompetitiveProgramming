#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

map<long long, vector<long long>> g;
map<long long, bool> visited;

void DFS(long long start) {
    visited[start] = true;
    cout << start << " ";
    for (int v : g[start]){
        if (!visited[v]){
            DFS(v);
        }
    }

}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    long long n; cin>>n;
    for (int k = 0; k < n; ++k) {
        long long i, j;
        cin >> i >> j;
        g[i].push_back(j);
        g[j].push_back(i);
        visited[i] = false; visited[j] = false;
    }

    long long start = 0;
    map<long long, vector<long long>>::iterator it;
    for (it = g.begin(); it != g.end(); it++){
        if (it->second.size() == 1){
            start=it->first;
            break;
        }
    }


    DFS(start);
    return 0;
}