class Solution {
 public:
  bool hasMatch(const string& s, const string& p) {
    const int starPos = p.find('*');
    const string prefix = p.substr(0, starPos);
    const string suffix = p.substr(starPos + 1);
    const int i = s.find(prefix);
    return i != string::npos &&
           s.find(suffix, i + prefix.size()) != string::npos;
  }
};
