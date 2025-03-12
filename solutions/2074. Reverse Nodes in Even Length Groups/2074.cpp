class Solution {
 public:
  ListNode* reverseEvenLengthGroups(ListNode* head) {
    // prev -> (head -> ... -> tail) -> next -> ...
    ListNode dummy(0, head);
    ListNode* prev = &dummy;
    ListNode* tail = head;
    ListNode* next = head->next;
    int groupLength = 1;

    while (true) {
      if (groupLength % 2 == 1) {
        prev->next = head;
        prev = tail;
      } else {
        tail->next = nullptr;
        prev->next = reverse(head);
        // Prev -> (tail -> ... -> head) -> next -> ...
        head->next = next;
        prev = head;
      }
      if (next == nullptr)
        break;
      head = next;
      const auto [theTail, theLength] = getTailAndLength(head, groupLength + 1);
      tail = theTail;
      next = tail->next;
      groupLength = theLength;
    }

    return dummy.next;
  }

 private:
  pair<ListNode*, int> getTailAndLength(ListNode* head, int groupLength) {
    int length = 1;
    ListNode* tail = head;
    while (length < groupLength && tail->next) {
      tail = tail->next;
      ++length;
    }
    return {tail, length};
  }

  ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    while (head != nullptr) {
      ListNode* next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }
    return prev;
  }
};
