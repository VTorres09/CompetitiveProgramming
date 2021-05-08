#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cases, px, py; cin>>cases;
    string cmd;
    while (cases--){
        int ver=0, l =0, r=0, u=0, d=0;
        cin>>px>>py;
        cin>>cmd;
        for(int i = 0; i<cmd.length(); i++){
            if(cmd.at(i)=='L') l++;
            else if(cmd.at(i)=='R') r++;
            else if(cmd.at(i)=='U') u++;
            else if(cmd.at(i)=='D') d++;
        }

        if(px==0) ver++;
        else if(px>0 and r>=px) ver++;
        else if(px<0 && l>=-px) ver++;

        if(py==0) ver++;
        else if(py>0 and u>=py) ver++;
        else if(py<0 and d>=-py) ver++;

        if(ver==2){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }

    }
    return 0;
}