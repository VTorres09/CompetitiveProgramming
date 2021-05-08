#include<iostream>
#include<map>
using namespace std;
const int N = 200010;
int v[N], tree[4*N];

void build(int p, int l, int r){
    if(l==r){
        tree[p] = v[r];
    }else{
        int m = (l+r)/2, lc = 2*p, rc = lc + 1;
        build(lc, l, m);
        build(rc, m+1, r);
        //soma
        tree[p] = tree[lc]+tree[rc];
    }
}

int query(int p, int l, int r, int ql, int qr){
    if(ql<=l && r <=qr){
        return tree[p];
    }else{
        int m = (l+r)/2, lc = 2*p, rc = lc + 1;
        if(qr<=m){
            return query(lc,l,m,ql,qr);
        }else if(ql>m){
            return query(rc, m+1, r, ql, qr);
        }else{
            return query(lc,l,m,ql,qr)+query(rc, m+1, r, ql, qr);
        }
    }
}

void update(int p, int l, int r, int i, int x){
    if(l == r){
        tree[p] = v[i] = x;
    }else{
        int m = (l+r)/2, lc = 2*p, rc = lc + 1;
        if(i<=m){
            update(lc, l, m, i,x );
        }else{
            update(rc, m+1, r, i, x);
        }
        tree[p] = tree[lc]+tree[rc];
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q; cin>>n>>m>>q;
    string drinks[n+1];
    map<string, int> bar;
    for(int i = 1; i<n+1; i++) cin>>drinks[i];
    for(int i = 1; i<m+1; i++){
        string name; int qtd;
        cin>>name>>qtd;
        bar[name]=qtd;
    }
    for(int i = 1; i<n+1; i++) v[i] = bar[drinks[i]];
    build(1, 1, n);

    for(int i =0; i<q; i++){
        int type; cin>>type;
        if(type == 1){
            string x; int y;
            cin>>y>>x;
            update(1,1,n,y,bar[x]);

        }else if(type == 2){
            int l, r, hours, alcohol; cin>>l>>r;
            hours = ((r-l)+1)*30;
            alcohol = query(1,1,n,l,r);
            if(alcohol>hours){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }

    return 0;
}