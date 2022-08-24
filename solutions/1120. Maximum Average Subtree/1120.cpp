struct T {
  int sum;
  int count;
  double maxAverage;
};

class Solution {
 public:
  double maximumAverageSubtree(TreeNode* root) {
    return maximumAverage(root).maxAverage;
  }

 private:
  T maximumAverage(TreeNode* root) {
    if (!root)
      return {0, 0, 0.0};

    T l = maximumAverage(root->left);
    T r = maximumAverage(root->right);

    const int sum = root->val + l.sum + r.sum;
    const int count = 1 + l.count + r.count;
    const double maxAverage =
        max({sum / (double)count, l.maxAverage, r.maxAverage});
    return {sum, count, maxAverage};
  }
};
