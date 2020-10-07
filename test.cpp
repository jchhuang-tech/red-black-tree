#include "RedBlackTree.h"
#include <iostream>
#include <vector>

using namespace std;

void simpleTest()
{
	//Int Tree Tests
	RedBlackTree<int> rb1;
	if (rb1.insert(42)) cout << "inserted 42" << endl;
	rb1.insert(71);
	rb1.insert(13);
	RedBlackTree<int> rb2(rb1);
	if (rb1.remove(13)) cout << "removed 13" << endl;
	if (rb1.search(42)) cout << "found 42" << endl;
	vector<int> v1 = rb1.search(50,100);//should contain 71
	vector<int> v2 = rb1.dump();//should contain {42,71}
	cout << "size = " << rb1.size() << endl;//should be 2
	NodeT<int>* pRoot = rb1.getRoot();//BAD design - for our testing only

}

int main()
{
	simpleTest();
	return 0;
}