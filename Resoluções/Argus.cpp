
#include <iostream>
#include <queue>
#include <string>
#include <sstream>


using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq1, pq2;
    string line;
    while (true) {
        getline(cin, line);
        if(line.compare("#") == 0) break;
    vector<string> tokens;
    stringstream check1(line);
    string intermediate;
    while (getline(check1, intermediate, ' ')) {
        tokens.push_back(intermediate);
    }
    pq1.push(make_pair(make_pair(stoi(tokens[2]), stoi(tokens[1])), stoi(tokens[2])));
    }
    int qtd;
    pair<pair<int, int>, int> sai;
    cin>>qtd;
    for(int i=0; i<qtd; i++){
            sai = pq1.top();
            pq1.pop();
            cout << sai.first.second << endl;
            sai.first.first += sai.second;
            pq1.push(sai);
    }
    return 0;
}