#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int inf = 0x3f3f3f3f;
#define inf 0x3f3f3f3f
typedef pair<int, int> ii;
int n,m;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n>>m){
        if(n==0 && m==0){
            break;
        }
        vector<ii> adjList[n];
        vector<bool> inMST(n, false);
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        int dist[n], maxx=-1;
        for(int i=0; i<m; i++){
            int a, b, w; cin>>a>>b>>w;
            adjList[a].push_back(make_pair(b, w));
            adjList[b].push_back(make_pair(a, w));
        }
        //Prim
        int source =0;
        for(int i = 0; i < n; i++) dist[i] = inf;
        dist[source] = 0;
        pq.emplace(0, source);
        while (!pq.empty()){
            int u = pq.top().second;
            pq.pop();

            if (inMST[u]) continue;
            inMST[u] = true;
            if(dist[u]>maxx){
                maxx = dist[u];
            }
            for(auto e : adjList[u]){
                int v = e.first, w = e.second;
                if (!inMST[v] && w < dist[v]) {
                    dist[v] = w;
                    pq.emplace(dist[v], v);
                }
            }
        }
        //Checando nodes
        bool ver = false;
        for(int j=0; j<inMST.size(); j++){
            if(!inMST[j]){
                ver = true;
                break;
            }
        }
        if(ver){
            cout<<"IMPOSSIBLE"<<endl;
        }else{
            cout<<maxx<<endl;
        }

    }

    return 0;
}