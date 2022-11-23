class Solution {
 public:
  int mostFrequentEven(vector<int>& nums) {
    int ans = -1;
    unordered_map<int, int> count;

    for (const int num : nums) {
      if (num & 1)
        continue;
      const int newCount = ++count[num];
      const int maxCount = count[ans];
      if (newCount > maxCount || newCount == maxCount && num < ans)
        ans = num;
    }

    return ans;
  }
};
