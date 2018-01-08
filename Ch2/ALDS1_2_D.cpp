#include <cstdio>

static const int maxn = 1000000 + 10;
int n, a[maxn], m, G[maxn];

void get_step(){
    if (n <= 3) {
        m = 1;
        G[0] = 1;
        return;
    }
    G[0] = n / 2;
    for (m = 1; m < n; m++) {
        G[m] = G[m-1] / 2;
        if (G[m] == 1)
            break;
    }
    m++;
}

void _out1(){
    printf("%d\n", m);
    for (int i = 0; i < m-1; i++)
        printf("%d ", G[i]);
    printf("%d\n", G[m-1]);
}

int insertionSort(int g){
    int cnt = 0, v, j;
    for (int i = g; i < n; i++) {
        v = a[i];
        j = i - g;
        while (j >= 0 && a[j] > v) {
            a[j+g] = a[j];
            j = j - g;
            cnt++;
        }
        a[j+g] = v;
    }
    return cnt;
}

int shellSort(){
    int cnt = 0;
    for (int i = 0; i < m; i++)
        cnt += insertionSort(G[i]);
    return cnt;
}

void _out2(){
    for (int i = 0; i < n; i++)
        printf("%d\n", a[i]);
}

int main(){
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
    while(scanf("%d", &n) == 1){
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        get_step();
        _out1();
        printf("%d\n", shellSort());
        _out2();
    }
    return 0;
}
