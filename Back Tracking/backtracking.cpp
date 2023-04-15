#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

using ll = long long;
using db = double;

const int MOD = (int)1e9+7;

    /* presurecode:
        void BackTrack(int i) {
            for (j = <khả năng 1>; j <= <khả năng N>; j++) {
                if (<chấp nhận được khả năng j>) {
                    X[i] = j;
                    <ghi nhận kết quả>
                    if (i == n) {
                        <Kết quả>;
                    }
                    else {
                        BackTrack(i + 1);
                    }
                }
            }
        }
     */
    int n;

    int C(int k, int n) {
        if (k == 0||k == n) {
            return 1;
        }
        else {
            return C(k - 1, n - 1) + C(k, n - 1);
        }
    }

    int main() { 
        // #ifndef ONLINE_JUDGE
        // freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
        // #endif
        ios_base::sync_with_stdio(false); 
        cin.tie(0); cout.tie(0);
        cin >> n;
        cout << C(5, 5) <<endl;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= i; j++) {
                cout << C(j, i) << " ";
            }
            cout << endl;
        }
    }          