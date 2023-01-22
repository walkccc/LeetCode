class Solution {
 public:
  vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
    set<string> ans;
    unordered_map<string, set<string>> firstWordToLasts;
    unordered_map<string, set<string>> lastWordToFirsts;

    for (const string& phrase : phrases) {
      const int firstSpaceIndex = phrase.find(' ');
      const int lastSpaceIndex = phrase.rfind(' ');
      // Index after firstWord.
      const int i =
          firstSpaceIndex == string::npos ? phrase.length() : firstSpaceIndex;
      // Index of lastWord.
      const int j = lastSpaceIndex == string::npos ? 0 : lastSpaceIndex + 1;
      const string firstWord = phrase.substr(0, i);
      const string lastWord = phrase.substr(j);

      // Concatenate `phrase` w/ `last` having the same `firstWord`.
      if (firstWordToLasts.count(lastWord))
        for (const string& last : firstWordToLasts[lastWord])
          ans.insert(phrase + last);

      // Concatenate `first` having the same `lastWord` w/ `phrase`.
      if (lastWordToFirsts.count(firstWord))
        for (const string& first : lastWordToFirsts[firstWord])
          ans.insert(first + phrase);

      // e.g. "a b c" -> {"a": " b c"}
      //          "a" -> {"a": ""}
      firstWordToLasts[firstWord].insert(phrase.substr(i));

      // e.g. "a b c" -> {"c": "a b "}
      //          "a" -> {"a": ""}
      lastWordToFirsts[lastWord].insert(phrase.substr(0, j));
    }

    return {begin(ans), end(ans)};
  }
};
