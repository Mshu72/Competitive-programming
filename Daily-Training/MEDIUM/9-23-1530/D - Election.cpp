#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> A(N);
  for(int i=0;i<N;i++)cin >> A[i];
  
  unordered_map<string, int> freq;
  for(auto &s:A) freq[s]++;

  string ans;
  int max_count =0;
  for(auto &p:freq){
    if(p.second > max_count){
      max_count = p.second;
      ans = p.first;
    }
  }

  cout << ans <<endl;
  return 0;
}
