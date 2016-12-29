#include <iostream> 
using namespace std; 
struct node
{ 
	int data;
	node* l; 
	node* r; 
};
int find(int a[],int left,int right,int x) 
{ 
	int i; 
	for(i=left;i<=right;i++) 
		if(a[i]==x) 
			break; 
	return i; 
} int n=0; 

node* createtree(int a[],int b[],int left,int right) 
{ 
	if(left<=right&&n>0) 
	{ 
		node* p=new node; 
		p->data=b[n-1]; 
		p->l=NULL; 
		p->r=NULL; 
		int j=find(a,left,right,b[n-1]); 
		if(j>right) 
			return NULL; 
		n--; 
		p->l=createtree(a,b,left,j-1); 
		p->r=createtree(a,b,j+1,right); 
		if(p->l==NULL) 
			p->l=createtree(a,b,left,j-1); 
		if(p->r==NULL) 
			p->r=createtree(a,b,left,j-1); 
		return p; 
	} 
	return NULL; 
} 

void travel(node* p) 
{ 
	static int a=0; 
	if(p!=NULL) 
	{ 
		if(a==0) 
		{ 
			cout<<p->data; 
			a=1; 
		} 
		else 
			cout<<' '<<p->data; 
		travel(p->l); 
		travel(p->r); 
	} 
} 

int main() 
{ 
	int a[65535]; 
	int b[65535]; 
	int i=0; 
	while(cin>>a[i++]) 
		if(cin.get()!=' ') 
			break; 
	int j=0; 
	while(cin>>b[n++]) 
		if(cin.get()!=' ') 
			break; 
	node* root=createtree(a,b,0,i-1); 
	travel(root); 
	cout<<endl; 
	return 0; 
}