class BSTIterator {
 public:
  BSTIterator(TreeNode* root) {
    pushLeftsUntilNull(root);
  }

  int peek() {
    return stack.top()->val;
  }

  void next() {
    TreeNode* node = stack.top();
    stack.pop();
    pushLeftsUntilNull(node->right);
  }

  bool hasNext() {
    return !stack.empty();
  }

 private:
  stack<TreeNode*> stack;

  void pushLeftsUntilNull(TreeNode* node) {
    while (node) {
      stack.push(node);
      node = node->left;
    }
  }
};

class Solution {
 public:
  vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    vector<int> ans;
    BSTIterator bstIterator1(root1);
    BSTIterator bstIterator2(root2);

    while (bstIterator1.hasNext() && bstIterator2.hasNext())
      if (bstIterator1.peek() < bstIterator2.peek()) {
        ans.push_back(bstIterator1.peek());
        bstIterator1.next();
      } else {
        ans.push_back(bstIterator2.peek());
        bstIterator2.next();
      }

    while (bstIterator1.hasNext()) {
      ans.push_back(bstIterator1.peek());
      bstIterator1.next();
    }

    while (bstIterator2.hasNext()) {
      ans.push_back(bstIterator2.peek());
      bstIterator2.next();
    }

    return ans;
  }
};
