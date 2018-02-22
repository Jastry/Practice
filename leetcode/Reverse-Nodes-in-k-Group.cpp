#include <iostream>


/* 链表逆转 */
#if 1
struct ListNode {
	int val;
	struct ListNode * next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == NULL || head->next == NULL || k <= 0)
			return head;
		ListNode fakenode(0);
		fakenode.next = head;
		ListNode * p = &fakenode;

		while (p) {
			p->next = reverseList(p->next, k);
			for (auto i = 0; p && i < k; ++i) {
				p = p->next;
			}
		}
		return fakenode.next;
	}
private:
	ListNode * reverseList(ListNode * head, int k) {
		ListNode * tail = head;
		while (tail && k > 0) {
			tail = tail->next;
			k--;
		}
		if (k > 0) {
			return head;
		}

		ListNode * begin = tail;
		ListNode * p = head;
		while (p != tail) {
			ListNode * q = p->next;
			p->next = begin;
			begin = p;
			p = q;
		}
		return begin;
	}
};

ListNode * CreateList(int a[], int n) {
	assert(a);
	ListNode *head = NULL, *p = NULL;
	for (auto i = 0; i < n; ++i) {
		if (head == NULL) {
			head = p = new ListNode(a[i]);
		}
		else {
			p->next = new ListNode(a[i]);
			p = p->next;
		}
	}
	return head;
}

void Destroy(ListNode * head) {
	if (head == NULL)
		return;
	ListNode * del = head;
	while (head) {
		head = head->next;
		delete del;
		del = head;
	}
}
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution2 {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* node = head;
		ListNode* rev;
		int tmp = k - 1;
		int i;


		for (i = 0; i<k; i++) {
			if (node == NULL) {
				return head;
			}
			node = node->next;
		}

		rev = reverse(head, node);
		head->next = reverseKGroup(node, k);
		return rev;
	}

	ListNode * reverse(ListNode *start, ListNode *end) {
		ListNode *prev = end;
		ListNode *next;


		while (start != end) {
			next = start->next;
			start->next = prev;
			prev = start;
			start = next;
		}

		return prev;

	}
};
int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6 };
	ListNode * head = CreateList(a, sizeof(a) / sizeof(a[0]));
	Solution2 so;
	so.reverseKGroup(head, 2);
	Destroy(head);
	return 0;
}

#endif
