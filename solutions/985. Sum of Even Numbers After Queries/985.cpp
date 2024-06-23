class Solution {
 public:
  vector<int> sumEvenAfterQueries(vector<int>& nums,
                                  vector<vector<int>>& queries) {
    vector<int> ans;
    int sum =
        accumulate(nums.begin(), nums.end(), 0, [](int subtotal, int num) {
          return subtotal + (num % 2 == 0 ? num : 0);
        });

    for (const vector<int>& query : queries) {
      const int val = query[0];
      const int index = query[1];
      if (nums[index] % 2 == 0)
        sum -= nums[index];
      nums[index] += val;
      if (nums[index] % 2 == 0)
        sum += nums[index];
      ans.push_back(sum);
    }

    return ans;
  }
};
