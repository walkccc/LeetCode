class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (!head)
      return nullptr;
    if (map.count(head))
      return map[head];

    Node* newNode = new Node(head->val);
    map[head] = newNode;
    newNode->next = copyRandomList(head->next);
    newNode->random = copyRandomList(head->random);
    return newNode;
  }

 private:
  unordered_map<Node*, Node*> map;
};
