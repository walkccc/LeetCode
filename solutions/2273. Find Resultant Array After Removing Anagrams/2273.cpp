class Solution {
 public:
  vector<string> removeAnagrams(vector<string>& words) {
    vector<string> ans;

    for (int i = 0; i < words.size();) {
      int j = i + 1;
      while (j < words.size() && isAnagram(words[i], words[j]))
        ++j;
      ans.push_back(words[i]);
      i = j;
    }

    return ans;
  }

 private:
  bool isAnagram(const string& a, const string& b) {
    if (a.length() != b.length())
      return false;

    vector<int> count(26);

    for (const char c : a)
      ++count[c - 'a'];

    for (const char c : b)
      --count[c - 'a'];

    return ranges::all_of(count, [](const int c) { return c == 0; });
  }
};
