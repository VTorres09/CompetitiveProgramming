#include <cstring>
#include <iostream>
#include <vector>
#define d 256
using namespace std;

void search(string pat, string txt, int q){
    vector<int> resp;
    int M = pat.size();
    int N = txt.size();
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;

    for (i = 0; i < M - 1; i++){
        h = (h * d) % q;
    }

    for (i = 0; i < M; i++){
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (i = 0; i <= N - M; i++){
        if (p == t){
            for (j = 0; j < M; j++){
                if (txt[i+j] != pat[j]){
                    break;
                }
            }

            if (j == M){
                resp.push_back(i+1);
            }
        }
        if ( i < N-M ){
            t = (d*(t - txt[i]*h) + txt[i+M])%q;
            if (t < 0) t = (t + q);
        }
    }


    if(resp.size()!=0){
        cout<<resp.size()<<endl;
        for(int i=0; i<resp.size(); i++){
            cout<<resp[i]<<" ";
        }
    }else{
        cout<<"Not Found";
    }
    cout<<endl<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases; cin>>cases;
    while(cases--){
        string word, pattern;
        cin>>word>>pattern;
        search(pattern, word, 101);
    }
    return 0;
}