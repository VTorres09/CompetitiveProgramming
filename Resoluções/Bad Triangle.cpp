#include <iostream>
typedef long long ll;
using namespace std;
int nums[50010];

bool verifica(ll x,ll y,ll z){
    if( x+y<=z || x+z<=y || y+z<=x ){
        return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases, n; cin>>cases;
    while(cases--){
        cin>>n;
        for(int i=1; i<=n; i++){
            cin>>nums[i];
        }
        if(!verifica(nums[1],nums[2],nums[n])){
            cout<<1<<" "<<2<<" "<<n<<endl;
        }else if (!verifica(nums[1],nums[n-1],nums[n])){
            cout<<1<<" "<<n-1<<" "<<n<<endl;
        } else{
            cout<<"-1"<<endl;
        }
    }
    return 0;
}



