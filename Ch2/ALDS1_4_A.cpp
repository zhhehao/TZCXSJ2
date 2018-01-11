/*
** 线性搜索
*/

# include <cstdio>

static const int maxn = 10000 + 5;

int line_search(int s[], int n, int t) {
	for (int i = 0; i < n; i++)
		if (s[i] == t)
			return 1;
	return 0;
}

int main() {
	// freopen("infile", "r", stdin);
	// freopen("outfile", "w", stdout);
	int n, q, s[maxn], t;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) scanf("%d", &s[i]);
		scanf("%d", &q);
		int ans = 0;
		for (int i = 0; i < q; i++) {
			scanf("%d", &t);
			ans += line_search(s, n, t);
		}
		printf("%d\n", ans);
	}
	return 0;
}