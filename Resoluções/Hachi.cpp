#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin>>s;
    vector<long long> cnt(10,0);
    for(int i = 0; i < s.length(); i++) {
        cnt[s[i] - '0']++;
    }
    if(s.size()==1){
        if(s == "8"){
            cout<< "Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
        return 0;
    } else if(s.size()==2){
        if(stoi(s)%8==0){
            cout<<"Yes"<<endl;
            return 0;
        }
        swap(s[0],s[1]);
        if(stoi(s)%8==0){
            cout<<"Yes"<<endl;
            return 0;
        }
        cout<<"No"<<endl;
        return 0;
    }
    long long r = 0;
    while(r<1000){
        long long temp = r;
        vector<long long> cnt2(10,0);
        for(int i = 0; i < 3; i++){
            cnt2[r%10]++;
            r /=10;
        }
        bool ok = true;
        for(int i = 0; i < 10; i++){
            if(cnt2[i] > cnt[i]) ok = false;
        }
        if(ok){
            cout<<"Yes"<<endl;
            return 0;
        }
        r=temp+8;
    }

    cout<<"No"<<endl;
    return 0;
}
