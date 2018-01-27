/*
** 树的先序遍历，中序遍历，后序遍历
*/

# include <cstdio>
# define MAX 30
# define NIL -1

struct Node {
    int parent, left, right;
} tree[MAX];

int n;

void createTree() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        tree[i].parent = NIL;
    }

    int u, l, r;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &u, &l, &r);
        tree[u].left = l;
        tree[u].right = r;
        if (l != NIL) {
            tree[tree[u].left].parent = u;
        }
        if (r != NIL) {
            tree[tree[u].right].parent = u;
        }
    }
}

void Preorder(int u) {
    if (u == NIL)
        return;
    printf(" %d", u);
    Preorder(tree[u].left);
    Preorder(tree[u].right);
}

void Inorder(int u) {
    if (u == NIL)
        return;
    Inorder(tree[u].left);
    printf(" %d", u);
    Inorder(tree[u].right);
}

void Postorder(int u) {
    if (u == NIL)
        return;
    Postorder(tree[u].left);
    Postorder(tree[u].right);
    printf(" %d", u);
}

int getRoot() {
    for (int i = 0; i < n; i++) {
        if (tree[i].parent == NIL)
            return i;
    }
}

void printTree() {
    int root = getRoot();

    printf("Preorder\n");
    Preorder(root);
    printf("\n");

    printf("Inorder\n");
    Inorder(root);
    printf("\n");

    printf("Postorder\n");
    Postorder(root);
    printf("\n");
}

int main() {
    // freopen("infile", "r", stdin);
    // freopen("outfile", "w", stdout);

    createTree();
    printTree();

    return 0;
}