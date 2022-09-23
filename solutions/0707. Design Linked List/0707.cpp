class MyLinkedList {
  struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
  };

 public:
  int get(int index) {
    if (index < 0 || index >= length)
      return -1;
    ListNode* curr = dummy.next;
    for (int i = 0; i < index; ++i)
      curr = curr->next;
    return curr->val;
  }

  void addAtHead(int val) {
    ListNode* head = dummy.next;
    ListNode* node = new ListNode(val);
    node->next = head;
    dummy.next = node;
    ++length;
  }

  void addAtTail(int val) {
    ListNode* curr = &dummy;
    while (curr->next)
      curr = curr->next;
    curr->next = new ListNode(val);
    ++length;
  }

  void addAtIndex(int index, int val) {
    if (index > length)
      return;
    ListNode* curr = &dummy;
    for (int i = 0; i < index; ++i)
      curr = curr->next;
    ListNode* cache = curr->next;
    ListNode* node = new ListNode(val);
    node->next = cache;
    curr->next = node;
    ++length;
  }

  void deleteAtIndex(int index) {
    if (index < 0 || index >= length)
      return;
    ListNode* curr = &dummy;
    for (int i = 0; i < index; ++i)
      curr = curr->next;
    ListNode* cache = curr->next;
    curr->next = cache->next;
    --length;
    delete cache;
  }

 private:
  int length = 0;
  ListNode dummy = ListNode(0);
};
