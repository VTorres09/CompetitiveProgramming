#include <iostream>
#include <vector>
using namespace std;
const int N = 2 * 1e5 +5;
int ds[N];
int sz[N];
int count;
int dsFind(int i){
    if(ds[i] != i){
        ds[i] = dsFind(ds[i]);
    }
    return ds[i];
}

void dsUnion(int a, int b){
    a= dsFind(a); b=dsFind(b);
    if(a!=b){
        if(sz[a] < sz[b]){
            swap(a, b);
        }
        ds[b] = a;
        sz[a] += sz[b];
        count--;
    }
}

void dsBuild(int n){
    for(int i =0; i< n; i++){
        ds[i]= i;
        sz[i]= 1;
    }
}


int main ( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, a ,b, road; cin>>n>>m;
    pair<int, int> roads[m];
    int nr[m];
    vector<int> ans;
    dsBuild(n);
    for(int i =0; i<m; i++){
        cin>>a>>b;
        roads[i] = make_pair(a,b);
    }

    for(int i = 0; i< m; i++){
        cin>>nr[i];
    }

    count=n;
    for(int i=m-1; i>=0; i--){
        int u = roads[nr[i]-1].first;
        int v = roads[nr[i]-1].second;
        dsUnion(u, v);
        ans.push_back(count);
    }


    for(int i=ans.size()-2; i>=0; i--){
        cout<<ans[i]<<endl;
    }
    cout<<n<<endl;
   return 0;
}