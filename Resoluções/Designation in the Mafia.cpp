#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dist[26][26];
void floydWarshall (int dist[][26]){

    for (int k = 0; k < 26; k++){
        for (int i = 0; i< 26; i++){
            for (int j = 0; j < 26; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string word;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            cin >> dist[i][j];
        }
    }
    floydWarshall(dist);
    cin >> word;
    long long ans = 0;

    for (int i = 0; i < word.size()/2; i++) {
        int a = word[i] - 'a', b = word[word.size() - i - 1] - 'a';
        if (a == b)
            continue;
        int temp = min(dist[a][b], dist[b][a]);
        for (int j = 0; j < 26; j++) {
            if ((j == a) || (j == b))
                continue;
            temp = min(temp, dist[a][j] + dist[b][j]);
        }
        ans += temp;
    }
        cout << ans << endl;
        return 0;
}