class Solution {
 public:
  int minimumSum(int num) {
    string s = to_string(num);
    sort(begin(s), end(s));
    return stoi(s.substr(0, 1) + s.substr(2, 1)) +
           stoi(s.substr(1, 1) + s.substr(3, 1));
  }
};
