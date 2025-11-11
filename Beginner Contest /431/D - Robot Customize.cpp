#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> W(N), H(N), B(N);
    int total_weight = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> W[i] >> H[i] >> B[i];
        total_weight += W[i];
    }
    
    // オフセット: 差が負になる可能性があるため
    int OFFSET = total_weight;
    int MAX_DIFF = 2 * total_weight + 1;
    
    // dp[j] = 頭と体の重さの差が (j - OFFSET) のときの最大の嬉しさ
    // 差 = 体の重さ - 頭の重さ
    vector<long long> dp(MAX_DIFF, -1);
    dp[OFFSET] = 0; // 初期状態: 差が0、嬉しさも0
    
    for (int i = 0; i < N; i++) {
        vector<long long> next_dp(MAX_DIFF, -1);
        
        for (int j = 0; j < MAX_DIFF; j++) {
            if (dp[j] == -1) continue;
            
            // 部品iを頭に取り付ける
            // 頭の重さが増えるので、差（体 - 頭）は減る
            int next_j = j - W[i];
            if (next_j >= 0) {
                next_dp[next_j] = max(next_dp[next_j], dp[j] + H[i]);
            }
            
            // 部品iを体に取り付ける
            // 体の重さが増えるので、差（体 - 頭）は増える
            next_j = j + W[i];
            if (next_j < MAX_DIFF) {
                next_dp[next_j] = max(next_dp[next_j], dp[j] + B[i]);
            }
        }
        
        dp = next_dp;
    }
    
    // 答えを求める: 差 >= 0 (体の重さ >= 頭の重さ) の中で最大値
    long long ans = 0;
    for (int j = OFFSET; j < MAX_DIFF; j++) {
        if (dp[j] != -1) {
            ans = max(ans, dp[j]);
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
