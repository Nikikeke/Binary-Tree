#include<iostream> 
#include<stdio.h> 
#include<string.h> 
#include<algorithm> 
#include<assert.h> 
#include<ctype.h> 

using namespace std; 
int a[100010]; 
int size; 
void siftdown( int cike )
{ 
	int i = cike;
	int j = 2*i;  
	int temp = a[cike];
	while( j <= size) 
	{ 
		if( j <= size -1 && a[j] > a[j+1])
			j++;
		if( temp > a[j])
		{ 
			a[i] = a[j]; 
			i = j; 
			j = 2*j; 
		} 
		else 
			break; 
	} 
	a[i] = temp;
} 

void siftup( int cike ) 
{ 
	int temdian = cike; 
	int temp = a[temdian]; 
	while( (temdian > 1)&&( a[temdian/2] > temp))
	{ 
		a[temdian] = a[temdian/2];
		temdian = temdian/2; 
	} 
	a[temdian] = temp;
} 

void insert( int t) 
{
	a[ ++size ] = t; 
	siftup( size ); 
} 

void del( ) 
{ 
	if(size==0)
		return ;
	cout << a[1] << endl;
	a[1] = a[size--]; 
	siftdown( 1 ); 
} 

int main() 
{ 
	int t; 
	cin >> t;
	while( t-- ) 
	{ 
		size = 0; 
		int type; 
		int m; 
		cin >> m;
		for(int i = 0; i< m; i++) 
		{ 
			cin >> type;
			if(type == 1) 
			{ 
				int b; 
				cin >> b;
				insert( b );
			} 
			else 
			{ 
				del(); 
			} 
		} 
	} 
	return 0; 
}