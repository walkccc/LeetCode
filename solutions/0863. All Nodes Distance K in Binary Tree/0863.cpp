class Solution {
 public:
  vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    vector<int> ans;
    unordered_map<TreeNode*, int> nodeToDistance;

    function<void(TreeNode*)> findDistance = [&](TreeNode* root) {
      if (!root) return;
      if (root == target) {
        nodeToDistance[root] = 0;
        return;
      }

      findDistance(root->left);
      if (nodeToDistance.count(root->left)) {
        nodeToDistance[root] = nodeToDistance[root->left] + 1;
        return;
      }

      findDistance(root->right);
      if (nodeToDistance.count(root->right)) {
        nodeToDistance[root] = nodeToDistance[root->right] + 1;
      }
    };

    function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int distance) {
      if (!root) return;

      if (nodeToDistance.count(root))
        distance = nodeToDistance[root];
      if (distance == K)
        ans.push_back(root->val);

      dfs(root->left, distance + 1);
      dfs(root->right, distance + 1);
    };

    findDistance(root);
    dfs(root, 0);

    return ans;
  }
};