class Solution {
 public:
  vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    int minDistance = INT_MAX;
    int firstMaIndex = -1;
    int prevMaIndex = -1;
    int index = 1;
    ListNode* prev = head;        // Point to the index 0.
    ListNode* curr = head->next;  // Point to the index 1.

    while (curr->next != nullptr) {
      if (curr->val > prev->val && curr->val > curr->next->val ||
          curr->val < prev->val && curr->val < curr->next->val) {
        if (firstMaIndex == -1)  // Only assign once.
          firstMaIndex = index;
        if (prevMaIndex != -1)
          minDistance = min(minDistance, index - prevMaIndex);
        prevMaIndex = index;
      }
      prev = curr;
      curr = curr->next;
      ++index;
    }

    if (minDistance == INT_MAX)
      return {-1, -1};
    return {minDistance, prevMaIndex - firstMaIndex};
  }
};
