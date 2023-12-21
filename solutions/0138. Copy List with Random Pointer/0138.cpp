class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (head == nullptr)
      return nullptr;
    if (const auto it = map.find(head); it != map.cend())
      return it->second;

    Node* newNode = new Node(head->val);
    map[head] = newNode;
    newNode->next = copyRandomList(head->next);
    newNode->random = copyRandomList(head->random);
    return newNode;
  }

 private:
  unordered_map<Node*, Node*> map;
};
