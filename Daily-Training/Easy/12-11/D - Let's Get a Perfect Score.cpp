#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    int ans = 0;
    for (int x = 0; x < N; x++) {
      for (int y = x + 1; y < N; y++) {
        bool ok = true;

        for (int j = 0; j < M; j++) {
          if (S[x][j] == 'x' && S[y][j] == 'x') {
            ok = false;
            break;
          }
        }

        if (ok) {
          ans++;
        }
      }
    }
    cout << ans << endl;
    return 0;
}
