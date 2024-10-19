#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int n[] = {0, 0, 0};

int equal(int a, int b, int c)
{
	if (a == b)
	{
		if (a == c || b == c)
		{
			return 3;
		}
		else
		{
			return 2;
		}
	}
	else if (b == c)
	{
		if (a == b || a == c)
		{
			return 3;
		}
		else
		{
			return 2;
		}
	}
	else if (a == c)
	{
		if (b == a || b == c)
		{
			return 3;
		}
		else
		{
			return 2;
		}
	}
	
	return 0;
}

int main()
{
	std::ostringstream ess;
	
	for (int i = 0; i < 3; i++)
	{
		std::ostringstream oss;
		string text = "Unesi broj ";
		oss << (i + 1);
		cout << text + oss.str() + ":" << endl;
		cin >> n[i];
	}
	
	cout << "";
	ess << equal(n[0], n[1], n[2]);
	cout << "The same number repeats itself the following amount of times: " + ess.str() << endl;
}
