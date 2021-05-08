#include<iostream>
using namespace std;
int maxarea(int larg[100][100], int n,int m){
    
    int area, w;
    area=0;
    for(int i=0; i<m ;i++){
        for(int j=0;j<n;j++){
            w=INT_MAX;
            for(int k=0; i-k>=0; k++){
                if(larg[i-k][j]==0){
                    break;
                }
                w = min(w, larg[i-k][j]);

                area = max(area, w*(k+1));
            }
        }
    }

    return area;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    while(cin>>m>>n){
        if(n==0 and m==0){
            break;
        }
        int trees[100][100];
        int larg[100][100]={0};
        int i,j;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                cin>>trees[i][j];
            }
        }

        for(int i=0; i<m ;i++){
            for(int j=0; j<n ;j++){
                if(trees[i][j]==1){
                    larg[i][j]=0;
                }else if(j==0){
                    larg[i][j]=1;
                }else{
                    larg[i][j] = larg[i][j-1]+1;
                }
            }
        }
        cout<<maxarea(larg,n,m)<<endl;
    }
    return 0;
}

