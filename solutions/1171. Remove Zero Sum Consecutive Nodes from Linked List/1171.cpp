class Solution {
 public:
  ListNode* removeZeroSumSublists(ListNode* head) {
    ListNode dummy(0);
    dummy.next = head;
    int prefixSum = 0;
    unordered_map<int, ListNode*> prefixSumToNode;
    prefixSumToNode[0] = &dummy;

    for (; head; head = head->next) {
      prefixSum += head->val;
      prefixSumToNode[prefixSum] = head;
    }

    prefixSum = 0;

    for (head = &dummy; head; head = head->next) {
      prefixSum += head->val;
      head->next = prefixSumToNode[prefixSum]->next;
    }

    return dummy.next;
  }
};