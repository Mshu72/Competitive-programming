#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    long long T;
    cin >> N >> T;
    vector<long long>A(N);
    for(int i=0;i<N;i++) cin >> A[i];

    long long ans = 0;
    long long open = 0;

    for(int i=0;i<N;i++){
        if(A[i] >= open){
            ans += A[i] - open;
            open = A[i] + 100;
        }
    }

    if(open < T) ans += T - open;

    cout << ans << endl;
}
