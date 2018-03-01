#include <iostream>

/* 输入一个链表，反转链表后，输出链表的所有元素 */
#if 1

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == NULL || pHead->next == NULL)
			return pHead;
		ListNode * res = NULL;
		ListNode * next = NULL;
		while (pHead) {
			next = pHead->next;
			pHead->next = res;

			res = pHead;
			pHead = next;
		}
		return res;
	}

};
#endif

