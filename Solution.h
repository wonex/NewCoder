#pragma once
#ifndef SOLUTION_H
#define SOLUTION_H
#include <vector>
#include <stack>
#include <queue>


using std::vector;
using std::stack;
using std::queue;

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) :
		val(x), next(NULL) {
		
	}
	
};


//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

class Solution
{
public:
	bool Find(int, vector<vector<int>>);
	void replaceSpace(char*, int);
	vector<int> printListFromTailToHead(ListNode* head);
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin);
	int minNumberInRotateArray(vector<int> rotateArray);
};

class Queue
{
public:
	void push(int node);

	int pop();

private:
    stack<int> stack1;
    stack<int> stack2;
};

class Stack
{
public:
	void push(int node);

	int pop();

private:
	queue<int> queue1;
	queue<int> queue2;
};
#endif // !SOLUTION_H



