#include<iostream>
const int N = 2 * 1e5 +5;
using namespace std;
int num[N], sz[N], sum[N], ds[N];
int n,m, aux;

int dsFind(int i){
    if(num[i]==i){
        return i;
    }else{
        return num[i]=dsFind(num[i]);
    }
}

void op1(int p,int q){
    int a=dsFind(p), b=dsFind(q);
    if(a!=b){
        num[a]=b;
        sum[b]+=sum[a];
        sz[b]+=sz[a];
    }
}

void op2(int p){
    int a=dsFind(ds[p]);
    sz[a]--;
    sum[a]-=p;
    ds[p]=++aux;
    num[aux]=aux;
    sz[aux]=1;
    sum[aux]=p;
}

void dsBuild(int n){
    for(int i=0;i<=3*n;i++){
        num[i]=i;
        sum[i]=i;
        sz[i]=1;
        ds[i]=i;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n>>m){
        dsBuild(n);
        aux=n;
        for(int i=0;i<m;i++){
            int op,p,q;
            cin>>op;
            if(op==1){
                cin>>p>>q;
                op1(ds[p],ds[q]);

            }else if(op==2){
                cin>>p>>q;

                if(dsFind(ds[p]) != dsFind(ds[q])){
                    op2(p);
                    op1(ds[p],ds[q]);
                }

            }else if(op==3){
                cin>>p;

                int a = dsFind(ds[p]);
                cout<<sz[a]<<" "<<sum[a]<<endl;

            }
        }
    }
    return 0;
}