class Solution {
 public:
  bool canConvert(string str1, string str2) {
    if (str1 == str2)
      return true;

    vector<int> mappings(128);

    for (int i = 0; i < str1.length(); ++i) {
      const int a = str1[i];
      const int b = str2[i];
      if (mappings[a] != 0 && mappings[a] != b)
        return false;
      mappings[a] = b;
    }

    // No letter in the str1 maps to > 1 letter in the str2 and there is at
    // lest one temporary letter can break any loops.
    return unordered_set<char>(str2.begin(), str2.end()).size() < 26;
  }
};
