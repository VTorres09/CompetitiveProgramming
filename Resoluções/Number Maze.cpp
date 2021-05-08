#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int inf = 0x3f3f3f3f;
#define inf 0x3f3f3f3f
int g[1000][1000];
int dist[1000][1000];
int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};
int n, m;
priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
bool outsideOfgrid(pair<int, int> p){
    if(p.first<0||p.second<0||p.first>=n||p.second>=m)return true;
    else return false;
}

void dijkstra(int x,int y){
    pair<int, int> u,v;
    int w,d;
    dist[y][x] = g[y][x];
    pq.emplace(g[y][x],make_pair(y,x));
    while(!pq.empty()) {
        u = pq.top().second;
        d = pq.top().first;
        pq.pop();
        if(d==dist[u.first][u.second])
            for(int i=0 ; i<=3 ; i++ ) {
                v.first = u.first + dy[i];
                v.second = u.second + dx[i];
                if(outsideOfgrid(v))continue;
                w = g[v.first][v.second];

                if( dist[u.first][u.second] + w < dist[v.first][v.second] ) {
                    dist[v.first][v.second] = dist[u.first][u.second] + w;
                    pq.emplace(dist[v.first][v.second], make_pair(v.first,v.second));
                }
            }
    }
}

int main(){
    int cases; cin>>cases;
    while(cases--){
        cin>>n>>m;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>g[i][j];
                dist[i][j] = inf;
            }
        }
        dijkstra(0,0);
        cout<<dist[n-1][m-1]<<endl;
    }

    return 0;
}