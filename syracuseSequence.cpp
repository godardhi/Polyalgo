#include <iostream>

using namespace std;

int syracuseN(int n)
{
	if(n==1)
	{
		cout<<"\n";
		return 1;
	}else
	{
		if(n%2==0)
		{
			n=n/2;
			cout<<n<<",";
			return syracuseN(n);
		}else
		{
			n=3*n;
			n+=1;
			if(n==1)
			cout<<n<<",";
			return syracuseN(n);
		}
	}	
}

int main()
{		
		/*
		int n =14;
		cout<<"S("<<n<<"): ";
		syracuseN(n);
		*/
		int a = 10;
		int b = 10000;
		
		for(int i=a; i<=b; i++)
		{
			cout<<"S("<<i<<"): ";
			syracuseN(i);	
		}
		
	return 0;
}
