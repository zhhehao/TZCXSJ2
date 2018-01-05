# include <cstdio>
# include <cstring>

int ri, rj, ans, n;

int main(void) {
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
    while (scanf("%d", &n) == 1) {
        scanf("%d%d", &ri, &rj);
        ans = rj - ri;
        int t, na;
        int len = n - 2;
        for (int i = 0; i < len; i++) {
            scanf("%d", &t);
            if (t > rj) {
                rj = t;
                na = rj - ri;
                if (na > ans) ans = na;
            }
            else if (t < ri) {
                ri = t;
                if (i != len - 1) {
                    scanf("%d", &rj);
                    na = rj - ri;
                    if (na > ans) ans = na;
                    i++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
