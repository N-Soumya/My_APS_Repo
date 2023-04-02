#include <bits/stdc++.h>
using namespace std;


void removespace(string s)
{
	
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{
			
			s.erase(s.begin() + i);
			i--;
		}
	}
	cout << s;
}

int main()
{
	string s = "Gee k ";
	cout << "original string is: " <<s<<endl;
	cout << "final updated string: ";
	//function calling
	removespace(s);
	cout<<endl;
	string s1="G e e k";
	cout << "original string is: " <<s1<<endl;
	cout << "final updated string: ";
	//function calling
	removespace(s1);
	return 0;
}

