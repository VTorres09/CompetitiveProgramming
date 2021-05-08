#include <iostream>
#include <algorithm>

using namespace std;

struct DNA{
    int ordem;
    int time;
};

int sort(string str){
    int time=0;
    for(int i=0;i<str.size();i++){
        for(int j=i+1;j<str.size();j++){
            if(str[i]>str[j]) time++;
        }
    }
    return time;
}

bool comp(DNA a,DNA b)
{
    if(a.time==b.time) {
        return a.ordem<b.ordem;
    }else {
        return a.time<b.time;
    }
}
int main()
{
    int N;
    int ver=0;
    cin>>N;
    while(N--)
    {
        if(ver){
            cout<<endl;
        }
        int linha,col;
        cin>>col>>linha;
        string str[linha];
        cin.get();
        for(int i=0;i<linha;i++){
            getline(cin,str[i]);
        }
        DNA srt[linha];

        for(int i=0;i<linha;i++){
            srt[i].ordem=i;
            srt[i].time=sort(str[i]);
        }

        sort(srt,srt+linha,comp);

        for(int i=0;i<linha;i++){
            cout<<str[srt[i].ordem]<<endl;
        }
        ver=1;
    }
    return 0;
}