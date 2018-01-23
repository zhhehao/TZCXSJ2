/*
** 本题算法分析很有借鉴的必要，详见本书 p143-145
*/

# include <iostream>
# include <algorithm>
# include <cstdio>
# include <cstring>
using namespace std;

const int maxn = 1000 + 5;
const int vmax = 10000 + 10;

int a[maxn], b[maxn], n, t[maxn], minv;

int solve() {
    int ans = 0;
    sort(b, b + n);
    for (int i = 0; i < n; i++) {
        if (t[i] != 0 || a[i] == b[i]) {
            continue;
        }

        int m = vmax, an = 0, sum = 0;
        int j = i;
        while (true) {
            t[j] = 1;
            m = min(m, a[j]);
            ++an;
            sum += a[j];
            j = lower_bound(b, b + n, a[j]) - b;
            if (j == i) {
                ans += min(sum + (an - 2) * m, sum + m + (an + 1) * minv);
                break;
            }
        }
    }
    return ans;
}

int main() {
    // freopen("infile", "r", stdin);
    // freopen("outfile", "w", stdout);
    cin >> n;
    minv = vmax;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        minv = min(minv, a[i]);
        b[i] = a[i];
    }
    memset(t, 0, sizeof(t));

    cout << solve() << endl;

    return 0;
}