class Solution {
 public:
  ListNode* removeZeroSumSublists(ListNode* head) {
    ListNode dummy(0, head);
    int prefix = 0;
    unordered_map<int, ListNode*> prefixToNode;
    prefixToNode[0] = &dummy;

    for (; head; head = head->next) {
      prefix += head->val;
      prefixToNode[prefix] = head;
    }

    prefix = 0;

    for (head = &dummy; head; head = head->next) {
      prefix += head->val;
      head->next = prefixToNode[prefix]->next;
    }

    return dummy.next;
  }
};
