#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cases, n, k; cin>>cases;
    while (cases--){
        cin>>n>>k;
        k--;
        if(n%2==0){
            int resp= k%n;
            cout<<resp+1<<endl;
        }else{
            int half= n/2;
            int resp=((k/half)+k)%n;
            cout<<resp+1<<endl;
        }
    }
    return 0;
}