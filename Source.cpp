#include "RedBlackTree.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	cout << "TEST INT" << endl;
	RedBlackTree<int> rbt;

	//test insert
	rbt.insert(5);
	cout << "insert test: " << rbt.getRoot()->data << endl;
	cout << "insert 5, size: " << rbt.size() << endl;
	//rbt.preorderHelper(rbt.getRoot());
	cout << endl;

	rbt.insert(7);
	cout << "insert 7, size: " << rbt.size() << endl;
	//rbt.preorderHelper(rbt.getRoot());
	cout << endl;

	rbt.insert(6);
	cout << "insert 6, size: " << rbt.size() << endl;
	//rbt.preorderHelper(rbt.getRoot());
	cout << endl;

	rbt.insert(8);
	cout << "insert 8, size: " << rbt.size() << endl;
	//rbt.preorderHelper(rbt.getRoot());
	cout << endl;

	rbt.insert(8);
	cout << "insert 8, size: " << rbt.size() << endl;
	//rbt.preorderHelper(rbt.getRoot());
	cout << endl;

	rbt.insert(10);
	cout << "insert 10, size: " << rbt.size() << endl;
	//rbt.preorderHelper(rbt.getRoot());
	cout << endl;

	rbt.insert(9);
	cout << "insert 9, size: " << rbt.size() << endl;
	//rbt.preorderHelper(rbt.getRoot());
	cout << endl;

	rbt.insert(3);
	cout << "insert 3, size: " << rbt.size() << endl;
	//rbt.preorderHelper(rbt.getRoot());
	cout << endl;

	rbt.insert(4);
	cout << "insert 4, size: " << rbt.size() << endl;
	//rbt.preorderHelper(rbt.getRoot());
	cout << endl;

	//test dump
	vector<int> d = rbt.dump();
	cout << "Inorder dump: " << endl;
	for (std::vector<int>::const_iterator i = d.begin(); i != d.end(); ++i)
		std::cout << *i << ' ';

	//test copy constructor
	RedBlackTree<int> rbt2(rbt);
	cout << endl << "rbt2(copy): " << endl;
	cout << "Inorder: " << endl;
	//rbt2.inorderHelper(rbt2.getRoot());
	cout << endl << "Preorder: " << endl;
	//rbt2.preorderHelper(rbt2.getRoot());


	//test operator=
	RedBlackTree<int> rbt3 = rbt;
	cout << endl << "rbt3(operator=): " << endl;
	cout << "Inorder: " << endl;
	//rbt3.inorderHelper(rbt3.getRoot());
	cout << endl << "Preorder: " << endl;
	//rbt3.preorderHelper(rbt3.getRoot());


	//test search 1
	cout << endl << "search 4(true): " << rbt.search(4) << endl;
	cout << "search 5(true): " << rbt.search(5) << endl;
	cout << "search 3(true): " << rbt.search(3) << endl;
	cout << "search 6(true): " << rbt.search(6) << endl;
	cout << "search 8(true): " << rbt.search(8) << endl;
	cout << "search 4(true): " << rbt.search(4) << endl;
	cout << "search 10(true): " << rbt.search(10) << endl;
	cout << "search 9(true): " << rbt.search(9) << endl;
	cout << "search 7(true): " << rbt.search(7) << endl;
	cout << "search 2(false): " << rbt.search(2) << endl;
	cout << "search 1(false): " << rbt.search(1) << endl;
	cout << "search 0(false): " << rbt.search(0) << endl;
	cout << "search 11(false): " << rbt.search(11) << endl;
	
	//test search 2
	vector<int> s1 = rbt.search(3, 6);
	cout << "search 3,6: ";
	for (std::vector<int>::const_iterator is1 = s1.begin(); is1 != s1.end(); ++is1)
		std::cout << *is1 << ' ';

	vector<int> s2 = rbt.search(7, 15);
	cout << endl << "search 7,15: ";
	for (std::vector<int>::const_iterator is2 = s2.begin(); is2 != s2.end(); ++is2)
		std::cout << *is2 << ' ';

	vector<int> s3 = rbt.search(12, 13);
	cout << endl << "search 12,13: ";
	for (std::vector<int>::const_iterator is3 = s3.begin(); is3 != s3.end(); ++is3)
		std::cout << *is3 << ' ';

	vector<int> s4 = rbt.search(7, 4);
	cout << endl << "search 7,4: ";
	for (std::vector<int>::const_iterator is4 = s4.begin(); is4 != s4.end(); ++is4)
		std::cout << *is4 << ' ';

	//test left rotation
	/*
	cout << endl << endl << "test rotation: ";
	rbt.rotateLeft(rbt.getRoot()->right);
	cout << endl << "left rotate 8:" << endl;
	cout << "Inorder: " << endl;
	rbt.inorderHelper(rbt.getRoot());
	cout << endl << "Preorder: " << endl;
	rbt.preorderHelper(rbt.getRoot());
	*/


	//test right rotation
	/*
	rbt.rotateRight(rbt.getRoot()->right);
	cout << endl << "right rotate 10:" << endl;
	cout << "Inorder: " << endl;
	rbt.inorderHelper(rbt.getRoot());
	cout << endl << "Preorder: " << endl;
	rbt.preorderHelper(rbt.getRoot());
	*/


	cout << endl << endl << "inorder helper: ";
	//rbt.inorderHelper(rbt.getRoot());

	cout << endl << "preorder helper: ";
	//rbt.preorderHelper(rbt.getRoot());

	//cout << endl << "test find helper, find 7: ";
	//NodeT<int>* f1 = rbt.findHelper(rbt.getRoot(), 7);
	//cout << f1->data << "(data) " << f1->parent->data << "(parent) " << f1->left << "(left) " << f1->right << "(right) " << f1->isBlack << "(isBlack) " << endl;



	cout << endl << "test remove: " << endl;
	rbt.remove(7);
	cout << "remove 7: " << endl;
	//rbt.preorderHelper(rbt.getRoot());

	RedBlackTree<int> rbt4;
	rbt4.insert(41);
	rbt4.insert(32);
	rbt4.insert(71);
	rbt4.insert(93);
	cout << endl << "insert 41, 32, 71, 93: ";
	//rbt4.preorderHelper(rbt4.getRoot());

	rbt4.insert(65);
	cout << endl << "insert 65: ";
	//rbt4.preorderHelper(rbt4.getRoot());
	rbt4.insert(82);
	cout << endl << "insert 82: ";
	//rbt4.preorderHelper(rbt4.getRoot());
	rbt4.insert(87);
	cout << endl << "insert 87: ";
	//rbt4.preorderHelper(rbt4.getRoot());

	rbt4.remove(87);
	cout << endl << "remove 87: ";
	//rbt4.preorderHelper(rbt4.getRoot());
	rbt4.remove(71);
	cout << endl << "remove 71: ";
	//rbt4.preorderHelper(rbt4.getRoot());
	rbt4.remove(32);
	cout << endl << "remove : ";
	//rbt4.preorderHelper(rbt4.getRoot());

	cout << endl << endl << endl << endl << endl << endl;












	cout << "TEST DOUBLE" << endl;
	RedBlackTree<double> rbts;

	//test insert
	rbts.insert(5.1);
	cout << "insert test: " << rbts.getRoot()->data << endl;
	cout << "insert 5, size: " << rbts.size() << endl;
	//rbts.preorderHelper(rbts.getRoot());
	cout << endl;

	rbts.insert(7.1);
	cout << "insert 7, size: " << rbts.size() << endl;
	//rbts.preorderHelper(rbts.getRoot());
	cout << endl;

	rbts.insert(6.1);
	cout << "insert 6, size: " << rbts.size() << endl;
	//rbts.preorderHelper(rbts.getRoot());
	cout << endl;

	rbts.insert(8.1);
	cout << "insert 8, size: " << rbts.size() << endl;
	//rbts.preorderHelper(rbts.getRoot());
	cout << endl;

	rbts.insert(8.1);
	cout << "insert 8, size: " << rbts.size() << endl;
	//rbts.preorderHelper(rbts.getRoot());
	cout << endl;

	rbts.insert(10.1);
	cout << "insert 10, size: " << rbts.size() << endl;
	//rbts.preorderHelper(rbts.getRoot());
	cout << endl;

	rbts.insert(9.1);
	cout << "insert 9, size: " << rbts.size() << endl;
	//rbts.preorderHelper(rbts.getRoot());
	cout << endl;

	rbts.insert(3.1);
	cout << "insert 3, size: " << rbts.size() << endl;
	//rbts.preorderHelper(rbts.getRoot());
	cout << endl;

	rbts.insert(4.1);
	cout << "insert 4, size: " << rbts.size() << endl;
	//rbts.preorderHelper(rbts.getRoot());
	cout << endl;

	//test dump
	vector<double> ds = rbts.dump();
	//vector<int> pd = rbt.preOrderDump(rbt.getRoot());
	cout << "Inorder dump: " << endl;
	for (std::vector<double>::const_iterator is = ds.begin(); is != ds.end(); ++is)
		std::cout << *is << ' ';

	//test copy constructor
	RedBlackTree<double> rbts2(rbts);
	cout << endl << "rbts2(copy): " << endl;
	cout << "Inorder: " << endl;
	//rbts2.inorderHelper(rbts2.getRoot());
	cout << endl << "Preorder: " << endl;
	//rbts2.preorderHelper(rbts2.getRoot());


	//test operator=
	RedBlackTree<double> rbts3 = rbts;
	cout << endl << "rbt3(operator=): " << endl;
	cout << "Inorder: " << endl;
	//rbts3.inorderHelper(rbts3.getRoot());
	cout << endl << "Preorder: " << endl;
	//rbts3.preorderHelper(rbts3.getRoot());


	//test search 1
	cout << endl << "search 4(true): " << rbts.search(4.1) << endl;
	cout << "search 5(true): " << rbts.search(5.1) << endl;
	cout << "search 3(true): " << rbts.search(3.1) << endl;
	cout << "search 6(true): " << rbts.search(6.1) << endl;
	cout << "search 8(true): " << rbts.search(8.1) << endl;
	cout << "search 4(true): " << rbts.search(4.1) << endl;
	cout << "search 10(true): " << rbts.search(10.1) << endl;
	cout << "search 9(true): " << rbts.search(9.1) << endl;
	cout << "search 7(true): " << rbts.search(7.1) << endl;
	cout << "search 2(false): " << rbts.search(2.1) << endl;
	cout << "search 1(false): " << rbts.search(1.1) << endl;
	cout << "search 0(false): " << rbts.search(0.1) << endl;
	cout << "search 11(false): " << rbts.search(11.1) << endl;

	//test search 2
	vector<double> ss1 = rbts.search(3.1, 6.1);
	cout << "search 3,6: ";
	for (std::vector<double>::const_iterator iss1 = ss1.begin(); iss1 != ss1.end(); ++iss1)
		std::cout << *iss1 << ' ';

	vector<double> ss2 = rbts.search(7.1, 15.1);
	cout << endl << "search 7,15: ";
	for (std::vector<double>::const_iterator iss2 = ss2.begin(); iss2 != ss2.end(); ++iss2)
		std::cout << *iss2 << ' ';

	vector<double> ss3 = rbts.search(12.1, 13.1);
	cout << endl << "search 12,13: ";
	for (std::vector<double>::const_iterator iss3 = ss3.begin(); iss3 != ss3.end(); ++iss3)
		std::cout << *iss3 << ' ';

	vector<double> ss4 = rbts.search(7.1, 4.1);
	cout << endl << "search 7,4: ";
	for (std::vector<double>::const_iterator iss4 = ss4.begin(); iss4 != ss4.end(); ++iss4)
		std::cout << *iss4 << ' ';

	//test left rotation
	/*
	cout << endl << endl << "test rotation: ";
	rbts.rotateLeft(rbts.getRoot()->right);
	cout << endl << "left rotate 8:" << endl;
	cout << "Inorder: " << endl;
	rbts.inorderHelper(rbts.getRoot());
	cout << endl << "Preorder: " << endl;
	rbts.preorderHelper(rbts.getRoot());
	*/


	//test right rotation
	/*
	rbt.rotateRight(rbt.getRoot()->right);
	cout << endl << "right rotate 10:" << endl;
	cout << "Inorder: " << endl;
	rbt.inorderHelper(rbt.getRoot());
	cout << endl << "Preorder: " << endl;
	rbt.preorderHelper(rbt.getRoot());
	*/


	cout << endl << endl << "inorder helper: ";
	//rbts.inorderHelper(rbts.getRoot());

	cout << endl << "preorder helper: ";
	//rbts.preorderHelper(rbts.getRoot());

	//cout << endl << "test find helper, find 7: ";
	//NodeT<double>* fs1 = rbts.findHelper(rbts.getRoot(), 7.1);
	//cout << fs1->data << "(data) " << fs1->parent->data << "(parent) " << fs1->left << "(left) " << fs1->right << "(right) " << fs1->isBlack << "(isBlack) " << endl;



	cout << endl << "test remove: " << endl;
	rbts.remove(7.1);
	cout << "remove 7: " << endl;
	//rbts.preorderHelper(rbts.getRoot());

	RedBlackTree<double> rbts4;
	rbts4.insert(41.1);
	rbts4.insert(32.1);
	rbts4.insert(71.1);
	rbts4.insert(93.1);
	cout << endl << "insert 41, 32, 71, 93: ";
	//rbts4.preorderHelper(rbts4.getRoot());

	rbts4.insert(65.1);
	cout << endl << "insert 65: ";
	//rbts4.preorderHelper(rbts4.getRoot());
	rbts4.insert(82.1);
	cout << endl << "insert 82: ";
	//rbts4.preorderHelper(rbts4.getRoot());
	rbts4.insert(87.1);
	cout << endl << "insert 87: ";
	//rbts4.preorderHelper(rbts4.getRoot());

	rbts4.remove(87.1);
	cout << endl << "remove 87: ";
	//rbts4.preorderHelper(rbts4.getRoot());
	rbts4.remove(71.1);
	cout << endl << "remove 71: ";
	//rbts4.preorderHelper(rbts4.getRoot());
	rbts4.remove(32.1);
	cout << endl << "remove : ";
	//rbts4.preorderHelper(rbts4.getRoot());

	cout << endl << endl << endl << endl << endl << "Test operator again: " << endl;
	
	RedBlackTree<int> rbt5;
	rbt5.insert(23);
	rbt5.insert(25);
	rbt5.insert(27);
	rbt5.insert(24);
	rbt5.insert(29);
	rbt5.insert(30);
	rbt5.insert(21);

	rbt5 = rbt;
	//rbt5.preorderHelper(rbt5.getRoot());

	return 0;
}