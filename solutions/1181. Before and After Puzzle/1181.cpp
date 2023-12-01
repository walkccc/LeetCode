class Solution {
 public:
  vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
    set<string> ans;
    unordered_map<string, set<string>> firstWordToLasts;
    unordered_map<string, set<string>> lastWordToFirsts;

    for (const string& phrase : phrases) {
      const int firstSpaceIndex = phrase.find(' ');
      const int lastSpaceIndex = phrase.rfind(' ');
      // the index after the firstWord
      const int i =
          firstSpaceIndex == string::npos ? phrase.length() : firstSpaceIndex;
      // the index of the lastWord
      const int j = lastSpaceIndex == string::npos ? 0 : lastSpaceIndex + 1;
      const string firstWord = phrase.substr(0, i);
      const string lastWord = phrase.substr(j);

      // Concatenate `phrase` with `last` having the same `firstWord`.
      if (const auto it = firstWordToLasts.find(lastWord);
          it != firstWordToLasts.cend())
        for (const string& last : it->second)
          ans.insert(phrase + last);

      // Concatenate `first` having the same `lastWord` with `phrase`.
      if (const auto it = lastWordToFirsts.find(firstWord);
          it != lastWordToFirsts.cend())
        for (const string& first : it->second)
          ans.insert(first + phrase);

      // e.g. "a b c" -> {"a": " b c"}
      //          "a" -> {"a": ""}
      firstWordToLasts[firstWord].insert(phrase.substr(i));

      // e.g. "a b c" -> {"c": "a b "}
      //          "a" -> {"a": ""}
      lastWordToFirsts[lastWord].insert(phrase.substr(0, j));
    }

    return {ans.begin(), ans.end()};
  }
};
