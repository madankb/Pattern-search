#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#define d 256
using namespace std;
void Rabin_Karp(char *txt,char *pat,int q)
{
	int t=strlen(txt);
	int p=strlen(pat);
	
	int h=1;
	
	// Equal to(d*d*d*d)%q where evaluation inside () may overflows above integer (INT_MAX) so it can also equal to (d%q*d%q*d%q*d%q)%q
	for (int i=0;i<p-1;i++) 
	{
		int temp=d%q;
		h=(temp*h)%q;
		cout<<"H inside is :"<<h<<endl;
	}

	int n=0;
	int m=0;
	int j=0;
	
	// Equal to (d*d*pat[0]+d*pat[1]+pat[2])%q where evaluation inside () may overflows above integer (INT_MAX) so it can also equal to (d*d*pat[0]%q+d*pat[1]%q+pat[2]%q)%q
	for (int i=0;i<p;i++) 
	{
		n=(d*n + pat[i])%q;
		m=(d*m + txt[i])%q;
	}

	cout<<"N and M is :"<<n<<" "<<m<<endl;
	
	for (int i=0;i<=t-p;i++)
	{
		if (n == m)
		{
			for (j = 0; j < p; j++)//To make sure the string really matches to avoid hashing collision
			{
				if (txt[i+j] != pat[j])
					break;
				
			}
			
			if (j == p)  // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
			{
				printf("Pattern found at index %d \n", i);
				
			}
			//printf("Pattern found at the index [%d] \n",i);
		}
		
		if (i < t-p )
		{
			cout<<"Text is :"<<txt[i]*h<<endl;
			
			//m=(d*(m - txt[i]*h) + txt[i+p])%q;
			
			m=(d*(m - txt[i]*h%q)%q + txt[i+p])%q;//To avoid negative numbers as txt[i]*h gets bigger and forms negative number it is moduloed by %q.
			
			//We need to avoid negative numbers because the above "m" is calculated with avoiding negative numbers.
			
			if (m < 0) //Other way of reducing the negative numbers, if you use other way of calculating "m".
			{
				//cout<<"we have negative value "<<endl;
				m=(m+q);
			}	
		}	
	}	
	
}	
int main()
{
	char *txt="AABAACAADAABAAABAA";
	char *pat="AABA";
	int q=101;
	
	int M = strlen(pat);
	int N = strlen(txt);
	
	int p = 0;  // hash value for pattern
	int t = 0; // hash value for txt
	
	int h=1;
	
	for (int i = 0; i < M-1; i++)
	{
		h = (h*d)%q;
		cout<<"H is :"<<h<<endl;
	}	
	
	short l=(d*d*d)%q;
	cout<<"Now is :"<<(l*d)%q<<endl;
	
	cout<<"Other is :"<<d%q*d%q*d%q*d%q<<endl;
	
	cout<<"INT MAX is:"<<INT_MAX<<endl;
	
	cout<<"SHORT MAX is:"<<SHRT_MAX<<endl;
	
	    
    // Calculate the hash value of pattern and first window of text
    for (int i = 0; i < M; i++)
    {
	cout<<"Before is :"<<d*p<<endl;
        p = (d*p + pat[i])%q;
        t = (d*t + txt[i])%q;
	    
	cout<<"P and T is :"<<p<<"  "<<t<<endl;    
    }
    
    cout<<"Other way "<<(d*d*pat[0]+d*pat[1]+pat[2])%q<<endl;
    
    cout<<"One other way "<<(d*d*pat[0]%q+d*pat[1]%q+pat[2]%q)%q<<endl;

    int t1=0;
    for (int i = 1; i <= M; i++)
    {
	t1 = (d*t1 + txt[i])%q;
    }
    
    cout<<"T1 is :"<<t1<<endl;  
    
    int s = (d*(t - txt[0]*h) + txt[M])%q;
    
    cout<<"S is :"<<s+q<<endl;
    
    Rabin_Karp(txt,pat,q);
}
