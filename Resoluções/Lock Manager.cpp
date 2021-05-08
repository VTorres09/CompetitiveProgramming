#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tam;
    cin >> tam;
    while (tam>0) {
        set<int> blocked;
        map<int, set<pair<char, int>>> locks;
        char mode;

        while (cin >> mode, mode != '#') {
            int trid, item;
            cin >> trid >> item;

            if (blocked.count(trid)>0){
                cout << "IGNORED"<< endl;
            }else if (locks.count(item)==0) {
                cout << "GRANTED"<< endl;
                set<pair<char, int>> nlock;
                nlock.insert(make_pair(mode, trid));
                locks[item] = nlock;
            } else {
                bool ver = false;
                for (auto lock: locks[item]){
                    if (lock.second != trid && (lock.first == 'X' || mode == 'X'))
                        ver = true;
                }
                if (ver) {
                    cout << "DENIED" << endl;
                    blocked.insert(trid);
                } else {
                    cout << "GRANTED" <<endl;
                    locks[item].insert(make_pair(mode, trid));
                }
            }
        }

        tam--;


    }
}