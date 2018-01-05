# include <cstdio>
# include <algorithm>
using namespace std;

int n, maxv, minv;

int main() {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	while (scanf("%d", &n) == 1) {
		maxv = -2000000000;
		scanf("%d", &minv);
		int t;
		for (int i = 1; i < n; i++) {
			scanf("%d", &t);
			maxv = max(maxv, t - minv);
			minv = min(minv, t);
		}
		printf("%d\n", maxv);
	}
	return 0;
}
