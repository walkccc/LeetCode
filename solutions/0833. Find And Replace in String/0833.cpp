class Solution {
 public:
  string findReplaceString(string s, vector<int>& indices,
                           vector<string>& sources, vector<string>& targets) {
    vector<pair<int, int>> sortedIndices;

    for (int i = 0; i < indices.size(); ++i)
      sortedIndices.emplace_back(indices[i], i);

    sort(rbegin(sortedIndices), rend(sortedIndices));

    for (const auto& [index, i] : sortedIndices) {
      const string& source = sources[i];
      const string& target = targets[i];
      if (s.substr(index, source.length()) == source)
        s = s.substr(0, index) + target + s.substr(index + source.length());
    }

    return s;
  }
};
