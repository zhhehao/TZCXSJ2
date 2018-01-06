# include <cstdio>

static const int maxn = 100 + 2;
int a[maxn], n;

void print_out() {
	for (int i = 0; i < n-1; i++) printf("%d ", a[i]);
	printf("%d\n", a[n-1]);
}

int main() {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		print_out();
		int v, j;
		for (int i = 1; i < n; i++) {
			v = a[i];
			j = i - 1;
			while (j >= 0 && a[j] > v) {
				a[j+1] = a[j];
				j--;
			}
			a[j+1] = v;
			print_out();
		}
	}
	return 0;
}
