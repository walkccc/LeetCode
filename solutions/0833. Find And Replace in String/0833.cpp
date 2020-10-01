class Solution {
 public:
  string findReplaceString(string S, vector<int>& indexes,
                           vector<string>& sources, vector<string>& targets) {
    vector<pair<int, int>> sortedIndexes;

    for (int i = 0; i < indexes.size(); ++i)
      sortedIndexes.push_back({indexes[i], i});

    sort(rbegin(sortedIndexes), rend(sortedIndexes));

    for (const auto& [index, i] : sortedIndexes) {
      string source = sources[i];
      string target = targets[i];
      if (S.substr(index, source.length()) == source)
        S = S.substr(0, index) + target + S.substr(index + source.length());
    }

    return S;
  }
};