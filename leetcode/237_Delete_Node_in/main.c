#include <stdlib.h>
/**
Definition for singly-linked list.
**/
struct ListNode {
	int val;
	struct ListNode *next;
};

void deleteNode(struct ListNode* node) {
	struct ListNode* temp = node->next;

	node->val = node->next->val;
	node->next = node->next->next;

	free(temp);
}

int main() {
	deleteNode(0);
	return 0;
}
