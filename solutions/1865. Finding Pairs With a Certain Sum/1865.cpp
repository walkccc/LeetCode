class FindSumPairs {
 public:
  FindSumPairs(vector<int>& nums1, vector<int>& nums2)
      : nums1(nums1), nums2(nums2) {
    for (const int num : nums2)
      ++count2[num];
  }

  void add(int index, int val) {
    --count2[nums2[index]];
    nums2[index] += val;
    ++count2[nums2[index]];
  }

  int count(int tot) {
    int ans = 0;
    for (const int num : nums1) {
      const int target = tot - num;
      if (count2.count(target))
        ans += count2[target];
    }
    return ans;
  }

 private:
  vector<int> nums1;
  vector<int> nums2;
  unordered_map<int, int> count2;
};
