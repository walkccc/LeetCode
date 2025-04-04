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
    if (root == nullptr)
      return {0, 0, 0.0};

    const T left = maximumAverage(root->left);
    const T right = maximumAverage(root->right);

    const int sum = root->val + left.sum + right.sum;
    const int count = 1 + left.count + right.count;
    const double maxAverage =
        max({sum / (double)count, left.maxAverage, right.maxAverage});
    return {sum, count, maxAverage};
  }
};
