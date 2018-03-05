#include <iostream>

/* 找两个链表的第一个共同节点 */
#if 1
class Solution {
public:
	ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == NULL || pHead2 == NULL)	return NULL;
		ListNode * p1 = pHead1;
		ListNode * p2 = pHead2;

		while (p1 != p2) {
			p1 = p1 ? p1->next : pHead2;
			p2 = p2 ? p2->next : pHead1;
		}
	}

	void push_front(ListNode *& head, int val) {
		ListNode * node = new ListNode(val);
		node->next = head;
		head = node;
	}

	ListNode * find(ListNode * head, int val) {
		ListNode * cur = head;
		while (cur) {
			if (cur->val == val) {
				return cur;
			}
			cur = cur->next;
		}
		return NULL;
	}
	void destroy(ListNode * head) {
		if (NULL == head) return;
		while (head) {
			ListNode * del = head;
			head = head->next;
			delete del;
		}
	}
};

int main()
{
	Solution so;
	ListNode * head = NULL;
	so.push_front(head, 1);
	so.push_front(head, 2);
	so.push_front(head, 3);
	so.push_front(head, 4);
	so.push_front(head, 5);
	so.push_front(head, 6);
	so.push_front(head, 7);
	ListNode * tamp = so.find(head, 1);
	ListNode * res = so.FindFirstCommonNode(tamp, head);

	so.destroy(head);
	return 0;
}
#endif

