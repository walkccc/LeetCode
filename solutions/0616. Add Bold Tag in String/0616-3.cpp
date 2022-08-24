class Solution {
 public:
  string addBoldTag(string s, vector<string>& words) {
    string ans;
    vector<pair<int, int>> intervals;
    vector<pair<int, int>> merged;

    for (const string& word : words) {
      const int n = word.length();
      for (int i = 0; i + n <= s.length(); ++i)
        if (s.substr(i, n) == word)
          intervals.emplace_back(i, i + n);
    }

    if (intervals.empty())
      return s;

    sort(begin(intervals), end(intervals));

    for (const auto& interval : intervals)
      if (merged.empty() || merged.back().second < interval.first)
        merged.push_back(interval);
      else
        merged.back().second = max(merged.back().second, interval.second);

    int prevEnd = 0;

    for (const auto& [startIndex, endIndex] : merged) {
      ans += s.substr(prevEnd, startIndex - prevEnd);
      ans += "<b>" + s.substr(startIndex, endIndex - startIndex) + "</b>";
      prevEnd = endIndex;
    }

    if (!merged.empty())
      ans += s.substr(merged.back().second);

    return ans;
  }
};
