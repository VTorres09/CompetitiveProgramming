
#include <iostream>
#include <map>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int cases, num;
    cin >> cases;
    while (cases--) {
        int tam;
        cin >> tam;
        map<int, int> cnt;

        int sum = 0;
        long long resp = 0;

        for (int i = 0; i < tam; i++) {
            cin >> num;
            sum += num;

            if (sum == 0){
                resp++;
            }
            resp += cnt[sum]++;
        }

        cout<<resp<<endl;
    }
}