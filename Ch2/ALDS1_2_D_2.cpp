#include <cstdio>
#include <vector>
using namespace std;

static const int maxn = 1000000 + 10;
int n, a[maxn];
vector <int> G;

void get_step(){
    G.resize(0);
    for (int i = 1; ;) {
        G.push_back(i);
        i = 3 * i + 1;
        if (i > n) break;
    }
}

void _out1(){
    printf("%d\n", G.size());
    for (int i = G.size()-1; i > 0; i--)
        printf("%d ", G[i]);
    printf("%d\n", G[0]);
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
    for (int i = G.size()-1; i >= 0; i--)
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
