# include <cstdio>
# include <cstring>
# include <algorithm>
using namespace std;

static const int maxn = 36 + 2;

struct Card {
    char s;
    int v;
};

void _out(Card a[], int n) {
    for (int i = 0; i < n-1; i++)
        printf("%c%d ", a[i].s, a[i].v);
    printf("%c%d\n", a[n-1].s, a[n-1].v);
}

void bubbleSort(Card a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = n-1; j >= i+1; j--)
            if (a[j].v < a[j-1].v) swap(a[j], a[j-1]);
    }
}

void selectionSort(Card a[], int n) {
    int minj;
    for (int i = 0; i < n; i++) {
        minj = i;
        for (int j = i; j < n; j++) {
            if (a[j].v < a[minj].v)
                minj = j;
        }
        swap(a[i], a[minj]);
    }
}

bool isStable(Card a[], Card b[], int n) {
    bool stable = true;
    for (int i = 0; i < n; i++) {
        if (a[i].s != b[i].s) {
            stable = false;
            break;
        }
    }
    return stable;
}

int main() {
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
    int n;
    Card b[maxn], s[maxn];
    while (scanf("%d", &n) == 1) {
        char buf[5];
        for (int i = 0; i < n; i++) {
            scanf("%s", buf);
            b[i].s = buf[0];
            b[i].v = buf[1] - '0';
            s[i].s = buf[0];
            s[i].v = buf[1] - '0';
        }
        bubbleSort(b, n);
        _out(b, n); printf("Stable\n");
        selectionSort(s, n);
        _out(s, n);
        if (isStable(b, s, n))
            printf("Stable\n");
        else
            printf("Not stable\n");
    }
    return 0;
}
