class Solution {
 public:
  int uniqueXorTriplets(vector<int>& nums) {
    const int n = nums.size();
    if (n == 1)
      return 1;

    unordered_set<int> pairs;
    bitset<2048> triplets;

    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        pairs.insert(nums[i] ^ nums[j]);

    for (const int pair : pairs)
      for (const int num : nums)
        triplets.set(pair ^ num);

    return triplets.count();
  }
};
