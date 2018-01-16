/*
** 科赫曲线
*/

# include <cstdio>
# include <cmath>
#define M_PI 3.14159265358979323846

int n;

struct PointPair {
    double x, y;
};

void koch(int k, PointPair p1, PointPair p2) {
    if (k == 0)
        return;
    PointPair s, u, t;
    double th = M_PI * 60.0 / 180.0;
    s.x = (2.0 * p1.x + 1.0 * p2.x) / 3.0;
    s.y = (2.0 * p1.y + 1.0 * p2.y) / 3.0;
    t.x = (1.0 * p1.x + 2.0 * p2.x) / 3.0;
    t.y = (1.0 * p1.y + 2.0 * p2.y) / 3.0;
    u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
    u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;
    

    koch(k - 1, p1, s);
    printf("%.8f %.8f\n", s.x, s.y);
    koch(k - 1, s, u);
    printf("%.8f %.8f\n", u.x, u.y);
    koch(k - 1, u, t);
    printf("%.8f %.8f\n", t.x, t.y);
    koch(k - 1, t, p2);
}

int main() {
    // freopen("infile", "r", stdin);
    // freopen("outfile", "w", stdout);
    scanf("%d", &n);
    PointPair p1, p2;
    p1.x = 0.0;
    p1.y = 0.0;
    p2.x = 100.0;
    p2.y = 0.0;
    printf("%.8f %.8f\n", p1.x, p1.y);
    koch(n, p1, p2);
    printf("%.8f %.8f\n", p2.x, p2.y);
    return 0;
}