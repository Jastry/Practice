#include <iostream>

/* 找出带环链表的头节点 */

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL)
			return NULL;
		ListNode * slow = pHead;
		ListNode * fast = pHead;
		do {
			slow = slow->next;
			fast = fast->next->next;
		} while (fast != slow && fast->next);

		if (fast != slow)
			return NULL;
		ListNode * entry = pHead;
		while (entry != fast) {
			fast = fast->next;
			entry = entry->next;
		}
		return entry;
	}
};

