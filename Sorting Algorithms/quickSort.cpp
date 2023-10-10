#include<iostream>
using namespace std;
int main()
{
	int sparse[10][10],i,j,row,col,temp,triplet[20][3];
	temp=1;
	cout<<"enter the number of rows and cols"<<endl;
	cin>>row>>col;
	cout<<"enter the elements of sparse matrix"<<endl;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			cin>>sparse[i][j];
		}
	}
	int nzero=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(sparse[i][j]!=0)
			{
				nzero++;
				
			}		
		}
	}
	triplet[0][0]=row;
	triplet[0][1]=col;
	triplet[0][2]=nzero;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(sparse[i][j]!=0)
			{
				triplet[temp][0]=i;
				triplet[temp][1]=j;	
				triplet[temp][2]=sparse[i][j];	
				temp++;
				
			}		
		}
	}
for(i=0;i<nzero+1;i++)
	{
		for(j=0;j<3;j++)
		{
			
				cout<<triplet[i][j]<<"\t";		
		}
		cout<<endl;
	}
	return 0;
}