/*
** 本题用分治法
** 此题值得深思，用以理解分治法的精髓
*/

# include <cstdio>

const int maxn = 20 + 2;
int n, a[maxn], q;

int solve(int i, int m) {
	if (m == 0)
		return 1;
	if (i >= n)
		return 0;
	// 把一个大问题分解成两个小问题。第一个表示不选择a[i]，第二个表示选择a[i]作为m的一部分
	int res = solve(i+1, m) || solve(i+1, m-a[i]); 
	return res;
}

int main() {
	// freopen("infile", "r", stdin);
	// freopen("outfile", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int m; scanf("%d", &m);
		if (solve(0, m)) 
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}