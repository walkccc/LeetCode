class Solution {
 public:
  int maxRepOpt1(string text) {
    int ans = 0;
    vector<int> count(26);
    vector<pair<char, int>> groups{{text[0], 1}};

    for (char c : text)
      ++count[c - 'a'];

    for (int i = 1; i < text.length(); ++i)
      if (text[i] == text[i - 1])
        ++groups[groups.size() - 1].second;
      else
        groups.emplace_back(text[i], 1);

    for (const auto& [c, length] : groups)
      ans = max(ans, min(length + 1, count[c - 'a']));

    for (int i = 1; i + 1 < groups.size(); ++i)
      if (groups[i - 1].first == groups[i + 1].first && groups[i].second == 1)
        ans = max(ans, min(groups[i - 1].second + groups[i + 1].second + 1,
                           count[groups[i - 1].first - 'a']));

    return ans;
  }
};
