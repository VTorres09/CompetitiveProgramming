#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>

using namespace std;

char g[50][50];
bool vis[50][50];
queue <pair<int, int>> Q;
int w , h;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool valid(int x,int y){
    return x>=0 && y>=0 && x<h && y<w && (g[x][y]=='.');
}

int bfs(int x, int y){
    int ux, uy, vx, vy, cnt=0;
    memset(vis, 0, sizeof(vis));
    while(!Q.empty()) Q.pop();

    vis[x][y] =  true;
    Q.push(pair<int,int>(x,y));

    while(!Q.empty()){
        pair<int,int> u = Q.front(); Q.pop();
        ux = u.first; uy = u.second;
        for(int i=0; i<4 ;i++){
            vx = ux + dx[i];
            vy = uy + dy[i];
            if(!valid(vx, vy)) continue;
            if(vis[vx][vy]) continue;
            cnt++;
            vis[vx][vy] = true;
            Q.push(make_pair(vx, vy));
        }
    }
    return cnt;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int posx, posy;
    int cases, t;
    int i, j;
    cin>>cases;
    for(int z=1; z<cases+1; z++){
        cin>>w>>h;
        for(i=0; i<h; i++) cin>>g[i];

        for(i=0; i<h; i++){
            for(j=0; j<w; j++){
                if(g[i][j]=='@'){
                    posx = i ,
                    posy = j, i = j = w+h;
                }
            }
        }

        int ans =  bfs(posx, posy)+1;
        cout<<"Case "<<z<<": "<< ans<<endl;
    }
    return 0;
}
