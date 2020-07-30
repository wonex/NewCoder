#include <iostream>
#include <string>
#include <vector>
#include "Solution.h"

using namespace std;


int main()
{
	
	Solution solu;

	////No.1
	////输入
	//int a, row, col, target;
	//cin >> target;
	//cin >> row >> col;
	//vector<vector<int>> vec(row);
	//for (int i = 0; i != row; ++i)
	//{
	//	for (int j = 0; j != col; ++j)
	//	{
	//		cin >> a;
	//		vec[i].push_back(a);
	//	}
	//}
	//vector<vector<int>>::iterator i;
	//for (i = vec.begin(); i != vec.end(); ++i)
	//{
	//	for (int j = 0; j != col; ++j)
	//		cout << (*i)[j] << ' ';
	//	cout << endl;
	//}
	////输入
	//
	//cout << solu.Find(target, vec) << endl;
	
	////No.2
	////输入
	//int length;
	//cin >> length;
	//getchar();
	//char* str, * strc;
	//str = new char[sizeof(char) * length]();
	//strc = str;
	//char c;
	//while ((c = getchar()) != '\n') { *(strc++) = c; };
	//*strc='\0';
	////输入

	//solu.replaceSpace(str, length);
	//str = 0;
	//strc = 0;
	//delete [] str;

	//No.3
	Stack a;
	int val;
	while (cin >> val)
	{
		if (val == -1)
			break;
		if (val == 0)
			cout << a.pop() << endl;
		else
			a.push(val);
	}
	system("pause");
	return 0;
}