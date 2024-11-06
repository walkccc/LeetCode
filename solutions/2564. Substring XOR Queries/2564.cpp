class Solution {
 public:
  vector<vector<int>> substringXorQueries(string s,
                                          vector<vector<int>>& queries) {
    constexpr int kMaxBit = 30;
    vector<vector<int>> ans;
    // {val: (left, right)} := s[left..right]'s decimal value = val
    unordered_map<int, pair<int, int>> valToLeftAndRight;

    for (int left = 0; left < s.length(); ++left) {
      int val = 0;
      if (s[left] == '0') {
        // edge case: Save the index of the first 0.
        if (!valToLeftAndRight.contains(0))
          valToLeftAndRight[0] = {left, left};
        continue;
      }
      const int maxRight = min(static_cast<int>(s.length()), left + kMaxBit);
      for (int right = left; right < maxRight; ++right) {
        val = val * 2 + s[right] - '0';
        if (!valToLeftAndRight.contains(val))
          valToLeftAndRight[val] = {left, right};
      }
    }

    for (const vector<int>& query : queries) {
      const int first = query[0];
      const int second = query[1];
      const int val = first ^ second;
      const auto it = valToLeftAndRight.find(val);
      if (it == valToLeftAndRight.cend()) {
        ans.push_back({-1, -1});
      } else {
        const auto [left, right] = it->second;
        ans.push_back({left, right});
      }
    }

    return ans;
  }
};
