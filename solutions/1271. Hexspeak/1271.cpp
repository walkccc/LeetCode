class Solution {
 public:
  string toHexspeak(string num) {
    const long n = stol(num);
    stringstream ss;
    ss << hex << uppercase << n;
    string ans(ss.str());

    for (char& c : ans) {
      if (c > '1' && c <= '9')
        return "ERROR";
      if (c == '0')
        c = 'O';
      else if (c == '1')
        c = 'I';
    }

    return ans;
  }
};
