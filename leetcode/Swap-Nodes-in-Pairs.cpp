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
	ListNode* swapPairs(ListNode* head) {
		return swapPairs1(head);
		//return swapPairs2(head);
	}
	void push_front(ListNode *& head, int val) {
		ListNode * np = new ListNode(val);
		if (head){
			np->next = head;
		}
		head = np;
	}
	void Destroy(ListNode * head) {
		ListNode * del = head;
		while (head) {
			head = head->next;
			delete del;
			del = head;
		}
	}
private:
	ListNode * swapPairs1(ListNode * head)
	{
		for (ListNode * p = head; p && p->next; p = p->next->next) {
			int n = p->val;
			p->val = p->next->val;
			p->next->val = n;
		}
		return head;
	}

	ListNode * swapPairs2(ListNode * head) {	
		ListNode * hp = NULL;
		for (ListNode * p = head; p && p->next; p = p->next) {
			ListNode * n = p->next;
			p->next = n->next;
			n->next = p;

			if (hp) {
				hp->next = n;
			}
			hp = p;

			if (head == p) {
				head = n;
			}
		}
		return head;
	}

};

int main()
{
	ListNode * l1 = NULL;
	Solution so;
	so.push_front(l1, 1);
	so.push_front(l1, 2);
	so.push_front(l1, 3);
	so.push_front(l1, 4);
	so.push_front(l1, 5);
	so.push_front(l1, 6);
	
	so.swapPairs(l1);
	so.Destroy(l1);
	
	return 0;
}
#endif
