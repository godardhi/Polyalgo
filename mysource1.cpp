#include <iostream>

int main()
{

	int n;
	std::cin>>n;
	int array[n];
	for(int i=1; i<=n; i++)
	{
		std::cin>>array[i];
	}
	for(int i=1; i<=n; i++)
	{
		if(array[(n+1)-i]==array[i])
		{
			std::cout<<"valid"<<"\n";
		}
		else
		{
			std::cout<<"invalid"<<"\n";
		}
		

	}
	
	
	return 0;
}
