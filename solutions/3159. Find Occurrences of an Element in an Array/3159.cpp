class Solution {
 public:
  vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries,
                                   int x) {
    const vector<int> indices = getIndices(nums, x);
    vector<int> ans;

    for (const int query : queries)
      ans.push_back(query <= indices.size() ? indices[query - 1] : -1);

    return ans;
  }

 private:
  vector<int> getIndices(const vector<int>& nums, int x) {
    vector<int> indices;
    for (int i = 0; i < nums.size(); ++i)
      if (nums[i] == x)
        indices.push_back(i);
    return indices;
  }
};
