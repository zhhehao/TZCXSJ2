/*
**
*/

# include <cstdio>
# define NIL -1
# define MAX 30

struct Node {
    int parent, left, right;
} t[MAX];

int n, d[MAX], h[MAX], dgree[MAX];

void init_tree() { // 所有节点的父节点都设置为NIL
    for (int i = 0; i < n; i++) {
        t[i].parent = NIL;
    }
}

void create_tree() { // 设置所有节点的父节点和子节点
    int i, l, r;
    for (int j = 0; j < n; j++) {
        scanf("%d%d%d", &i, &l, &r);
        t[i].left = l;
        t[i].right = r;
        int dg = 0;
        if (l != NIL) {
            t[l].parent = i;
            dg++;
        }
        if (r != NIL) {
            t[r].parent = i;
            dg++;
        }
        dgree[i] = dg;
    }
}

void set_depth(int u, int dd) {
    if (u == NIL)
        return;
    d[u] = dd;
    set_depth(t[u].left, dd + 1);
    set_depth(t[u].right, dd + 1);
}

int set_height(int u) {
    int h1 = 0, h2 = 0;
    if (t[u].left != NIL)
        h1 = set_height(t[u].left) + 1;
    if (t[u].right != NIL)
        h2 = set_height(t[u].right) + 1;

    return h[u] = (h1 > h2 ? h1 : h2);
}

int getsibling(int u) {
    if (t[u].parent == NIL)
        return NIL;
    if (t[t[u].parent].left != u && t[t[u].parent].left != NIL)
        return t[t[u].parent].left;
    if (t[t[u].parent].right != u && t[t[u].parent].right != NIL)
        return t[t[u].parent].right;
    return NIL;
}

void print_tree() {
    for (int i = 0; i < n; i++) {
        printf("node %d: ", i);
        printf("parent = %d, ", t[i].parent);
        printf("sibling = %d, ", getsibling(i));
        printf("degree = %d, ", dgree[i]);
        printf("depth = %d, ", d[i]);
        printf("height = %d, ", h[i]);
        if (t[i].parent == NIL) {
            printf("root\n");
        }
        else if (t[i].left == NIL && t[i].right == NIL) {
            printf("leaf\n");
        }
        else {
            printf("internal node\n");
        }
    }
}

int main () {
    // freopen("infile", "r", stdin);
    // freopen("outfile", "w", stdout);
    scanf("%d", &n); 
        init_tree();
        create_tree();
        int root;
        for (root = 0; root < n; root++) { // 寻找根节点
            if (t[root].parent == NIL)
                break;
        }
        set_depth(root, 0);
        set_height(root);
        print_tree();
    
    return 0;
}