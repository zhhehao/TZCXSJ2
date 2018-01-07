# include <cstdio>
# include <algorithm>
using namespace std;

static const int maxn = 100 + 2;
int n, a[maxn], cnt;

void put_out() {
    for (int i = 0; i < n-1; i++) printf("%d ", a[i]);
    printf("%d\n%d\n", a[n-1], cnt);
}

void bubblesort() {
	int flag = 1;
	int j = 0;
	while (flag) {
		flag = 0;
		for (int i = n-1; i >= j+1; i--) {
			if (a[i] < a[i-1]) {
				swap(a[i], a[i-1]);
				flag = 1;
				cnt++;
			}
		}
		j++;
	}
}

int main() {
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        cnt = 0;
        bubblesort();
        put_out();
    }
    return 0;
}
