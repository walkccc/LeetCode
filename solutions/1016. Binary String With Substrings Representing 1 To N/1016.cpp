class Solution {
 public:
  bool queryString(string s, int n) {
    if (n > 1511)
      return false;

    for (int i = n; i > n / 2; --i) {
      string binary = bitset<32>(i).to_string();
      binary = binary.substr(binary.find("1"));
      if (s.find(binary) == string::npos)
        return false;
    }

    return true;
  }
};
