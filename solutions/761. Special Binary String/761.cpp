class Solution {
 public:
  string makeLargestSpecial(string s) {
    vector<string> specials;
    int count = 0;

    for (int i = 0, j = 0; j < s.length(); ++j) {
      count += s[j] == '1' ? 1 : -1;
      if (count == 0) {  // Find a special string.
        const string& inner = s.substr(i + 1, j - i - 1);
        specials.push_back('1' + makeLargestSpecial(inner) + '0');
        i = j + 1;
      }
    }

    ranges::sort(specials, greater<>());
    return join(specials);
  }

 private:
  string join(const vector<string>& specials) {
    string joined;
    for (const string& special : specials)
      joined += special;
    return joined;
  }
};
