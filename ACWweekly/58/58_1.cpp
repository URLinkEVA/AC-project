#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int n;
int a[100];


int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 1)
		{
			cout << "YES" << endl;
			break;
		}
		if(i == n)
		{ 
			cout << "NO";
			break;
		}
	}

	return 0;
}
