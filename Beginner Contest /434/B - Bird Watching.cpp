#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  
  map<int, vector<int>> mp;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    mp[a].push_back(b);
  }
  
  for (auto const& [key, values] : mp) {
    double sum = 0;
    for (int v : values) {
      sum += v;
    }
    
    
    if (!values.empty()) {
        double ans = sum / values.size();
        cout << ans << endl;
    }
  }

  return 0;
}
