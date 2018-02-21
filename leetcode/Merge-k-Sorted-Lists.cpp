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


/****************************************************
*				method 2							*
****************************************************/
class Solution2 {
	/******************************************************
	 维护一个k个大小的最小堆，
	 初始化堆中元素为每个链表的头结点，
	 每次从堆中选择最小的元素加入到结果链表，
	 再选择该最小元素所在链表的下一个节点加入到堆中。
	 这样当堆为空时，所有链表的节点都已经加入了结果链表。
	 元素加入堆中的复杂度为O（longk），总共有kn个元素加入堆中，
	 因此，复杂度O（nklogk）
	 *******************************************************/
public:
	struct cmp {
		bool operator()(ListNode * left, ListNode * right) {
			return left->val > right->val;
		}
	};

	ListNode * mergeKLists(std::vector< ListNode * >& lists) {
		ListNode * head = nullptr;
		ListNode ** ppcur = &head;

		std::priority_queue<ListNode *, std::vector< ListNode * >, cmp> pq;
		for (auto list : lists) {
			if (list) {
				pq.emplace(list);
			}
		}
		while (!pq.empty()) {
			auto cur = pq.top();
			pq.pop();
			*ppcur = cur;
			if (cur->next) {
				pq.emplace(cur->next);
			}
			ppcur = &(*ppcur)->next;
		}
		return head;
	}
};

/****************************************************
 *				method 1							*
 ****************************************************/

class Solution {
	//总共遍历的节点数目为n(2+3+…+k) = n*(k^2+k-2)/2, 因此时间复杂度是O(n*(k^2+k-2)/2) = O(nk^2)
public:
	ListNode* mergeKLists(std::vector<ListNode*>& lists) {
		if (lists.size() <= 0)
			return NULL;

		ListNode * res = lists[0];

		for (int i = 1; i < lists.size(); ++i) {
			res = MergeTwoSortList(res, lists[i]);
		}
		return res;
	}
	
private:
	ListNode * MergeTwoSortList(ListNode * l1, ListNode * l2)
	{
		ListNode * p1 = l1;
		ListNode * p2 = l2;
		if (l1 == NULL || l2 == NULL) {
			return l1 != NULL ? l1 : l2;
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
		}
		if (p1 == NULL) {
			cur->next = p2;
		}
		else {
			cur->next = p1;
		}
		cur = fakehead;
		fakehead = fakehead->next;
		delete cur;
		return fakehead;
	}

};

#endif

