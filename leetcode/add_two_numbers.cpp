
 /*
  * Source : https://leetcode.com/problems/add-two-numbers/description/
  * Author : blb
  * Date   : 2018 年 1 月 3日
  */

/*
 * 
 *	You are given two non-empty linked lists representing two non-negative integers. 
 *	The digits are stored in reverse order and each of their nodes contain a single digit. 
 *	Add the two numbers and return it as a linked list.
 *	You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 *	Example
 *
 *	Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 *	Output: 7 -> 0 -> 8
 *	Explanation: 342 + 465 = 807.
 */


/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


/* java 版本
public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
	ListNode dummyHead = new ListNode(0);
	ListNode p = l1, q = l2, curr = dummyHead;
	int carry = 0;
	while (p != null || q != null) {
		int x = (p != null) ? p.val : 0;
		int y = (q != null) ? q.val : 0;
		int sum = carry + x + y;
		carry = sum / 10;
		curr.next = new ListNode(sum % 10);
		curr = curr.next;
		if (p != null) p = p.next;
		if (q != null) q = q.next;
	}
	if (carry > 0) {
		curr.next = new ListNode(carry);
	}
	return dummyHead.next;
}
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
	ListNode()
		:val(0), next(NULL)
	{}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == NULL && l2 == NULL)
			return NULL;
		int carry = 0;
		int sum = 0;


		ListNode* head = NULL;
		ListNode* tail = head;
		

		while (l1 != NULL || l2 != NULL) {
			int x = GetValueAndMoveNext(l1);
			int y = GetValueAndMoveNext(l2);
			sum = carry + x + y;
			if (head == NULL) {
				head = new ListNode(sum % 10);
				tail = head;
			}
			else {
				tail->next = new ListNode(sum % 10);
				tail = tail->next;
			}
			
		}
		if (carry > 0) {
			ListNode* pnode = new ListNode(carry);
			tail->next = pnode;
		}
		return head;
	}
private:
	int GetValueAndMoveNext(ListNode* &list)
	{
		if (NULL == list)
			return 0;
		int x = list->val;
		list = list->next;
		return x;
	}
};

int main()
{
	ListNode* pl = new ListNode[10];
	ListNode* l1 = &pl[0];
	ListNode* l2 = &pl[3];
	int i = 0;
	for (; i < 3; ++i) {
		pl[i].val = i;
		if (i < 2)
			pl[i].next = &pl[i + 1];
	}

	for (; i < 10; ++i) {
		pl[i].val = i;
		if (i < 9)
			pl[i].next = &pl[i + 1];
	}
	
	Solution solution;
	ListNode* tamp = solution.addTwoNumbers(l1, l2);
	delete[] pl;
	while (tamp) {
		ListNode* del = tamp;
		tamp = tamp->next;
		delete(del);
	}
	return 0;
}
