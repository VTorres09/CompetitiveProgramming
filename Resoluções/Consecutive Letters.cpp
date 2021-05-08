#include <iostream>
#include <vector>
using namespace std;
string word;
int sz[2000010];
int ds[2000010];
int resp[2000010];
pair<int, int> inputs[2000010];

int dsFind(int i){
    if(ds[i] != i){
        ds[i] = dsFind(ds[i]);
    }
    return ds[i];
}

void dsUnion(int a, int b){
    a= dsFind(a); b=dsFind(b);
    if(a!=b){
        if(sz[a] < sz[b]){
            swap(a, b);
        }
        ds[b] = a;
        sz[a] += sz[b];
    }
}

void dsBuild(){
    for(int i =0; i< word.length(); i++){
        ds[i]= i;
        sz[i]= 1;
        if(i>=1 && word.at(i)!='#' && word.at(i)==word.at(i-1)){
            dsUnion(i, i-1);
        }
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases, q; cin>>cases;
    for(int i =1; i<cases+1; i++){
        cin>>word>>q;
        string backup = word;
        for(int i=0; i<q; i++){
            cin>>inputs[i].first>>inputs[i].second;
            if(inputs[i].first==2){
                word.at(inputs[i].second) = '#';
            }
        }
        dsBuild();
        int count=0;
        for(int j=q-1; j>=0; j--){
            if(inputs[j].first == 1){
                resp[count] = sz[dsFind(inputs[j].second)];
                count++;
            }else{
                word[inputs[j].second] = backup[inputs[j].second];
                if(inputs[j].second>=1 && word.at(inputs[j].second) == word.at(inputs[j].second-1)){
                    dsUnion(inputs[j].second, inputs[j].second-1);
                }
                if(inputs[j].second<word.length()-1 && word.at(inputs[j].second) == word.at(inputs[j].second+1)){
                    dsUnion(inputs[j].second, inputs[j].second+1);
                }
            }
        }

        cout<<"Case "<<i <<":"<<endl;
        for(int i=count-1; i>=0; i--){
            cout<<resp[i]<<endl;
        }
    }
    return 0;
}