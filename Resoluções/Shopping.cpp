#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
typedef long long ll;
using namespace std;
int w, h;
char g[25][25];
ll dist[25][ 25 ] = {0};
ll dx[4] = { 0 , 0 , 1 , -1 };
ll dy[4] = { 1 ,-1 , 0 ,  0 };
ll startx,starty,endx,endy;

bool limit(ll x,ll y){
    return x>=0 and x<w and y>=0 and y<h and g[x][y] != 'X';
}

void dijkstra(){
    dist[startx][starty] = 0;
    queue<pair<ll,ll>> q;
    q.push({startx,starty});

    while(!q.empty()){
        auto x = q.front();
        q.pop();
        ll u = x.first;
        ll v = x.second;

        for(ll i = 0 ; i < 4 ; i++){
            ll ni = u + dx[i];
            ll nj = v + dy[i];

            if(limit(ni,nj) and (dist[ni][nj]>(dist[u][v] + (g[u][v] - '0') ) ) ){
                dist[ni][nj] = dist[u][v] + (g[u][v] - '0');
                q.push({ni,nj});
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>h>>w && w!=0 && h!= 0) {
        for(ll i = 0 ; i < w ; i++){
            for(ll j = 0 ; j < h ; j++){
                char ch; cin>>ch;
                g[i][j] = ch;
                if(ch == 'S'){
                    startx = i; starty = j;
                    g[i][j] = '0';
                }
                else if(ch == 'D'){
                    endx = i; endy = j;
                    g[i][j] = '0';
                }
                dist[i][j] = 1e9;
            }
        }
        dijkstra();
        cout<<dist[endx][endy]<<endl;
    }
    return 0;
}



