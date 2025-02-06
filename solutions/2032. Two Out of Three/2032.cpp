class Solution {
 public:
  vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2,
                            vector<int>& nums3) {
    vector<int> ans;
    vector<int> count(101);

    for (const vector<int>& nums : {nums1, nums2, nums3})
      update(count, nums);

    for (int i = 1; i <= 100; ++i)
      if (count[i] >= 2)
        ans.push_back(i);

    return ans;
  }

 private:
  void update(vector<int>& count, const vector<int>& nums) {
    for (const int num : unordered_set<int>(nums.begin(), nums.end()))
      ++count[num];
  }
};
