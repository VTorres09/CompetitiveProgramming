#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    cin>>input;
    vector<char> v;

    for(int i=0; i<input.size(); i++){
        if(v.size() == 0){
            v.push_back(input.at(i));
        }else{
            if(v[v.size()-1] == input.at(i)){
                v.pop_back();
            }else{
                v.push_back(input.at(i));
            }

        }
    }

    if(v.size() == 0){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}