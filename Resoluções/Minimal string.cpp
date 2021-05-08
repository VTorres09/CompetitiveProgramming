#include <iostream>
#include <stack>
#include <cstring>
#include <queue>
using namespace std;
int count[30];

char menorChar(){
    for(int i = 1;i<=26;++i){
        if(count[i]){
            return 'a'-1+i;
        }
    }
}
int main(){
    char str[100005];
    queue<char > fila;
    stack<char > pilha;
    scanf("%s",str+1);
    string resp = "";
    int len = strlen(str+1);
    for(int i = 1;i<=len;++i){
        fila.push(str[i]);
        count[str[i]-'a'+1]++;
    }
    while(!fila.empty()){
        char menor = menorChar();
        if(pilha.empty()){
            char now = fila.front();
            count[now-'a'+1]--;
            fila.pop();
            pilha.push(now);
        }else{
            if(pilha.top()<=menor){
                char top = pilha.top();
                pilha.pop();
                resp+=top;
            }else{
                char now = fila.front();
                count[now-'a'+1]--;
                fila.pop();
                pilha.push(now);
            }
        }
    }

    while(!pilha.empty()){
        resp+=pilha.top();
        pilha.pop();
    }
    cout<<resp<<endl;
    return 0;
}