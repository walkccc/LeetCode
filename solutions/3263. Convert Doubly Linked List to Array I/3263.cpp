class Solution {
 public:
  vector<int> toArray(Node* head) {
    vector<int> ans;
    Node* curr = head;

    while (curr != nullptr) {
      ans.push_back(curr->val);
      curr = curr->next;
    }

    return ans;
  }
};
