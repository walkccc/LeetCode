class Solution {
 public:
  bool isAlienSorted(vector<string>& words, const string& order) {
    vector<char> map(26);  // order = "bca" -> map = ['c', 'a', 'b']

    for (int i = 0; i < 26; ++i)
      map[order[i] - 'a'] = i + 'a';

    for (string& word : words)
      for (char& c : word)
        c = map[c - 'a'];

    return is_sorted(begin(words), end(words));
  }
};
