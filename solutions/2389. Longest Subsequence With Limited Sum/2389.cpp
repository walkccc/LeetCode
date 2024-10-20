class Solution {
 public:
  vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    vector<int> ans;

    ranges::sort(nums);

    for (const int query : queries)
      ans.push_back(numOfElementsLessThan(nums, query));

    return ans;
  }

 private:
  int numOfElementsLessThan(const vector<int>& nums, int query) {
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      if (sum > query)
        return i;
    }
    return nums.size();
  }
};
