class Solution {
 public:
  // If sorted(nums)[i + 1] - sorted(nums)[i] > 1, then there's a gap. Instead
  // of determining the number of gaps in each subarray, let's find out how many
  // subarrays contain each gap.
  int sumImbalanceNumbers(vector<int>& nums) {
    const int n = nums.size();
    int ans = 0;
    // Note that to avoid double counting, only `left` needs to check nums[i].
    // This adjustment ensures that i represents the position of the leftmost
    // element of nums[i] within the subarray.

    // left[i] := the maximum index l s.t. nums[l] = nums[i] or nums[i] + 1
    vector<int> left(n);
    // right[i] := the minimum index r s.t. nums[r] = nums[i]
    vector<int> right(n);

    vector<int> numToIndex(n + 2, -1);
    for (int i = 0; i < n; ++i) {
      left[i] = max(numToIndex[nums[i]], numToIndex[nums[i] + 1]);
      numToIndex[nums[i]] = i;
    }

    fill(numToIndex.begin(), numToIndex.end(), n);
    for (int i = n - 1; i >= 0; --i) {
      right[i] = numToIndex[nums[i] + 1];
      numToIndex[nums[i]] = i;
    }

    // The gap above nums[i] persists until encountering nums[i] or nums[i] + 1.
    // Consider subarrays nums[l..r] with l <= i <= r, where l in [left[i], i]
    // and r in [i, right[i] - 1]. There are (i - left[i]) * (right[i] - i)
    // subarrays satisfying this condition.
    for (int i = 0; i < n; ++i)
      ans += (i - left[i]) * (right[i] - i);

    // Subtract n * (n + 1) / 2 to account for the overcounting of elements
    // initially assumed to have a gap. This adjustment is necessary as the
    // maximum element of every subarray does not have a gap.
    return ans - n * (n + 1) / 2;
  }
};
