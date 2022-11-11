#include <bits/stdc++.h>
#include "BNode.cpp"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#define GET_VARIABLE_NAME(Variable) (#Variable)
//1 NODE NULL <=> ALL(parent,left,right)=NULL;

template<class Key,class T>
class BSTree
{
	public:
		//Method 

		//Constructor
		BSTree();
		BSTree(BNode<Key,T>* root);

		//Elements Access
		int size();
		int isEmpty();
		int isInternal(BNode<Key,T>*);
		int isExternal(BNode<Key,T>*);
		int isRoot(BNode<Key,T>*);


		/// Traversals
		void preOrder(BNode<Key,T>*);
		void inOrder(BNode<Key,T>*);
		void postOrder(BNode<Key,T>*);
		void printBT(const std::string& prefix, BNode<Key,T>* node, bool isLeft);
		void printBT(BNode<Key,T>* node);

		//Modifiers
		BNode<Key,T>* Insert(Key,T,BNode<Key,T>*);
		BNode<Key,T>* InsertRoot(BNode<Key,T>*, BNode<Key,T>*);
		BNode<Key,T>* Remove(Key,BNode<Key,T>*);


		//Interfaces
		BNode<Key,T>* getRoot();
		BNode<Key,T>* Search(Key,BNode<Key,T>*root);

		
		//ADV Tree tools
		int leftHeight(BNode<Key,T>* node);
		int rightHeight(BNode<Key,T>* node);
		int getBalance(BNode<Key,T>* node);
		BNode<Key,T>* getAVLTree(int balance, BNode<Key,T>* Root);
		BNode<Key,T>* rightRotate(BNode<Key,T>* node);
		BNode<Key,T>* leftRotate(BNode<Key,T>* node);

		

	private:
		BNode<Key,T>* root;
		int n;

};

// Implementation
//Method 

//Constructor
template<class Key,class T>
BSTree<Key,T>::BSTree(){this->root= new BNode<Key,T>();n=0;}
template<class Key,class T>
BSTree<Key,T>::BSTree(BNode<Key,T>* root)
{
	this->root= root;
	this->root->setParent(NULL);
	n=1;
}

//Elements Access
template<class Key,class T>
int BSTree<Key,T>::size()
{
	return n;
}
template<class Key,class T>
int BSTree<Key,T>::isEmpty()
{
	return n==0;
}
template<class Key,class T>
int BSTree<Key,T>::isInternal(BNode<Key,T>* node)
{
	return node->getLeft()!=NULL || node->getRight()!=NULL;
}
template<class Key,class T>
int BSTree<Key,T>::isExternal(BNode<Key,T>* node)
{
	return node->getLeft()==NULL && node->getRight()==NULL;
}
template<class Key,class T>
int BSTree<Key,T>::isRoot(BNode<Key,T>* node)
{
	return node->getParent()==NULL;
}


/// Traversals
template<class Key,class T>
void BSTree<Key,T>::preOrder(BNode<Key,T>* node)
{
	if(node==NULL) return;
	cout<<node->getData()<<" ";
	preOrder(node->getLeft());
	preOrder(node->getRight());

}
template<class Key,class T>
void BSTree<Key,T>:: inOrder(BNode<Key,T>* node)
{
	if(node==NULL) return;
	inOrder(node->getLeft());
	cout<<node->getKey()<<":"<<node->getData()<<"\n";
	inOrder(node->getRight());
}
template<class Key,class T>
void BSTree<Key,T>:: postOrder(BNode<Key,T>* node)
{
	if(node==NULL) return;
	postOrder(node->getLeft());
	postOrder(node->getRight());
	cout<<node->getData()<<" ";
}


//Modifiers
template<class Key,class T>
BNode<Key,T>* BSTree<Key,T>::Insert(Key key,T data, BNode<Key,T>* Root)
{
	if(isEmpty()){
		this->root = new BNode<Key,T>(key, data);
		// cout<<"added root!\n";
		n++;
		return this->root;
	}
	if(Root==nullptr)
	{
		Root = new BNode<Key,T>(key, data);
		// cout<<"check\n";
		n++;
		return Root;
	}
	if(key<Root->getKey())
	{
		// cout<<"left\n";
		Root->setLeft(Insert(key,data,Root->getLeft()));
	}
	else if(key > Root->getKey())
	{
		// cout<<"right\n";
		Root->setRight(Insert(key,data,Root->getRight()));
	}
	else
	{
		// cout<<"equal\n";
		return Root;
	}

	//Update height of this ancestor node
	Root->setHeight(1 + max(leftHeight(Root), rightHeight(Root)));
	
	if(Root->getData()=="root"||Root->getKey()==this->root->getKey()){
		// dont want to rotate the RootNode 
		return Root;
	}
	else{
		//check balance
		int balance = getBalance(Root);
		if(abs(balance) > 1){//if |balance| > 1: unbalance
			return getAVLTree(balance, Root);
		}	
	}
	return Root;
	
}

template<class Key,class T>
BNode<Key,T>* BSTree<Key,T>::InsertRoot(BNode<Key,T>* node, BNode<Key,T>* Root)
{

	if(Root==NULL)
	{
		return node;
	}
	if(node->getKey()<Root->getKey())
	{
		Root->setLeftRoot(InsertRoot(node,Root->getLeftRoot()));
	}
	else
	{
		Root->setRightRoot(InsertRoot(node,Root->getRightRoot()));
	}

	//Return Root after insertion
	return Root;

}

template<class Key,class T>
BNode<Key,T>* BSTree<Key,T>::Remove(Key key, BNode<Key,T>* Root)
{	
	if(Root == NULL)
	{
		return Root;
	}
	if(key<Root->getKey())
	{
		Root->setLeft(Remove(key,Root->getLeft()));
	}
	else if(key > Root->getKey())
	{
		Root->setRight(Remove(key,Root->getRight()));
	}
	else
	{
		//delete
		//key==root->getKey()
		n--;
		if(Root->getLeft()==NULL)
		{
			BNode<Key,T>* tmpNode = Root->getRight();
			tmpNode == NULL ? Root = NULL : Root = tmpNode;
			// free(tmpNode);
		}
		else if(Root->getRight()==NULL)
		{
			BNode<Key,T>* tmpNode = Root->getLeft();
			tmpNode == NULL ? Root = NULL : Root = tmpNode;
			// free(tmpNode);
		}
		else
		{
			BNode<Key,T>* succParent = Root;
	 
	        // Find inorder successor
	        BNode<Key,T>* succ = Root->getRight();
	        while (succ->getLeft() != NULL) {
	            succParent = succ;
	            succ = succ->getLeft();
	        }
	        if (succParent != Root)
	            succParent->setLeft(succ->getRight());
	        else
	            succParent->setRight(succ->getRight());
	  
	        // Copy Successor Data to Root
	        Root->setKey(succ->getKey());
	   		Root->setData(succ->getData());
	        // Delete Successor and return Root
	        delete succ;
	        
	    }
	}
	if(Root == NULL){
		return Root;
	}
	//Update height of this ancestor node
	Root->setHeight(1 + max(leftHeight(Root), rightHeight(Root)));


	if(Root->getData()=="root"){
		// dont want to rotate the RootNode 
		return Root;
	}
	else{
		//check balance
		int balance = getBalance(Root);
		if(abs(balance) > 1){//if |balance| > 1: unbalance
			return getAVLTree(balance, Root);
		}	
	}
	return Root;
	

}

//Interfaces
template<class Key,class T>
BNode<Key,T>* BSTree<Key,T>::getRoot()
{
	return this->root;
}

template<class Key,class T>
BNode<Key,T>* BSTree<Key,T>::Search(Key key,BNode<Key,T>*Root)
{
	if(Root==NULL||Root->getKey()==key)
	{
		return Root;
	}
	if(key<Root->getKey())
	{
		return Search(key,Root->getLeft());
	}
	return Search(key,Root->getRight());

}

template<class Key,class T>
void BSTree<Key,T>::printBT(const std::string& prefix, BNode<Key,T>* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->getKey() << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->getLeft(), true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->getRight(), false);
    }
}
template<class Key,class T>
void BSTree<Key,T>::printBT(BNode<Key,T>* node)
{
    printBT("", node, false);    
}

//AVL Tree
template<class Key,class T>
int BSTree<Key,T>::leftHeight(BNode<Key,T>* node){
	if(node->getLeft() == nullptr){
		return 0;
	}
	return node->getLeft()->getHeight();
}
template<class Key,class T>
int BSTree<Key,T>::rightHeight(BNode<Key,T>* node){
	if(node->getRight() == nullptr){
		return 0;
	}
	return node->getRight()->getHeight();
}
template<class Key,class T>
int BSTree<Key,T>::getBalance(BNode<Key,T>* node)
{
	if(node == nullptr){
		return 0;
	}
	return leftHeight(node)-rightHeight(node);
}


template<class Key,class T>
BNode<Key,T>* BSTree<Key,T>::getAVLTree(int balance, BNode<Key,T>* Root){
	//LL 
	if(balance > 1 && getBalance(Root->getLeft()) >= 0){
		// cout<<"LL\n";
		return rightRotate(Root);
	} 

	//RR
	if(balance < -1 && getBalance(Root->getRight()) <= 0){
		// cout<<"RR\n";
		return leftRotate(Root);
	} 

	//LR
	if(balance > 1 && getBalance(Root->getLeft())< 0){
		// cout<<"LR\n";
		Root->setLeft(leftRotate(Root->getLeft()));
		return rightRotate(Root);
	} 

	//RL
	if(balance < -1 && getBalance(Root->getRight()) > 0){
		// cout<<"RL\n";
		Root->setRight(rightRotate(Root->getRight()));
		return leftRotate(Root);
	} 
	return Root;


}
//rightRotate
template<class Key,class T>
BNode<Key,T>* BSTree<Key,T>::rightRotate(BNode<Key,T>* node){
	BNode<Key,T>* leftNode = node->getLeft();
	BNode<Key,T>* right_leftNode = leftNode->getRight();

	//movement
	leftNode->setRight(node);
	node->setLeft(right_leftNode);

	//update heights
	node->setHeight(1 + max(leftHeight(node), rightHeight(node)));
	leftNode->setHeight(1 + max(leftHeight(leftNode), rightHeight(leftNode)));

	//return node top new
	return leftNode;
}

//leftRotate
template<class Key,class T>
BNode<Key,T>* BSTree<Key,T>::leftRotate(BNode<Key,T>* node){
	BNode<Key,T>* rightNode = node->getRight();
	BNode<Key,T>* left_rightNode = rightNode->getLeft();

	//movement
	rightNode->setLeft(node);
	node->setRight(left_rightNode);

	//update heights
	node->setHeight(1 + max(leftHeight(node), rightHeight(node)));
	rightNode->setHeight(1 + max(leftHeight(rightNode), rightHeight(rightNode)));

	//return node top new
	return rightNode;
}




#endif
// pass the root node of your binary tree
// printBT(root);
// int main()
// {
// 	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// 	BSTree<string, string> bstree;
// 	bstree.Insert("amazing","tuyetsvoi",bstree.getRoot());
// 	// cout<<bstree.getRoot()->getKey()<<"\n";
// 	bstree.Insert("abutu","tuyetsvoi",bstree.getRoot());
// 	// cout<<bstree.getRoot()->getKey()<<"\n";
// 	bstree.Insert("award","giai thuong",bstree.getRoot());
// 	bstree.Insert("angry","tuc gian",bstree.getRoot());
// 	BNode<string, string>* Node = bstree.Insert("applications","nhung ung dung",bstree.getRoot());

// 	// // bstree.Remove("applications",bstree.getRoot());
// 	// bstree.Insert("applications","hêllo",bstree.getRoot());                                                                                                                                                                                 

// 	bstree.Insert("hello","xin chao",bstree.getRoot());
// 	bstree.Insert("alo","nhung ung dung",bstree.getRoot());
// 	bstree.Insert("zalo","nhung ung dung",bstree.getRoot());

// 	bstree.Remove("hello",bstree.getRoot());
// 	bstree.Insert("applications","hêllo",bstree.getRoot());

// 	// bstree.Remove("applications",bstree.getRoot());



// 	bstree.printBT(bstree.getRoot());
// 	// cout<<bstree.rightHeight(bstree.getRoot());
// 	// cout<<bstree.leftHeight(bstree.getRoot());
// 	// bstree.getRoot()->setHeight(1 + max(bstree.leftHeight(bstree.getRoot()), bstree.rightHeight(bstree.getRoot())));
// 	// cout<<bstree.getRoot()->getHeight();
// 	//cout<<typeid(node_a->getKey()).name();
// 	//cout<<GET_VARIABLE_NAME(root);


// 	return 0;
// }
