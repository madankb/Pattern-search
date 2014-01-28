/*****************************************************************************************************************************************************************************************
Naive pattern searching :- Every string of pattern is searched with source string,if fails in some specific index then it should next index of started index. So worst case scenario for
                           naive implemntation is O(nm). Eg:- txt[] = "AAAAAAAAAAAAAAAAAB",pat[] = "AAAAB". 
			   
KMP algorithm :-Worst case of naive searching O(nm) can be reduced by O(n) in KMP algorithm.It is working based on prefix-suffix matches computed for the pattern string needs to be searched.
               
	       1) Prefix is intial substring of certain length.
               2) Suffix is final substring of certain length.
	       3) Prefix-suffix array tells number of suffix matches with the number of prefix of certain substring at the index of array.Eg:- lps[6] tells up to the index 6 in the string
	          how many prefix-suffix matches. So string of "ABCDABCEF" upto index 6 lps[6]=3 has 3 prefix substring matches with suffix substring which is "ABC".

Steps to find index :-

        1) Compute prefix-suffix array for the patter of string.
	2) If matches keep moving the index of pattern string and text string.
	3) Else find the prefix-suffix matches in the array up to index where pattern string.
	
	For example:-
	
	m: 01234567890123456789012
        S: ABC ABCDAB ABCDABCDABDE
        W: ABCDABD
        i: 0123456
	
	Fails at m=3,i=3 lps[3-1]=lps[2]=0;So start from the index m=4,i=0
	  
	             1         2
	m: 01234567890123456789012
        S: ABC ABCDAB ABCDABCDABDE
        W:     ABCDABD
        i:     0123456
	
	Fails at m=10,i=6 but lps[6-1]=lps[5]=2 which is up to index 5 it has length 2 of matching prefix-suffix "AB", so do not compare first two string of pattern because anyway it is
	going to match. So m=10,i=2.
	
	             1         2  
        m: 01234567890123456789012
        S: ABC ABCDAB ABCDABCDABDE
        W:         ABCDABD
        i:         0123456
	
Final example :-

        txt[] = "AAAAAAAAAAAAAAAAAB",pat[] = "AAAAB". Naive has n=18, m=5 O(nm).
	
	Fails at index n=4 but lps[3]=3 so comparison starts n=5,m=3. But fails A<>B, so n=6,m=3 (lps[3]=3. 3 comparisons skipped).It goes like that at O(n) to find index at end.
******************************************************************************************************************************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
bool KMP(char *txt,char *pat)
{
	int l=strlen(txt);
	int p=strlen(pat);
	
	int lps[p];//Prefix-suffix array
	
	lps[0]=0;
	
	int len=0;
	for(int i=1;i<p;i++)
	{
		if (pat[len] == pat[i])
		{
			len++;
			lps[i]=len;
		}
		else
		{
			int x=0;
			while (x < len && pat[x] == pat[i])//For Handling the special cases like AAACAAAA (or ABCDABCAB) and i = 7. TO get lps[7]=3. This fix is for that example.
				x++;
			
			lps[i]=x;
			len=x;
		}	
	}
	
	for(int i=0;i<p;i++)
	{
		printf("%d ",lps[i]);
	}
	cout<<endl;
	
	int j=0;
	int i=0;
	while ( i < l)
	{
		if (txt[i] == pat[j])
		{
			i++;
			j++;
			
			if (j == p)
			{
				printf("Pattern found at the index [%d] \n",i-j);
				j=0;
			}
		}
		else
		{
			if (j != 0)
				j=lps[j-1];
			else
				i=i+1;//No suffix or prefix matches, so move to the next character for comparison
		}
		
	}	
}	
int main()
{
	char *txt="AAAAAAAAAAAABAAAAB";
	char *pat="AAAAB";
	KMP(txt,pat);
	return 0;
}	
