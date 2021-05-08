#include<iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int cases;
    string palavra;

    cin>>cases;
    while(cases>0){
        cin>>palavra;
        stack<char> pilha;
        for(int i = 0; i<palavra.size(); i++) {
            if(pilha.empty() || palavra[i] == 'A') pilha.push(palavra[i]);
            else if((palavra[i] == 'B' && pilha.top() =='A') || (palavra[i] == 'B' && pilha.top() =='B')) pilha.pop();
        }
        cout<<pilha.size()<<endl;
    }
    return 0;
}
