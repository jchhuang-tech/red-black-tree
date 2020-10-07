#pragma once
//include statements
#include <vector>
#include <iostream>


// template declaration
template <class T>
class NodeT {
public:
	T data;
	NodeT<T>* left;
	NodeT<T>* right;
	NodeT<T>* parent;
	bool isBlack;

	NodeT(T val)
	{
		data = val;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
		isBlack = false;
	}
};


// template declaration
template <class T>
class RedBlackTree {
public:
	RedBlackTree();
	RedBlackTree(const RedBlackTree& rbt);
	RedBlackTree& operator= (const RedBlackTree& rbt);
	~RedBlackTree();
	bool insert(const T val);
	bool remove(const T val);
	bool search(const T val) const;
	std::vector<T> search(T val1, T val2) const;
	std::vector<T> dump() const;
	int size() const;
	NodeT<T>* getRoot() const;




private:
	NodeT<T>* root;
	int msize;

	void destructorHelper(NodeT<T>* node);
	bool searchHelper1(const NodeT<T>* node, const T key) const;
	std::vector<T> searchHelper2(const NodeT<T>* node, const T key1, const T key2) const;
	std::vector<T> dumpHelper(const NodeT<T>* node) const;
	NodeT<T>* bstInsertHelper(NodeT<T>* node, NodeT<T>* pt);
	NodeT<T>* cloneHelper(const NodeT<T>* node) const;
	void rotateLeft(NodeT<T>* pt);
	void rotateRight(NodeT<T>* pt);

	NodeT<T>* findHelper(NodeT<T>* node, const T val) const;
	NodeT<T>* predecessor(NodeT<T>* node) const;
	void fix(NodeT<T>* x, NodeT<T>* xp, bool xIsLeft);
};

//RedBlackTree method implementations

//default constructor
template <class T>
RedBlackTree<T>::RedBlackTree()
{
	root = nullptr;
	msize = 0;
}

//copy constructor
template <class T>
RedBlackTree<T>::RedBlackTree(const RedBlackTree& rbt)
{
	root = cloneHelper(rbt.root);
	msize = rbt.msize;
}

//operator=
template <class T>
RedBlackTree<T>& RedBlackTree<T>::operator= (const RedBlackTree& rbt)
{
	if (this == &rbt) {//check for self assignment
		return *this;
	}
	destructorHelper(root);//make the calling object empty, free the memory
	root = cloneHelper(rbt.root);
	msize = rbt.msize;
	return *this;
}

template <class T>
RedBlackTree<T>::~RedBlackTree()
{
	destructorHelper(root);
}

template <class T>
bool RedBlackTree<T>::insert(const T val)
{
	
	if (search(val)) {//if the tree contains the parameter
		return false;
	}
	
	NodeT<T>* pt = new NodeT<T>(val);//pt is the node to be inserted

	root = bstInsertHelper(root, pt);//the normal BST insert method
	
	while (pt != root && pt->parent->isBlack == false) {//iterates until the root or a black parent is reached
		if (pt->parent == pt->parent->parent->left) {//pt's parent is a left child
			NodeT<T>* uncle = pt->parent->parent->right;//uncle is pt's uncle
			if (uncle != nullptr && uncle->isBlack == false) {//uncle is red, same as pt's parent
				pt->parent->isBlack = true;
				uncle->isBlack = true;
				pt->parent->parent->isBlack = false;
				pt = pt->parent->parent;//make pt the grandparent and repeat
			}
			else {//uncle is black
				if (pt == pt->parent->right) {
					pt = pt->parent;
					rotateLeft(pt);
				}
				pt->parent->isBlack = true;
				pt->parent->parent->isBlack = false;
				rotateRight(pt->parent->parent);//rebalance the tree
			}
		}
		else//pt's parent is a right child
		{
			NodeT<T>* uncle = pt->parent->parent->left;//pt's uncle
			if (uncle != nullptr && uncle->isBlack == false) {//uncle is red
				pt->parent->isBlack = true;
				uncle->isBlack = true;
				pt->parent->parent->isBlack = false;
				pt = pt->parent->parent;//make pt the grandparent and repeat
			}
			else//uncle is black
			{
				if (pt == pt->parent->left) {
					pt = pt->parent;
					rotateRight(pt);
				}
				pt->parent->isBlack = true;
				pt->parent->parent->isBlack = false;
				rotateLeft(pt->parent->parent);//rebalance the tree
			}
		}
	}

	root->isBlack = true;
	

	return true;
}

template <class T>
bool RedBlackTree<T>::remove(const T val)
{
	if (!search(val)) {//if the tree doesnt contain the parameter
		return false;
	}

	NodeT<T>* z = findHelper(root, val);//z is the node that contains the data to be removed
	NodeT<T>* y;

	if (z->left == nullptr || z->right == nullptr) {//if z has one or no children
		y = z;
	}
	else {//if z has two children
		y = predecessor(z);//y is the node that contains the data to replace z
	}

	NodeT<T>* x;
	NodeT<T>* xp;//xp is x's parent
	bool xIsLeft;//xIsLeft is true when x is a left child
	if (y->left != nullptr) {//identify if y's only child is right or left
		x = y->left;
		xp = y;
		xIsLeft = 1;
	}
	else {
		x = y->right;
		xp = y;
		xIsLeft = 0;
	}

	if (x) {
		x->parent = y->parent;//detach x form y
		xp = y->parent;
		xIsLeft = (x == y->left);
	}

	if (y->parent == nullptr) {//y is the root
		root = x;
	}
	else {
		//attach x to y's parent
		if (y == y->parent->left) {//y is a left child
			y->parent->left = x;
			xp = y->parent;
			xIsLeft = 1;
		}
		else {
			y->parent->right = x;
			xp = y->parent;
			xIsLeft = 0;
		}
	}

	if (y != z) {//y has conceptually been moved up
		z->data = y->data;//replace z with y
	}

	if (y->isBlack == true) {
		fix(x, xp, xIsLeft);
	}

	delete y;//free the memory
	msize--;

	return true;
}

template <class T>
bool RedBlackTree<T>::search(const T val) const
{
	return searchHelper1(root, val);
}

template <class T>
std::vector<T> RedBlackTree<T>::search(T val1, T val2) const
{
	if (val1 > val2) {//if val1 is larger than val2, swap them
		T temp = val1;
		val1 = val2;
		val2 = temp;
	}
	return searchHelper2(root, val1, val2);
}

template <class T>
std::vector<T> RedBlackTree<T>::dump() const
{
	return dumpHelper(root);
}

template <class T>
int RedBlackTree<T>::size() const
{
	return msize;
}

template <class T>
NodeT<T>* RedBlackTree<T>::getRoot() const
{
	return root;
}

//helper function for the destructor
template <class T>
void RedBlackTree<T>::destructorHelper(NodeT<T>* node)
{
	if (node) {
		destructorHelper(node->left);
		destructorHelper(node->right);
		delete node;
	}
}

//helper function for the first search function
template <class T>
bool RedBlackTree<T>::searchHelper1(const NodeT<T>* node, const T key) const
{
	if (node == NULL)
		return false;

	if (node->data == key)
		return true;

	// if key is smaller than node, then recur on left subtree
	if (key < node->data) {
		bool res1 = searchHelper1(node->left, key);
		return res1;
	}
	else {// if key is greater than node, then recur on right subtree
		bool res2 = searchHelper1(node->right, key);
		return res2;
	}
}

//helper function for the second search function
template <class T>
std::vector<T> RedBlackTree<T>::searchHelper2(const NodeT<T>* node, const T key1, const T key2) const
{
	std::vector<T> result;

	if (node) {
		std::vector<T> left = searchHelper2(node->left, key1, key2);//recur on the left subtree, and put the results in the vector
		result.insert(result.end(), left.begin(), left.end());

		if (node->data >= key1 && node->data <= key2) {
			result.push_back(node->data);
		}

		std::vector<T> right = searchHelper2(node->right, key1, key2);//recur on the right subtree, and put the results in the vector
		result.insert(result.end(), right.begin(), right.end());
	}

	return result;
}

//helper function for the dump function
template <class T>
std::vector<T> RedBlackTree<T>::dumpHelper(const NodeT<T>* node) const
{
	std::vector<T> result;

	if (node) {
		std::vector<T> left = dumpHelper(node->left);//recur on the left subtree, and put the results in the vector
		result.insert(result.end(), left.begin(), left.end());

		result.push_back(node->data);//put the data in the vector

		std::vector<T> right = dumpHelper(node->right);//recur on the right subtree, and put the results in the vector
		result.insert(result.end(), right.begin(), right.end());
	}

	return result;
}

//the standard BST insertion function
template <class T>
NodeT<T>* RedBlackTree<T>::bstInsertHelper(NodeT<T>* node, NodeT<T>* pt)
{
	if (node == nullptr)//trivial case
	{
		node = pt;
		msize++;
		return node;
	}

	if (pt->data > node->data)//if the data to be inserted is larger than node, recur on the right subtree
	{
		node->right = bstInsertHelper(node->right, pt);
		node->right->parent = node;
	}
	else//if the data to be inserted is smaller than node, recur on the left subtree
	{
		node->left = bstInsertHelper(node->left, pt);
		node->left->parent = node;
	}

	return node;
	
}

//clone the tree
template <class T>
NodeT<T>* RedBlackTree<T>::cloneHelper(const NodeT<T>* node) const
{
	if (node == nullptr) {
		return nullptr;
	}

	//create new node and make it a copy of 'node'
	NodeT<T>* newnode = new NodeT<T>(node->data);
	newnode->data = node->data;    //copying data
	newnode->isBlack = node->isBlack;
	newnode->left = cloneHelper(node->left);    //cloning left child
	if (newnode->left) {
		newnode->left->parent = newnode;
	}
	newnode->right = cloneHelper(node->right);  //cloning right child
	if (newnode->right) {
		newnode->right->parent = newnode;
	}
	return newnode;
}


template <class T>
void RedBlackTree<T>::rotateLeft(NodeT<T>* pt)
{
	//pt is the node to be rotated
	NodeT<T>* pt_right = pt->right;//a pointer to the right node

	pt->right = pt_right->left;

	if (pt->right != NULL) {//set pt's right child's parent reference
		pt->right->parent = pt;
	}
	pt_right->parent = pt->parent;//set pt_right's parent reference

	//set child reference of pt's parent
	if (pt->parent == NULL) {//pt was root
		root = pt_right;
	}
	else if (pt == pt->parent->left) {//left child
		pt->parent->left = pt_right;
	}
	else {
		pt->parent->right = pt_right;
	}
	//make pt pt_right's left child
	pt_right->left = pt;
	pt->parent = pt_right;
}

template <class T>
void RedBlackTree<T>::rotateRight(NodeT<T>* pt)
{
	//pt is the node to be rotated
	NodeT<T>* pt_left = pt->left;//a pointer to the left node

	pt->left = pt_left->right;

	if (pt->left != NULL) {//set pt's left child's parent reference
		pt->left->parent = pt;
	}
	pt_left->parent = pt->parent;//set pt_left's parent reference

	//set child reference of pt's parent
	if (pt->parent == NULL){//pt was root
		root = pt_left;
	}
	else if (pt == pt->parent->left) {//left child
		pt->parent->left = pt_left;
	}
	else {
		pt->parent->right = pt_left;
	}
	//make pt pt_left's right child
	pt_left->right = pt;
	pt->parent = pt_left;
}

template <class T>
NodeT<T>* RedBlackTree<T>::findHelper(NodeT<T>* node, const T val) const //the function used to find a node and return it
{
	if (node != nullptr) {
		if (node->data == val) {//the node is found
			return node;
		}
		else {//if the node is not found
			NodeT<T>* foundNode = findHelper(node->left, val);//recur on the left subtree
			if (foundNode == nullptr) {//if the node is still not found
				foundNode = findHelper(node->right, val);//recur on the right tree
			}
			return foundNode;//return the node, if it's found; or return nullptr if it's not found
		}
	}
	else {
		return nullptr;//trivial case
	}
}

template <class T>
NodeT<T>* RedBlackTree<T>::predecessor(NodeT<T>* node) const //find node's predecessor
{
	NodeT<T>* tmp = node->left;
	while (tmp->right) {
		tmp = tmp->right;//find the node with the largest value in the left subtree
	}
	return tmp;
}


template <class T>
void RedBlackTree<T>::fix(NodeT<T>* x, NodeT<T>* xp, bool xIsLeft)//x is the node to be fixed, xp is x's parent, xIsLeft is true when x is a left child
{
	while (x != root && (x == nullptr || x->isBlack == true)) {//
		if (xIsLeft) {//x is a left child
			NodeT<T>* y = xp->right;//x's sibling
			if (y->isBlack == false) {//y is red
				y->isBlack = true;
				xp->isBlack = false;//x's parent must have been black since y is red
				rotateLeft(xp);
				y = xp->right;
			}

			if ((y->left == nullptr || y->left->isBlack == true) && (y->right == nullptr || y->right->isBlack == true)) {//y has two black children
				y->isBlack = false;
				x = xp;
				xp = x->parent;
				xIsLeft = (x == xp->left);
			}
			else {//y has at least 1 red child
				if (y->right == nullptr || y->right->isBlack == true) {// y's right child is black
					y->left->isBlack = true;
					y->isBlack = false;
					rotateRight(y);
					y = xp->right;
				}
				y->isBlack = xp->isBlack;
				xp->isBlack = true;
				if (y->right) {
					y->right->isBlack = true;
				}
				rotateLeft(xp);
				x = root;
			}
		}
		else {//x is a right child
			//symmetric
			NodeT<T>* y = xp->left;
			if (y->isBlack == false) {//y is red
				y->isBlack = true;
				xp->isBlack = false;//x's parent must have been black since y is red
				rotateRight(xp);
				y = xp->left;
			}

			if ((y->right == nullptr || y->right->isBlack == true) && (y->left == nullptr || y->left->isBlack == true)) {//y has two black children
				y->isBlack = false;
				x = xp;
				xp = x->parent;
				xIsLeft = (x == xp->left);
			}
			else {//y has at least 1 red children
				if (y->left == nullptr || y->left->isBlack == true) {//y's left child is black
					y->right->isBlack = true;
					y->isBlack = false;
					rotateLeft(y);
					y = xp->left;
				}
				y->isBlack = xp->isBlack;
				xp->isBlack = true;
				if (y->left) {
					y->left->isBlack = true;
				}
				rotateRight(xp);
				x = root;
			}
		}
	}
	x->isBlack = true;
}