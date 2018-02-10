#include <iostream>
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
	ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == NULL || (n <= 0))
			return NULL;

		ListNode fakeHead(0);
		//冒牌头节点
		fakeHead.next = head;
		head = &fakeHead;
		
		ListNode * fast = head;
		ListNode * slow = head;
		for (int i = 0; i < n && (fast != NULL); ++i) {
			fast = fast->next;
		}
		if (fast == NULL)
			return slow;
		while (fast) {
			slow = slow->next;
			fast = fast->next;
		}
		slow->next = slow->next->next;
		return head->next;
	}
};
#endif

