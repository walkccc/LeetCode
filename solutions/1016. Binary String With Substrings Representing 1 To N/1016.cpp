class Solution {
 public:
  bool queryString(string S, int N) {
    if (N > 1511)
      return false;

    for (int i = N; i > N / 2; --i) {
      string binary = bitset<32>(i).to_string();
      binary = binary.substr(binary.find("1"));
      if (S.find(binary) == string::npos)
        return false;
    }

    return true;
  }
};
