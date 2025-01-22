class Solution {
 public:
  int countMatches(vector<vector<string>>& items, string ruleKey,
                   string ruleValue) {
    const int index = ruleKey == "type" ? 0 : ruleKey == "color" ? 1 : 2;
    return ranges::count_if(items, [index, &ruleValue](const auto& item) {
      return item[index] == ruleValue;
    });
  }
};
