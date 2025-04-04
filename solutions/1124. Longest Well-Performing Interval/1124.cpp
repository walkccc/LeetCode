class Solution {
 public:
  int longestWPI(vector<int>& hours) {
    int ans = 0;
    int prefix = 0;
    unordered_map<int, int> map;

    for (int i = 0; i < hours.size(); ++i) {
      prefix += hours[i] > 8 ? 1 : -1;
      if (prefix > 0) {
        ans = i + 1;
      } else {
        if (!map.contains(prefix))
          map[prefix] = i;
        if (const auto it = map.find(prefix - 1); it != map.cend())
          ans = max(ans, i - it->second);
      }
    }

    return ans;
  }
};
