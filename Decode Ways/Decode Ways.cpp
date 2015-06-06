// Decode Ways.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int numDecodings(string s)
	{
		if (s.size() == 0) return 0;
		vector<int> vec;
		reverse(s.begin(), s.end());
		for (int i = 0; i < s.size(); i++)
		{
			if (i == 0)
			{
				if (s[i] == '0') vec.push_back(0);
				else vec.push_back(1);
			}
			else if (i == 1)
			{
				if (s[i] > '2' || (s[i] == '2' && s[i - 1] > '6'))
				{
					vec.push_back(vec[i - 1]);
				}
				else if (s[i] == '0')
				{
					vec.push_back(0);
				}
				else if (s[i - 1] == '0')
				{
					vec.push_back(1);
				}
				else
				{
					vec.push_back(2);
				}
			}
			else
			{
				if (s[i] > '2' || (s[i] == '2' && s[i - 1] > '6'))
				{
					vec.push_back(vec[i - 1]);
				}
				else if (s[i] == '0')
				{
					vec.push_back(0);
				}
				else if (s[i - 1] == '0')
				{
					vec.push_back(vec[i - 2]);
				}
				else
				{
					vec.push_back(vec[i - 1] + vec[i - 2]);
				}
			}
		}
		return vec[s.size() - 1];
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	string str = "01";
	Solution S;
	cout << S.numDecodings(str) << endl;
	return 0;
}

