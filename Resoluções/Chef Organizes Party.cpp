#include<iostream>
#include<queue>

typedef long long ll;
using namespace std;

ll gcd(ll a,ll b) {
    if(b==0)
        return a;
    else
        return gcd(b, a%b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases, a, n, aux, m, resp; cin>>cases;
    while(cases--){
        cin>>a;
        queue<int> nums;
        queue<int> backup;
        for(int i=0; i<a; i++){
            cin>>n;
            nums.push(n);
            backup.push(n);
        }
        m = nums.front();
        nums.pop();
        while(!nums.empty()){
            m = gcd(m, nums.front());
            nums.pop();
        }
        resp=0;
        while(!backup.empty()){
            resp += backup.front()/m;
            backup.pop();
        }
        cout<<resp<<endl;

    }

    return 0;
}