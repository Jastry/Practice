#include <iostream>


class Solution {
public:
	std::vector<int> printListFromTailToHead(ListNode* head) {
		std::vector<int> res;
		std::vector<ListNode * >tamp;
		if (head == NULL)
			return res;
		while (head) {
			tamp.push_back(head);
			head = head->next;
		}
		res.resize(tamp.size());

		int index = 0;
		for (int i = tamp.size() - 1; i >= 0; --i) {
			res[index++] = tamp[i]->val;
		}
		return res;
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

/* 销毁链表 */
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

int main()
{	
	int a[] = { 1, 2, 3, 4, 5, 6, 7 };
	ListNode * head = CreateList(a, sizeof(a) / sizeof(int));
	Solution so;
	std::vector<int> v = so.printListFromTailToHead(head);
    Destroy(head);
    return 0;
}
#endif

