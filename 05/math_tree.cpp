#ifndef MATH_TREE
#define MATH_TREE
#include <iostream>
#include <vector>


namespace saod
{


class TreeNode {

    private: 
        double num = 0; // number
        char op = 0; // operation
        std::vector<TreeNode*> children;

    public: 
        TreeNode(double n, char o) { num = n; op = o; };
        TreeNode(char o) { num = -1; op = o; };
        TreeNode(double n) { num = n; op = 0; };

        bool isOperation() { return op != 0; }
        bool isOperator() { return op == 0; }
        char getOperation() { return op; }
        double getNumber() { return num; }

        void addChild(TreeNode * child) { children.push_back(child); }

        double solve();
};


double TreeNode::solve()
{
    if (isOperation()) 
    {
        // perform unary operation
        if (children.size() == 1) {
            if (op == '-') 
                return -1 * children[0]->solve();
            else 
                return children[0]->solve();
        }
        else { 
            int i = 0;
            double res = children.at(i++)->solve();

            while (i < children.size())
            {
                if (op == '+')
                    res += children.at(i++)->solve();
                else if (op == '-')
                    res -= children.at(i++)->solve();
                else if (op == '*')
                    res *= children.at(i++)->solve();
                else 
                    res /= children.at(i++)->solve();
            }
            return res;
        }
    }
    else 
        return num;
}




/*****************************************************************/




class Tree {

    private: 
        TreeNode * root = nullptr;


    public:
        Tree() {};
        void fill();
        double solve() { return root->solve(); }

};




void Tree::fill()
{
    auto n1 = new TreeNode('*');
    root = n1;

    auto n2 = new TreeNode('+');
    n1->addChild(n2);

    n2->addChild(new TreeNode(1.0));
    n2->addChild(new TreeNode(2.0));

    n1->addChild(new TreeNode(7.0));
}








} // namespace saod

#endif // MATH_TREE