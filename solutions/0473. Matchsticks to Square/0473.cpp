class Solution {
 public:
  bool makesquare(vector<int>& nums) {
    if (nums.size() < 4)
      return false;

    const int perimeter = accumulate(begin(nums), end(nums), 0);
    if (perimeter % 4 != 0)
      return false;

    vector<int> edges(4, perimeter / 4);

    sort(begin(nums), end(nums), greater<int>());

    return dfs(nums, 0, edges);
  }

 private:
  bool dfs(const vector<int>& nums, int selected, vector<int>& edges) {
    if (selected == nums.size())
      return all_of(begin(edges), end(edges),
                    [](int edge) { return edge == 0; });

    for (int i = 0; i < 4; ++i) {
      if (nums[selected] > edges[i])
        continue;
      edges[i] -= nums[selected];
      if (dfs(nums, selected + 1, edges))
        return true;
      edges[i] += nums[selected];
    }

    return false;
  }
};
