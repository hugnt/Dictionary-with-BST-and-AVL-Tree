#include <bits/stdc++.h>
#include<conio.h>
#include "BST_Dictionary.cpp"
using namespace std;

/*
									CHÚ Ý 
	- Khi import du lieu tu file:
	+ Cac tu và nghia của chung phai được ghi tren cung 1 dong
	+ Tu va nghia ngan cach nhau boi dau hai cham ":"
	*Co the xem file mau import: data_input.txt

*/


Dictionary dict;
void Menu();
void Continue(void (OP)())
{
	char op;
	cout<<"\nTiep tuc chuc nang?(y/n):";
	op=getch();cout<<op;
	// cin>>op;
	if(op==121||op==89)
	{
		OP();
	}
	else
	{
		Menu();
	}

}
void OP1()
{
	string inp;
	string resSearch;
	cout<<"\n- Nhap vao tu can tra cuu:";
	getline(cin,inp);
	resSearch=dict.Search(inp);
	if(resSearch==" "){
		cout<<"!Error: '"<<inp<<"'"<<" is not existed in the dictionary!";
		Continue(OP1);
		return;
	}
	cout<<"\n\t-----------------------------------\n";
	cout<<"\t"<<inp<<": "<<dict.Search(inp)<<"\n";
	cout<<"\t-----------------------------------\n";
	Continue(OP1);
}
void OP2()
{
	string inpWord,inpMean;
	string resSearch;
	cout<<"\n- Nhap vao tu:";
	getline(cin,inpWord);
	cout<<"- Nhap vao nghia:";
	getline(cin,inpMean);
	dict.Insert(inpWord,inpMean);
	// fflush(stdin);
	Continue(OP2);

}
void OP3()
{
	
	string inp;
	string inpUpdate;
	string resSearch;
	cout<<"\n- Nhap vao tu can cap nhat:";
	getline(cin,inp);
	resSearch = dict.Search(inp);
	if(resSearch ==" ")
	{
		cout<<"!Error: '"<<inp<<"'"<<" is not existed in the dictionary!";
		cout<<": Updated failed\n";
		Continue(OP3);
		return;
	}
	cout<<"\n- Cap nhat ngia moi cua '"<<inp<<"' :";
	getline(cin,inpUpdate);
	dict.Update(inp,inpUpdate);
	// fflush(stdin);
	Continue(OP3);

}
void OP4(){
	string inp;
	string resSearch;
	cout<<"\n- Nhap vao tu can xoa:";
	getline(cin,inp);
	resSearch = dict.Search(inp);
	if(resSearch ==" ")
	{
		cout<<"!Error: '"<<inp<<"'"<<" is not existed in the dictionary!";
		cout<<": Delete failed\n";
		Continue(OP4);
		return;
	}
	dict.Remove(inp);
	// fflush(stdin);
	Continue(OP4);
}
void OP5(){
	string inp;
	cout<<"\n*Chu y:file import phai co dung dinh dang cho du lieu dau vao\n";
	cout<<"\n- Nhap vao ten file import:";
	getline(cin,inp);
	dict.ImportFromFile(inp);
	Continue(OP5);
}
void OP6(){
	string inp,filter;
	int op;
	cout<<"\n**Lua chon xuat:\n";
	cout<<"0. Tat ca"<<"\n";
	cout<<"1. Cac tu bat dau bang chu cai(vd: a):"<<"\n";
	cout<<"- Nhap lua chon xuat:";cin>>op;fflush(stdin);
	if(op==0)
	{
		filter="all";
	}
	else
	{
		cout<<"- Nhap vao chu cai dai dien:";
		getline(cin,filter);
	}	

	cout<<"- Nhap vao ten file xuat:";
	getline(cin,inp);
	dict.ExportToFile(inp,filter);
	Continue(OP6);
}

void Menu()
{

	system("cls");
	cout<<"\n--------LUA CHON CHUC NANG TU DIEN ANH VIET----------\n";
	string op1="1. Tra cuu tu dien\n";
	string op2="2. Them vao tu moi\n";
	string op3="3. Cap nhat nghia cua tu\n";
	string op4="4. Xoa bo tu khoi tu dien\n";
	string op5="5. Import data from file\n";
	string op6="6. Export data to file\n";
	string opx="Esc. Thoat khoi chuong trinh\n";
	string wa="Khong xac dinh lua chon, vui long nhap lai\n";
	cout<<op1<<op2<<op3<<op4<<op5<<op6<<opx;
	cout<<"\n-----------------------o0o--------------------------\n";
	cout<<"*Nhap vao lua chon:";
	char op;
	op=getch();
	//fflush(stdin);
	//int op;cin>>op;
	//fflush(stdin);
	cout<<op<<"\n";
	switch(op)
	{
		case 49:
		{
			cout<<"**"<<op1.substr(3);
			OP1();
			break;
		}
		case 50:
		{
			cout<<"**"<<op2.substr(3);
			OP2();
			break;
		}
		case 51:
		{
			cout<<"**"<<op3.substr(3);
			OP3();
			break;
		}
		case 52:
		{
			cout<<"**"<<op4.substr(3);
			OP4();
			break;
		}
		case 53:
		{
			cout<<"**"<<op5.substr(3);
			OP5();
			break;
		}
		case 54:
		{
			cout<<"**"<<op6.substr(3);
			OP6();
			break;
		}
		case 27:
		{	
			cout<<"\ne--------Thanks for using! Have a good day!---------\n";
			break;
		}
		default:
		{
			cout<<wa;
			Menu();
			break;
		}

	}

}
int main()
{
	// dict.Insert("hello","xin chao");
	// dict.Insert("money","tien");
	dict.ImportFromFile("data_input.txt");
	Menu();
	// dict.Insert("aello","xin chao");
	// dict.Insert("alo","xin chao");
	// dict.Remove("alo");
	// dict.getBSTree().printBT(dict.node_a);
	// dict.Remove("enter");
	// dict.Update("double","hai");
	// cout<<dict.Search("esport");
	// dict.ExportToFile("data_output.txt","all");      

	return 0;
}