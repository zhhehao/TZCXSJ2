/*
** 左子右兄弟表示法
*/

# include <cstdio>
# include <vector>
using namespace std;

const int maxn = 100000 + 10;
const int NIL = -1;

struct Node {
    int p, l, r;
} t[maxn];

int n;

int getDepth(int u) {
    int d = 0;
    while (t[u].p != NIL) {
        ++d;
        u = t[u].p;
    }
    return d;
}

int main() {
    // freopen("infile", "r", stdin);
    // freopen("outfile", "w", stdout);

    scanf("%d", &n);

        /*
        ** 此段为根据输入存储有根树
        */
    for (int i = 0; i < n; i++) { // 初始化有根树
        t[i].p = NIL;
        t[i].l = NIL;
        t[i].r = NIL;
    }
    int id, k;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &id, &k);
        if (k == 0)
        {
            // t[id].l = NIL; // 此为叶节点
            continue;
        }
        int cid;
        vector<int> vc;
        vc.resize(0); // 初始化子节点vector
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &cid);
            vc.push_back(cid);
        }
        t[id].l = vc[0]; // 左子节点
        for (int j = 0; j < vc.size(); j++)
        {
            t[vc[j]].p = id; // 父节点
            if (j < vc.size() - 1)
            {
                t[vc[j]].r = vc[j + 1]; // 兄弟节点
            }
        }
        t[vc[vc.size() - 1]].r = NIL; // 没有兄弟节点
    }

        /*
        ** 以下为依照顺序输出节点信息。
        */
        for (int i = 0; i < n; i++) {
            printf("node %d: parent = %d, depth = %d, ", i, t[i].p, getDepth(i));
            if (t[i].p == NIL) {
                printf("root, ");
            }
            else if (t[i].l == NIL) {
                printf("leaf, ");
            }
            else {
                printf("internal node, ");
            }
            printf("[");
            if (t[i].l != NIL) {
                int u = t[i].l;
                int flag = 0;
                while (true) {
                    if (flag++ != 0)
                        printf(", ");
                    printf("%d", u);
                    if (t[u].r == NIL)
                        break;
                    u = t[u].r; 
                }
            }
            printf("]\n");
        }
            
    return 0;
}