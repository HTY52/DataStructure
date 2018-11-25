#include <iostream>
#include <cstdlib>

//判断二叉树的高度
using namespace std;

typedef struct a{
    char data;
    struct a * lchild;
    struct a * rchild;
}treeNode;

//创建二叉树,以字符'^'表示空节点
treeNode * CreateTree(treeNode * node) {
    char ch;
    cin >> ch;
    if (ch == '^') {
        return nullptr;
    } else {
        node = (treeNode *)malloc(sizeof(treeNode));
        node->data = ch;
        node->lchild = CreateTree(node->lchild);
        node->rchild = CreateTree(node->rchild);
    }
    return node;
}

void DestoryTree(treeNode *& node) {
    if (node) {
        DestoryTree(node->lchild);
        DestoryTree(node->rchild);
        free(node);
    }
}

int TreeOfHeight(treeNode * root) {
    int lHeight, rHeight;
    if (!root) {
        return 0;
    } else {
        lHeight = TreeOfHeight(root->lchild);
        rHeight = TreeOfHeight(root->rchild);
        return lHeight > rHeight ? lHeight + 1 : rHeight + 1;
    }
}

//先序遍历
//先访问根，然后访问左子树,最后右子树
void PreOrder(treeNode * root) {
    if (root) {
        cout << root->data;
        PreOrder(root->lchild);
        PreOrder(root->rchild);
    }
}

//中序遍历
//先访问左子树,在访问根,最后右子树
void InOrder(treeNode * root) {
    if (root) {
        InOrder(root->lchild);
        cout << root->data;
        InOrder(root->rchild);
    }
}

//后序遍历
//先访问左子树,然后访问右子树,最后根
void PostOrder(treeNode * root) {
    if (root) {
        PostOrder(root->lchild);
        PostOrder(root->rchild);
        cout << root->data;
    }
}
//括号法输出树
void DispTree(treeNode * node) {
    if (node) {
        cout << node->data;
        if (node->lchild || node->rchild) {
            cout << "(";
            DispTree(node->lchild);
            if (node->rchild) {
                cout << ",";
            }
            DispTree(node->rchild);
            cout << " )";
        }
    }
}

int main() {

    treeNode * root = nullptr;
    root = CreateTree(root);

    DispTree(root);

    cout << endl << "树高：" << TreeOfHeight(root) << endl;
    cout << "先序遍历：";
    PreOrder(root);
    cout << endl;
    cout << "中序遍历：";
    InOrder(root);
    cout << endl;
    cout << "后序遍历：";
    PostOrder(root);
    cout << endl;
    return 0;
}
