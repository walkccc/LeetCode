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
        if (!map.count(prefix))
          map[prefix] = i;
        if (map.count(prefix - 1))
          ans = max(ans, i - map[prefix - 1]);
      }
    }

    return ans;
  }
};
