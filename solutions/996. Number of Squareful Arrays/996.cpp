class Solution {
 public:
  int numSquarefulPerms(vector<int>& nums) {
    int ans = 0;
    ranges::sort(nums);
    dfs(nums, vector<bool>(nums.size()), {}, ans);
    return ans;
  }

 private:
  void dfs(vector<int>& nums, vector<bool>&& used, vector<int>&& path,
           int& ans) {
    if (path.size() > 1 && !isSquare(path.back() + path[path.size() - 2]))
      return;
    if (path.size() == nums.size()) {
      ++ans;
      return;
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (used[i])
        continue;
      if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
        continue;
      used[i] = true;
      path.push_back(nums[i]);
      dfs(nums, std::move(used), std::move(path), ans);
      path.pop_back();
      used[i] = false;
    }
  }

  bool isSquare(int num) {
    const int root = sqrt(num);
    return root * root == num;
  }
};
