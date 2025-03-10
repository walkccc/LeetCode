class Solution {
 public:
  // Same as 3346. Maximum Frequency of an Element After Performing Operations I
  int maxFrequency(vector<int>& nums, int k, int numOperations) {
    int ans = 1;
    int adjustable = 0;
    unordered_map<int, int> count;
    map<int, int> line;
    set<int> candidates;

    for (const int num : nums) {
      ++count[num];
      ++line[num - k];
      --line[num + k + 1];
      candidates.insert(num);
      candidates.insert(num - k);
      candidates.insert(num + k + 1);
    }

    for (const int num : candidates) {
      adjustable += line.contains(num) ? line[num] : 0;
      const int countNum = count.contains(num) ? count[num] : 0;
      const int adjusted = adjustable - countNum;
      ans = max(ans, countNum + min(numOperations, adjusted));
    }

    return ans;
  }
};
