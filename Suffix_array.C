#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
struct suffix
{
	int index;
	char *a;
};
int comp(struct suffix x,struct suffix y)
{
	return strcmp(x.a,y.a)<0?1:0;
}		
int* build_suffix(char *txt,int n)
{
	string *s=new string[n];
	
	for (int i=0;i<n;i++)
	{
		s[i]=txt+i;
	}
	
	sort(s,s+n);
	
	
	struct suffix sfx[n];
	for (int i=0;i<n;i++)
	{
		sfx[i].index=i;
		sfx[i].a=txt+i;
	}
	
	sort(sfx,sfx+n,comp);
	
	int *R=new int[n];
	
	for (int i=0;i<n;i++)
	{
		
		cout<<"Index and suffix string :"<<sfx[i].index<<"   "<<sfx[i].a<<endl;
		R[i]=sfx[i].index;
	}
		
	return R;		
}
int binary_search(char *pat,char* txt,int* sfx_ary,int n)
{
	int m=strlen(pat);
	int lower=0;
	int upper=n-1;
	int mid=0;
	
	while (lower <= upper)
	{
		cout<<"Lower and upper is :"<<lower<<"  "<<upper<<endl;
		mid=(lower+upper)/2;//Find middle index to start
		
		int res=strncmp(pat,txt+sfx_ary[mid],m);
		
		if (res == 0)
		return sfx_ary[mid];
		
		if (res < 0)
		upper=mid-1;//Range to search from lower to above middle(upper)
		else
		lower=mid+1;//Range to search from below middle(lower) to upper 
	}
	return -1;	
}		
int main()
{
	char txt[]="banana";
	int n=strlen(txt);
	int *R=build_suffix(txt,n);//Suffix array is sorted array of suffix of the string with index.
	
	cout<<"Char is : "<<txt+3<<endl;
	
	int a[3]={1,2,3};
	
	cout<<"Int is :"<<a+2<<endl;
	
	for (int i=0;i<n;i++)
	{
		printf("%d ",R[i]);
	}
	cout<<endl;
	
	cout<<"String comp :"<<strncmp("banana","ban",3)<<endl;
	
	char pat[]="bana";
	printf("Patter found at the index [%d] \n",binary_search(pat,txt,R,n));	
	
	cout<<(3+4)/2<<endl;
	
}	
