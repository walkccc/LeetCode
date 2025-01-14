class Solution {
 public:
  bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2,
                           vector<vector<string>>& similarPairs) {
    if (sentence1.size() != sentence2.size())
      return false;

    // map[key] := all the similar words of key
    unordered_map<string, unordered_set<string>> map;

    for (const vector<string>& pair : similarPairs) {
      map[pair[1]].insert(pair[0]);
      map[pair[0]].insert(pair[1]);
    }

    for (int i = 0; i < sentence1.size(); ++i) {
      if (sentence1[i] == sentence2[i])
        continue;
      if (!map.contains(sentence1[i]))
        return false;
      if (!map[sentence1[i]].contains(sentence2[i]))
        return false;
    }

    return true;
  }
};
