#ifndef AVL_TREE
#define AVL_TREE

namespace saod
{


class TreeNode {

public: 
    TreeNode(int d);
    int data;
    int height;
    TreeNode * left, 
             * right;

    TreeNode * insert (TreeNode * node, int key);

};


TreeNode::TreeNode(int d)
{
    left = right = nullptr;
    height = 1;
    data = d;
}


/**********************************************************/


class Tree {

private: 
    TreeNode * root = nullptr;
    int _max(int a, int b);
    int height(TreeNode * n);
    int getBalance(TreeNode * n);

    TreeNode * rightRotate(TreeNode * y);
    TreeNode * leftRotate(TreeNode * x);

public: 
    TreeNode * insert(TreeNode * node);

};


TreeNode * Tree::insert(TreeNode * node)
{

}


int height(TreeNode * n)
{
    if (n == nullptr)
        return 0;
    return n->height;
}


int _max(int a, int b)
{
    return (a > b) ? a : b;
}


TreeNode * Tree::rightRotate(TreeNode * y)
{
    TreeNode * x = y->left;
    TreeNode * T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = _max(height(y->left), height(y->right) + 1);
    x->height = _max(height(x->left), height(x->right) + 1);

    return x;
}


TreeNode * Tree::leftRotate(TreeNode * x)
{
    TreeNode * y = x->right;
    TreeNode * T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = _max(height(x->left), height(x->right) + 1);
    y->height = _max(height(y->left), height(y->right) + 1);

    return y;
}


int Tree::getBalance(TreeNode * n)
{
    if (n == nullptr)
        return 0;
    return height(n->left) - height(n->right);
}







} // namespace saod

#endif // AVL_TREE