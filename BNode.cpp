#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#ifndef BINARY_NODE_TREE
#define BINARY_NODE_TREE
template<class Key,class T>
class BNode
{
	public:
		//Method
		//Constructor
		BNode();
		BNode(Key key,T data,BNode<Key,T>* Left=nullptr,BNode<Key,T>* Right=nullptr,BNode<Key,T>* Parent=nullptr);


		//Node Interfaces & Access
		BNode *getParent();
		BNode *getLeft();
		BNode *getRight();
		void setLeft(BNode<Key,T>*);
		void setRight(BNode<Key,T>*);
		void setParent(BNode<Key,T>*);
		int hasLeft(); 
		int hasRight();
		T& getData();//read only
		void setData(T);
		Key& getKey();//read only
		void setKey(Key);
		int& getHeight();
		void setHeight(int height);


		// Node root
		BNode<Key,T>* getLeftRoot();//read only
		void setLeftRoot(BNode<Key,T>*);
		BNode<Key,T>* getRightRoot();//read only
		void setRightRoot(BNode<Key,T>*);

		
	private:
		T data;
		Key key;
		BNode<Key,T>* Parent;
		BNode<Key,T>* Left;
		BNode<Key,T>* Right;

		BNode<Key,T>* LeftRoot;
		BNode<Key,T>* RightRoot;

		int height;

};

// Implementation
//Method
//Constructor
template<class Key, class T> 
BNode<Key,T>::BNode()
{
	Parent=Left=Right=LeftRoot=RightRoot=nullptr;
	height = 1;
}
template<class Key, class T> 
BNode<Key,T>::BNode(Key key,T data,BNode<Key,T>* Left,BNode<Key,T>* Right,BNode<Key,T>* Parent)
{
	this->key=key;
	this->data=data;
	this->Parent=Parent;
	this->Left=Left;
	this->Right=Right;
	this->LeftRoot=nullptr;
	this->RightRoot=nullptr;
	this->height=1;
}

//Node Interfaces & Access
template<class Key, class T> 
BNode<Key,T>* BNode<Key,T>::getParent()
{
	return this->Parent;
}
template<class Key, class T> 
BNode<Key,T>* BNode<Key,T>::getLeft()
{
	return this->Left;
}
template<class Key, class T> 
BNode<Key,T>* BNode<Key,T>::getRight()
{
	return this->Right;
}
template<class Key, class T>
void BNode<Key,T>::setLeft(BNode<Key,T> *Left)
{
	this->Left=Left;
}
template<class Key, class T>
void BNode<Key,T>::setRight(BNode<Key,T> *Right)
{
	this->Right=Right;
}
template<class Key, class T>
void BNode<Key,T>::setParent(BNode<Key,T> *Parent)
{
	this->Parent=Parent;
}
template<class Key, class T>
int BNode<Key,T>::hasLeft()
{
	return this->Left!=nullptr;
}
template<class Key, class T>
int BNode<Key,T>:: hasRight()
{
	return this->Right!=nullptr;
}

template<class Key, class T>
T& BNode<Key,T>::getData() 
{
	return this->data;
}
template<class Key, class T>
void BNode<Key,T>::setData(T data)
{
	this->data=data;
}
template<class Key, class T>
Key& BNode<Key,T>::getKey() 
{
	return this->key;
}
template<class Key, class T>
void BNode<Key,T>::setKey(Key key)
{
	this->key=key;
}
template<class Key, class T>
int& BNode<Key,T>::getHeight() 
{
	return this->height;
}
template<class Key, class T>
void BNode<Key,T>::setHeight(int height)
{
	this->height=height;
}


//Node root
template<class Key, class T>
BNode<Key,T>* BNode<Key,T>::getLeftRoot() 
{
	return this->LeftRoot;
}
template<class Key, class T>
void BNode<Key,T>::setLeftRoot(BNode<Key,T>* LeftRoot)
{
	this->LeftRoot=LeftRoot;
}

template<class Key, class T>
BNode<Key,T>* BNode<Key,T>::getRightRoot() 
{
	return this->RightRoot;
}
template<class Key, class T>
void BNode<Key,T>::setRightRoot(BNode<Key,T>* RightRoot)
{
	this->RightRoot=RightRoot;
}
#endif

// int main()
// {
// 	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// 	BNode<int,int> *BTNode=new BNode<int,int>();
// 	BNode<int,int> *R=new BNode<int,int>(2,200);
// 	BNode<int,int> *L=new BNode<int,int>(3,300);
// 	BTNode->setData(100);
// 	BTNode->setKey(1);
// 	BTNode->setLeft(L);
// 	BTNode->setRight(R);
// 	cout<<BTNode->getKey()<<" "<<BTNode->getData()<<"\n";
// 	cout<<BTNode->getRight()->getKey()<<" "<<BTNode->getRight()->getData()<<"\n";
// 	cout<<BTNode->getLeft()->getKey()<<" "<<BTNode->getLeft()->getData()<<"\n";
// 	BTNode->getRight()->setKey(4);
// 	BTNode->getLeft()->setKey(5);
// 	cout<<BTNode->getRight()->getKey()<<" "<<BTNode->getRight()->getData()<<"\n";
// 	cout<<BTNode->getLeft()->getKey()<<" "<<BTNode->getLeft()->getData()<<"\n";


// 	return 0;
// }