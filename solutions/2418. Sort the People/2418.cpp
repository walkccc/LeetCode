class Solution {
 public:
  vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    vector<string> ans;
    vector<pair<int, string>> heightAndNames;

    for (int i = 0; i < names.size(); ++i)
      heightAndNames.emplace_back(heights[i], names[i]);

    sort(heightAndNames.begin(), heightAndNames.end(), greater<>());

    for (const auto& [_, name] : heightAndNames)
      ans.push_back(name);

    return ans;
  }
};
