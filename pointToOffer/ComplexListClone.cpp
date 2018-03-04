#include <iostream>

/* 复杂链表的复制 */
#if 1
struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};

class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (pHead == NULL) return nullptr;
		RandomListNode * cur = pHead;

		/* 往后追加 clone 节点 */
		while (cur) {
			RandomListNode * tamp = new RandomListNode(cur->label);
			tamp->next = cur->next;
			cur->next = tamp;
			cur = tamp->next;
		}

		/* 复制 random 节点 */
		cur = pHead;
		while (cur) {
			RandomListNode * pclone = cur->next;
			if (cur->random)
				pclone->random = cur->random->next;
			cur = pclone->next;
		}

		/* 拆分 */
		RandomListNode * pclone = pHead->next;
		cur = pHead;
		RandomListNode * pnode = pclone;
		if (pHead != NULL) {
			cur->next = pclone->next;
			cur = cur->next;
		}

		while (cur != NULL) {
			pclone->next = cur->next;
			pclone = pclone->next;
			cur->next = pclone->next;
			cur = cur->next;
		}
		return pnode;
	}
};
#endif
