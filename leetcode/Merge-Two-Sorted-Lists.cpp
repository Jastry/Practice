#include <iostream>
#if 1
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode * p1 = l1;
		ListNode * p2 = l2;
		if (p1 == NULL || p2 == NULL) {
			return p1 == NULL ? p2 : p1;
		}
		ListNode * fakehead = new ListNode(0);
		ListNode * cur = fakehead;
		while (p1 && p2) {
			if (p1->val >= p2->val) {
				cur->next = p2;
				p2 = p2->next;
			}
			else {
				cur->next = p1;
				p1 = p1->next;
			}
			cur = cur->next;
			cur->next = NULL;
		}
		if (p1 == NULL)
			cur->next = p2;
		else
			cur->next = p1;
		cur = fakehead;
		fakehead = fakehead->next;
		delete cur;
		return fakehead;
	}
};
#endif
