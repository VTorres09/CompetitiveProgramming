#include<iostream>
#include <string.h>
using namespace std;
string s;
int memo[1005][1005];

int palindromSize(int x,int y){
    if (x==y){
        return 1;
    }
    if (y-x==1){
        if (s[x]==s[y]){
            return 2;
        }else{
            return 1;
        }
    }
    if (memo[x][y]!=-1){
          return memo[x][y];
     }
    if (s[x]==s[y])
        memo[x][y]= 2 + palindromSize(x+1,y-1);
    else
        memo[x][y]=max(palindromSize(x+1,y),palindromSize(x,y-1));
    
    return memo[x][y];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases; cin>>cases; cin.ignore();
    while(cases--){
        getline(cin, s);
        memset(memo,-1,sizeof(memo));
        cout<<palindromSize(0, s.size()-1)<<endl;
    }
    return 0;
}