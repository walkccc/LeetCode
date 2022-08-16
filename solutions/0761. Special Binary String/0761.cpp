class Solution {
 public:
  string makeLargestSpecial(string S) {
    vector<string> specials;
    int count = 0;

    for (int i = 0, j = 0; j < S.length(); ++j) {
      count += S[j] == '1' ? 1 : -1;
      if (count == 0) {  // find a special string
        const string& inner = S.substr(i + 1, j - i - 1);
        specials.push_back('1' + makeLargestSpecial(inner) + '0');
        i = j + 1;
      }
    }

    sort(begin(specials), end(specials), greater<>());
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
