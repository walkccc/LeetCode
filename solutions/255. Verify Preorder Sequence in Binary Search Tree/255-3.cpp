class Solution {
 public:
  bool verifyPreorder(vector<int>& preorder) {
    int low = INT_MIN;
    int i = -1;

    for (const int p : preorder) {
      if (p < low)
        return false;
      while (i >= 0 && preorder[i] < p)
        low = preorder[i--];
      preorder[++i] = p;
    }

    return true;
  }
};
