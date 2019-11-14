#ifndef SAOD_TREE
#define SAOD_TREE
#include <iostream>

namespace saod
{


class TreeNode {

	private:
		std::string fun; // function
		std::string op;  // operation
		std::string var; // variable

		TreeNode * left; // if unary, left is nullptr
		TreeNode * right;

	public:
		TreeNode(std::string function, std::string operation, std::string variable);
		bool isFunction() { return fun.size() != 0; }
		bool isOperation() { return op.size() != 0; }
		bool isVariable() { return var.size() != 0; }

		void addLeftChild(TreeNode * l) { left = l; }
		void addRightChild(TreeNode * r) { right = r; }

		std::string toString();
};


TreeNode::TreeNode(std::string function, std::string operation, std::string variable)
{
	fun = function;
	op = operation;
	var = variable;
}


std::string TreeNode::toString()
{
	if (isFunction())
		return fun + "(" + right->toString() + ")";
	else if (isVariable())
		return var;
	else if (isOperation())
	{
		if (left != nullptr)
			if (op == "+" || op == "-")
				return "(" + left->toString() + op + right->toString() + ")";
			else 
				return left->toString() + op + right->toString();
		else 
			return "(" + op + right->toString() + ")";
	}

}



/****************************************************************************/



class Tree {

	private:
		TreeNode * root = nullptr;

	public: 
		Tree() 
		{
			fill();
			std::cout << toString() << std::endl;
		};
		void fill();
		std::string toString();


};



void Tree::fill ()
{
	auto n1 = new TreeNode("", "-", "");
	root = n1;

	auto n2 = new TreeNode("", "-", "");
	root->addLeftChild(n2);

	auto n3 = new TreeNode("", "+", "");
	n2->addRightChild(n3);

	auto n4 = new TreeNode("", "*", "");
	n3->addLeftChild(n4);

	auto n5 = new TreeNode("", "", "a1");
	n4->addLeftChild(n5);

	auto n6 = new TreeNode("", "", "bar");
	n4->addRightChild(n6);

	auto n7 = new TreeNode("", "", "c");
	n3->addRightChild(n7);

	auto n8 = new TreeNode("", "-", "");
	n1->addRightChild(n8);

	auto n9 = new TreeNode("SIN", "", "");
	n8->addLeftChild(n9);

	auto n10 = new TreeNode("", "", "dors");
	n9->addRightChild(n10);

	auto n11 = new TreeNode("", "", "e");
	n8->addRightChild(n11);
}


std::string Tree::toString()
{
	return root->toString();
}




} // namespace saod

#endif // SAOD_TREE