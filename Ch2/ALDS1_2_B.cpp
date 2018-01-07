# include <cstdio>
# include <iostream>
using namespace std;

static const int maxn = 100 + 2;

int selectionSort(int a[], int n) {
	int minj, sw = 0;
	for (int i = 0; i < n; i++) {
		minj = i;
		for (int j = i; j < n; j++) {
			if (a[j] < a[minj])
				minj = j;
		}
		if (a[i] != a[minj]) {
			swap(a[i], a[minj]);
			sw++;
		}
	}
	return sw;
}

int main() {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int n, a[maxn];
	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		int sw = selectionSort(a, n);
		for (int i = 0; i < n-1; i++)
			printf("%d ", a[i]);
		printf("%d\n%d\n", a[n-1], sw);
	}
	return 0;
}
