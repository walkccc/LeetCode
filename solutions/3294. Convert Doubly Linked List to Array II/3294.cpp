class Solution {
 public:
  vector<int> toArray(Node* node) {
    vector<int> ans;
    Node* curr = node;

    while (curr->prev != nullptr)
      curr = curr->prev;

    while (curr != nullptr) {
      ans.push_back(curr->val);
      curr = curr->next;
    }

    return ans;
  }
};
