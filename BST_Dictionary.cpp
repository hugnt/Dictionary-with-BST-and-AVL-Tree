#include <bits/stdc++.h>
#include "BNode.cpp" 
#include "BSTree.cpp"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#ifndef BST_DICTIONARY
#define BST_DICTIONARY
//suported tool

class Dictionary
{
	public:

		//Constructor
		Dictionary();
		

		//Modifier
		void Insert(string,string);
		void Remove(string);
		void Update(string,string);
		void ImportFromFile(string);
		void ExportToFile(string,string filter="all");

		//Access Elements & Interfaces
		void printBTRoot(const std::string& prefix, BNode<string,string>* node, bool isLeft);
		void printBTRoot(BNode<string,string>* node);
		BSTree<string,string> getBSTree();

		//Travelsal
		void inOrderRoot(BNode<string,string>*,ofstream&);
		void inOrderBranch(BNode<string,string>*,ofstream&);

		//node roots 
		BNode<string ,string>* root;
		BNode<string ,string>* node_h;
		BNode<string ,string>* node_d;
		BNode<string ,string>* node_b;
		BNode<string ,string>* node_a;
		BNode<string ,string>* node_c;
		BNode<string ,string>* node_f;
		BNode<string ,string>* node_e;
		BNode<string ,string>* node_g;
		BNode<string ,string>* node_l;
		BNode<string ,string>* node_j;
		BNode<string ,string>* node_i;
		BNode<string ,string>* node_k;
		BNode<string ,string>* node_n;
		BNode<string ,string>* node_m;
		BNode<string ,string>* node_o;
		BNode<string ,string>* node_x;
		BNode<string ,string>* node_t;
		BNode<string ,string>* node_r;
		BNode<string ,string>* node_q;
		BNode<string ,string>* node_s;
		BNode<string ,string>* node_v;
		BNode<string ,string>* node_u;
		BNode<string ,string>* node_w;
		BNode<string ,string>* node_z;
		BNode<string ,string>* node_y;


		//Search
		string Search(string);
		BNode<string,string>* SearchRoot(string,BNode<string,string>*root);

		//Other filter tool
		BNode<string,string>* filterRoot(string);
		string subData(string);
		bool checkData(string,string);

		
		

	
	private:
		BSTree<string,string> bstree;


};


//Constructor
Dictionary::Dictionary()
{
	this->root=new BNode<string ,string>("p","root");
	this->node_h=new BNode<string ,string>("h","root");
	this->node_d=new BNode<string ,string>("d","root");
	this->node_b=new BNode<string ,string>("b","root");
	this->node_a=new BNode<string ,string>("a","root");
	this->node_c=new BNode<string ,string>("c","root");
	this->node_f=new BNode<string ,string>("f","root");
	this->node_e=new BNode<string ,string>("e","root");
	this->node_g=new BNode<string ,string>("g","root");
	this->node_l=new BNode<string ,string>("l","root");
	this->node_j=new BNode<string ,string>("j","root");
	this->node_i=new BNode<string ,string>("i","root");
	this->node_k=new BNode<string ,string>("k","root");
	this->node_n=new BNode<string ,string>("n","root");
	this->node_m=new BNode<string ,string>("m","root");
	this->node_o=new BNode<string ,string>("o","root");
	this->node_x=new BNode<string ,string>("x","root");
	this->node_t=new BNode<string ,string>("t","root");
	this->node_r=new BNode<string ,string>("r","root");
	this->node_q=new BNode<string ,string>("q","root");
	this->node_s=new BNode<string ,string>("s","root");
	this->node_v=new BNode<string ,string>("v","root");
	this->node_u=new BNode<string ,string>("u","root");
	this->node_w=new BNode<string ,string>("w","root");
	this->node_z=new BNode<string ,string>("z","root");
	this->node_y=new BNode<string ,string>("y","root");
	
	BSTree<string ,string> bstree(root);
	this->bstree=bstree;

	this->bstree.InsertRoot(node_h,root);
	this->bstree.InsertRoot(node_d,root);
	this->bstree.InsertRoot(node_b,root);
	this->bstree.InsertRoot(node_a,root);
	this->bstree.InsertRoot(node_c,root);
	this->bstree.InsertRoot(node_f,root);
	this->bstree.InsertRoot(node_e,root);
	this->bstree.InsertRoot(node_g,root);
	this->bstree.InsertRoot(node_l,root);
	this->bstree.InsertRoot(node_j,root);
	this->bstree.InsertRoot(node_i,root);
	this->bstree.InsertRoot(node_k,root);
	this->bstree.InsertRoot(node_n,root);
	this->bstree.InsertRoot(node_m,root);
	this->bstree.InsertRoot(node_o,root);
	this->bstree.InsertRoot(node_x,root);
	this->bstree.InsertRoot(node_t,root);
	this->bstree.InsertRoot(node_r,root);
	this->bstree.InsertRoot(node_q,root);
	this->bstree.InsertRoot(node_s,root);
	this->bstree.InsertRoot(node_v,root);
	this->bstree.InsertRoot(node_u,root);
	this->bstree.InsertRoot(node_w,root);
	this->bstree.InsertRoot(node_z,root);
	this->bstree.InsertRoot(node_y,root);
}


//Modifier
void Dictionary::Insert(string key,string data)
{
	key = subData(key);
	if(checkData(key, data) == false){
		return;
	}
	bstree.Insert(key,data,filterRoot(key));
	cout<<"'"<<key<<"'"<<" is added successful!\n";
}
void Dictionary::Remove(string key)
{
	key = subData(key);
	bstree.Remove(key,filterRoot(key));
	cout<<"Removed "<<"'"<<key<<"'"<<" successful!\n";
}
void Dictionary::Update(string key,string data)
{
	BNode<string,string>* selectedNode = bstree.Search(key,filterRoot(key));
	selectedNode->setData(data);
	cout<<"Updated "<<"'"<<key<<": "<<selectedNode->getData()<<"'"<<" successful!\n";
}
void Dictionary::ImportFromFile(string fileName)
{

	string line;
	int count_raw=0;
	int count_success=0;
	ifstream dataFile(fileName);
	if(dataFile.is_open())
	{   
		size_t pos =0;
		string key,data;
		while(getline(dataFile, line))
		{
			// cout<<line<<"\n";
			count_raw++;
			pos=line.find(":");
			if(line.length()>0&&pos!=string::npos)
			{
				key = subData(line.substr(0, pos));
				data = subData(line.substr(pos+1,line.length()));
				if(checkData(key, data)==false){
					continue;
				}
				Insert(key,data);
				count_success++;
			}
			else
			{
				cout<<"!Error: '"<<line<<"'"<<" is imported in wrong type!"<<"\n";
				cout<<count_success<<"/"<<count_raw<<" imported successful!"<<"\n";
				dataFile.close();
	  			return;
			}	
		}
		
	}
	else
	{
		cout << "Unable to open file\n"; 
	}
	cout<<count_success<<"/"<<count_raw<<" imported successful!"<<"\n";
	dataFile.close();
}
void Dictionary::ExportToFile(string fileName, string filter)
{
	if(filterRoot(filter)==nullptr)
	{
		cout<<"Error: Cant export file, please check your output data again!\n";
		return;
	}
	ofstream dataFile(fileName);
	if (dataFile.is_open())
	{
		if(filter=="all")
	  	{
	  		inOrderRoot(this->root,dataFile);
	  	}
	  	else if(filter!="all")
	  	{
	 		inOrderBranch(filterRoot(filter),dataFile);
	  	}
	  	else
	  	{
	  		cout<<"Error: Cant export file, please check your output data again!\n";
	  		dataFile.close();
	  		return;
	  	}
	  	cout<<"Exported successful!"<<"\n";
	}
	else cout <<"Unable to open file";
	dataFile.close();
}

//Travelsal
void Dictionary::inOrderRoot(BNode<string, string>* Root,ofstream& dataFile)
{
	if(Root==NULL) return;
	inOrderRoot(Root->getLeftRoot(),dataFile);
	inOrderBranch(Root,dataFile);
	inOrderRoot(Root->getRightRoot(),dataFile);
}
void Dictionary::inOrderBranch(BNode<string,string>* node,ofstream& dataFile)
{
	if(node==NULL) return;
	inOrderBranch(node->getLeft(),dataFile);
	if(node->getData()!="root"&&dataFile!=nullptr)
	{
		dataFile<<node->getKey()<<": "<<node->getData()<<"\n";
	}
	inOrderBranch(node->getRight(),dataFile);
}

//Other tools
BNode<string,string>* Dictionary::filterRoot(string key)
{
	string key0 ="";
	key0 += tolower(key[0]);
	return SearchRoot(key0,bstree.getRoot());
}

string Dictionary::subData(string str)
{
    while(str[0]==' ')
    {
        str.replace(str.begin(),str.begin()+1,"");
        // cout<<str<<"\n";
    }
    while(str[str.length()-1]==' ')
    {
        str.replace(str.end()-1,str.end(),"");
    }
    str[0] = tolower(str[0]);
    return str;
}
bool Dictionary::checkData(string key, string data){
	BNode<string,string>* Root = filterRoot(key);
	if(Root == nullptr||(Search(key)==data&&Search(key)!="root")||Search(key)!=" ")
	{
		cout<<"!Error: '"<<key<<"'"<<" is not added in right type or already existed, Please check your typing!\n";
		return false;
	}
	return true;
}

//Interfaces
BSTree<string,string> Dictionary::getBSTree()
{
	return this->bstree;
}
void Dictionary::printBTRoot(const std::string& prefix, BNode<string,string>* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->getKey() << std::endl;

        // enter the next tree level - left and right branch
        printBTRoot( prefix + (isLeft ? "│   " : "    "), node->getLeftRoot(), true);
        printBTRoot( prefix + (isLeft ? "│   " : "    "), node->getRightRoot(), false);
    }
}
void Dictionary::printBTRoot(BNode<string,string>* node)
{
    printBTRoot("", node, false);    
}


string Dictionary::Search(string key)
{
	key=subData(key);
	BNode<string,string>* node =  this->bstree.Search(key,filterRoot(key));
	if(node == NULL||node->getData()=="root")
	{
		return " ";
	}
	else
	{
		return node->getData();
	}
	
}
BNode<string,string>* Dictionary::SearchRoot(string key,BNode<string,string>*Root)
{
	if(Root==nullptr||Root->getKey()==key){
		return Root;
	}
	if(key<Root->getKey())
	{
		return SearchRoot(key,Root->getLeftRoot());
	}
	return SearchRoot(key,Root->getRightRoot());

}

#endif

// int main()
// {
// 	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// 	Dictionary dict;
// 	dict.ImportFromFile("data_input.txt");
// 	dict.Remove("enter");
// 	dict.Update("double","hai");
// 	cout<<dict.Search("esport");
// 	dict.ExportToFile("data_output.txt","all");
// 	// cin>>Tu;cout<<Nghia       
// 	return 0;
// }