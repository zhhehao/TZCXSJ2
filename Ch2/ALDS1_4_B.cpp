/*
** 二分搜索
*/

# include <cstdio>

static int const maxn = 100000 + 5;

int binarySearch(const int s[], int n, int t) {
	int start = 0, end = n-1, mid;
	
	while (start <= end) {
		mid = start + (end-start)/2;
		if (s[mid] == t) return 1;
		else if (s[mid] < t) 
			start = mid + 1;
		else
			end = mid - 1;
	}
	return 0;
}

int main() {
	// freopen("infile", "r", stdin);
	// freopen("outfile", "w", stdout);
	
	int n, q, t, s[maxn];
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) 
			scanf("%d", &s[i]);
		scanf("%d", &q);
		
		int ans = 0;
		for (int i = 0; i < q; i++) {
			scanf("%d", &t);
			ans += binarySearch(s, n, t);
		}
		
		printf("%d\n", ans);
	}
	return 0;
}