class Solution {
 public:
  string getEncryptedString(string s, int k) {
    k %= s.length();
    return s.substr(k) + s.substr(0, k);
  }
};
