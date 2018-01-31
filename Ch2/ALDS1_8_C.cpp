/*
** 二叉搜索树的插入
** 中序和前序输出
*/

# include <cstdio>
# include <cstdlib>
# include <cstddef>

struct Node {
    int key;
    Node *parent, *left, *right;
};

Node *root;

void inorder(Node *u) {
    if (u == NULL)
        return;
    inorder(u->left);
    printf(" %d", u->key);
    inorder(u->right);
}

void preorder(Node *u) {
    if (u == NULL)
        return;
    printf(" %d", u->key);
    preorder(u->left);
    preorder(u->right);
}

void insertNode(int k) {
    Node *y = NULL;
    Node *x = root;

    Node *z = (Node *)malloc(sizeof(Node));
    z->key = k;
    z->left = NULL;
    z->right = NULL;

    while (x != NULL) {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;

    if (y == NULL)
        root = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;
}

bool findNode(int k) {
    Node *x = root;
    while (x != NULL) {
        if (k == x->key)
            return true;
        if (k < x->key)
            x = x->left;
        else
            x = x->right;
    }
    return false;
}

Node * findKey(int key) {
    Node *u = root;
    while (u != NULL && key != u->key) {
        if (key < u->key) {
            u = u->left;
        }
        else {
            u = u->right;
        }
    }
    return u;
}

Node * getMinimum(Node *u) {
    while (u->left != NULL) {
        u = u->left;
    }
    return u;
}

Node * getSuccessor(Node *u) {
    if (u->right != NULL)
        return getMinimum(u->right);

    Node *y = u->parent;
    while (y != NULL && u == y->right) {
        u = y;
        y = y->parent;
    }
    return y;
}

void deleteNode(Node *u) {
    Node *y = NULL;
    Node *x = NULL;

    if (u->left == NULL || u->right == NULL) {
        y = u;
    }
    else {
        y = getSuccessor(u);
    }

    if (y->left != NULL) {
        x = y->left;
    }
    else
    {
        x = y->right;
    }

    if (x != NULL) {
        x->parent = y->parent;
    }

    if (y->parent == NULL) {
        root = x;
    }
    else if (y == (y->parent)->left) {
        (y->parent)->left = x;
    }
    else {
        (y->parent)->right = x;
    }

    if (y != u) {
        u->key = y->key;
    }

    free(y);
}

void solve() {
    int n, x;
    char com[10];

    root = NULL;

    scanf("%d", &n);    
    for (int i = 0; i < n; i++) {
        scanf("%s", com);
        if (com[0] == 'i') {
            scanf("%d", &x);
            insertNode(x);
        }
        else if (com[0] == 'f') {
            scanf("%d", &x);
            if (findNode(x))
                printf("yes\n");
            else
                printf("no\n");
        }
        else if (com[0] == 'd') {
            scanf("%d", &x);
            deleteNode(findKey(x));
        }
        else {
            inorder(root);
            printf("\n");
            preorder(root);
            printf("\n");
        }
    }
}

int main() {
    // freopen("infile", "r", stdin);
    // freopen("outfile", "w", stdout);
    solve();
    return 0;
}