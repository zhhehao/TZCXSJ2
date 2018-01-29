/*
** 通过先序遍历和中序遍历，重建树，并输出后序遍历
** 本例题的解法并没有生成树，而是一次到位生成了后序遍历
*/

# include <iostream>
# include <algorithm>
# include <vector>
# include <cstdio>
using namespace std;

int n, pos;
vector<int> pre, in, post;

void init() {
    scanf("%d", &n);
    int node;
    for (int i = 0; i < n; i++) {
        scanf("%d", &node);
        pre.push_back(node);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &node);
        in.push_back(node);
    }
}

void rec(int l, int r) {
    if (l >= r)
        return;
    int root = pre[pos++];
    int m = distance(in.begin(), find(in.begin(), in.end(), root));
    rec(l, m);
    rec(m + 1, r);
    post.push_back(root);
}

void solve() {
    pos = 0;
    rec(0, pre.size());
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", post[i]);
    }
    printf("%d\n", post[n - 1]);
}

int main() {
    // freopen("infile", "r", stdin);
    // freopen("outfile", "w", stdout);
    init();
    solve();
    return 0;
}