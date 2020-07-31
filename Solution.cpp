#include "Solution.h"
#include <vector>
#include <iostream>
#include <stack>

TreeNode* _reConstructBinaryTree(vector<int>::iterator, vector<int>::iterator, vector<int>::iterator, vector<int>::iterator);
void _movingCount(int, int, int, int, int, int&, int**);
bool moveIn(int, int, int);

bool Solution::Find(int target, vector<vector<int>> array)
{
	//bool res = false;
	vector<vector<int>>::size_type row, col;
	row = array.size();
	col = array[0].size();
	vector<vector<int>>::size_type i = 0, j = col - 1;
	while (i < row && j >= 0)
	{
		if (array[i][j] == target)
			return true;
		else if (array[i][j] < target)
			++i;
		else
			--j;
	}
	return false;
}

void Solution::replaceSpace(char* str, int length)
{
	/*vector<char> strc;
	for (int i = 0; *(str+i) != '\0'; ++i)
	{
		if (*(str + i) != ' ')
			strc.push_back(*(str + i));
		else
		{
			strc.push_back('%');
			strc.push_back('2');
			strc.push_back('0');
		}
	}
	strc.push_back('\0');
	for (int i = 0; i < strc.size(); ++i)
		str[i] = strc[i];*/

	int oldLength = 0;
	int numWhitespace = 0;
	for (int i = 0; *(str + i) != '\0'; ++i)
	{
		if (*(str + i) == ' ')
			++numWhitespace;
		++oldLength;
	}
	int newLength = oldLength + numWhitespace * 2;
	if (length < newLength)
		return;
	for (; newLength >= 0;)
	{
		if (str[oldLength] == ' ')
		{
			str[newLength--] = '0';
			str[newLength--] = '2';
			str[newLength--] = '%';
		}
		else
			str[newLength--] = str[oldLength];
		--oldLength;
	}
	for (int i = 0; str[i] != '\0'; ++i)
		std::cout << str[i];
	std::cout << std::endl;
}

vector<int> Solution::printListFromTailToHead(ListNode* head)
{
	
	vector<int> vec; 
	if (head == NULL)
		return vec;
	std::stack<int> sta;
	ListNode* pNode = head;
	while (pNode != NULL)
	{
		sta.push(pNode->val);
		pNode = pNode->next;
	}
	while (!sta.empty())
	{
		vec.push_back(sta.top());
		sta.pop();
	}
	return vec;
}

TreeNode* Solution::reConstructBinaryTree(vector<int> pre, vector<int> vin)
{
	if (pre.empty() || vin.empty() || pre.size() != vin.size())
		return NULL;

	return _reConstructBinaryTree(pre.begin(), pre.end()-1, vin.begin(), vin.end()-1);
}

TreeNode* _reConstructBinaryTree(vector<int>::iterator pre_begin, vector<int>::iterator pre_end, vector<int>::iterator vin_begin, vector<int>::iterator vin_end)
{

	int val = *pre_begin;
	TreeNode* root = new TreeNode(val);
	if (pre_begin == pre_end)
		return root;

	vector<int>::iterator begin = vin_begin;
	while (*begin != val && begin <= vin_end)
		++begin;
	int length = begin - vin_begin;
	vector<int>::iterator left_pre_end = pre_begin + length;

	if (length > 0)
		root->left = _reConstructBinaryTree(pre_begin + 1, left_pre_end, vin_begin, begin - 1);
	if (length < pre_end - pre_begin)
		root->right = _reConstructBinaryTree(left_pre_end + 1, pre_end, begin + 1, vin_end);
	return root;

}

void Queue::push(int node)
{
	stack1.push(node);
}
int Queue::pop()
{
	if (stack2.empty())
	{
		while (!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
	}
	int val = stack2.top();
	stack2.pop();
	return val;
}

void Stack::push(int node)
{
	if (!queue1.empty())
		queue1.push(node);
	else
		queue2.push(node);
}
int Stack::pop()
{
	if (!queue1.empty())
	{
		while (queue1.size() > 1)
		{
			queue2.push(queue1.front());
			queue1.pop();
		}
		int val = queue1.front();
		queue1.pop();
		return val;
	}
	else
	{
		if (queue2.empty())
			return NULL;
		while (queue2.size() > 1)
		{
			queue1.push(queue2.front());
			queue2.pop();
		}
		int val = queue2.front();
		queue2.pop();
		return val;
	}
}

int Solution::minNumberInRotateArray(vector<int> rotateArray)
{
	if (rotateArray.size() == 0)
		return 0;
	int left = 0;
	int right = rotateArray.size() - 1;
	int mid = 0;
	while (left < right)
	{
		if (right - left == 1)
			return rotateArray[right];
		mid = (left + right) / 2;
		if (rotateArray[mid] >= rotateArray[left] && rotateArray[left] >= rotateArray[right])
			left = mid + 1;
		else
			right = mid;

	}
	return rotateArray[right];
}

int Solution::Fibonacci(int n)
{
	if (n < 0)
		return NULL;
	int result[2] = { 0, 1 };
	if (n < 2)
		return result[n];
	int tmp = 0;
	for (int i = 2; i <= n; ++i)
	{
		tmp = result[1];
		result[1] += result[0];
		result[0] = tmp;
	}
	return result[1];
}

int Solution::jumpFloor(int number)
{
	if (number <= 0)
		return 0;
	int result[2] = { 1, 2 };
	if (number <= 2)
		return result[number - 1];
	int tmp = 0;
	for (int i = 3; i <= number; ++i)
	{
		tmp = result[1];
		result[1] += result[0];
		result[0] = tmp;
	}
	return result[1];
		
}

int Solution::jumpFloorII(int number)
{
	if (number <= 0)
		return 0;
	//if (number == 1)
	//	return 1;
	//int result = 1;
	//for (int i = 2; i <= number; ++i)
	//	result *= 2;

	int result = 1;

	return result << (number - 1);
}

int Solution::rectCover(int number) {
	if (number <= 0)
		return 0;
	int result[2] = { 1,2 };
	if (number <= 2)
		return result[number - 1];
	int tmp = 0;
	for (int i = 3; i <= number; ++i)
	{
		tmp = result[1];
		result[1] += result[0];
		result[0] = tmp;
	}
	return result[1];
}

double Solution::Power(double base, int exponent)
{
	if (base == 0)
		return 0;
	if (exponent == 0)
		return 1;
	double result = 1;
	if (exponent > 0)
	{
		for (int i = 1; i <= exponent; ++i)
			result *= base;
	}
	else
	{
		for (int i = 1; i <= -exponent; ++i)
			result *= (1 / base);
	}
	return result;
}

int Solution::movingCount(int threshold, int rows, int cols)
{
	int result = 0;
	int** map = new int*[rows];
	for (int i = 0; i < rows; ++i)
		map[i] = new int[cols]();
	_movingCount(0, 0, threshold, rows-1, cols-1, result, map);
	return result;
}

void _movingCount(int i, int j, int threshold, int rows, int cols, int& result, int** map)
{
	if (!moveIn(i, j, threshold) || i > rows || j > cols || map[i][j])
		return;
	++result;
	map[i][j] = 1;
	_movingCount(i + 1, j, threshold, rows, cols, result, map);
	_movingCount(i, j+1, threshold, rows, cols, result, map);
}

bool moveIn(int i, int j, int thres)
{
	int sum = 0;
	while (i)
	{
		sum += i % 10;
		i /= 10;
	}
	while (j)
	{
		sum += j % 10;
		j /= 10;
	}

	return sum <= thres;
}

int Solution::movingCount(int threshold, int rows, int cols, bool dfs)
{
	int result = 0;
	int** map = new int* [rows];
	for (int i = 0; i < rows; ++i)
		map[i] = new int[cols]();
	for (int i = 0; i < rows; ++i)
	{
		if (rows <= threshold)
			map[i][0] = 1;
		else
			map[i][0] = 0;
	}

	for (int i = 0; i < cols; ++i)
	{
		if (cols <= threshold)
			map[0][i] = 1;
		else
			map[0][0] = 0;
	}
	return result;
}