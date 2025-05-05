class Solution {
 public:
  string findReplaceString(string s, vector<int>& indices,
                           vector<string>& sources, vector<string>& targets) {
    vector<tuple<int, string, string>> operations;

    for (int i = 0; i < indices.size(); ++i)
      operations.emplace_back(indices[i], sources[i], targets[i]);

    ranges::sort(operations, greater<>());

    for (const auto& [index, source, target] : operations)
      if (string_view(s.data() + index, source.length()) == source)
        s = s.substr(0, index) + target + s.substr(index + source.length());

    return s;
  }
};
