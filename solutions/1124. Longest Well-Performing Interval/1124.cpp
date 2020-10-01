class Solution {
 public:
  int longestWPI(vector<int>& hours) {
    int ans = 0;
    int prefixSum = 0;
    unordered_map<int, int> map;

    for (int i = 0; i < hours.size(); ++i) {
      prefixSum += hours[i] > 8 ? 1 : -1;
      if (prefixSum > 0) {
        ans = i + 1;
      } else {
        if (!map.count(prefixSum)) map[prefixSum] = i;
        if (map.count(prefixSum - 1)) ans = max(ans, i - map[prefixSum - 1]);
      }
    }

    return ans;
  }
};