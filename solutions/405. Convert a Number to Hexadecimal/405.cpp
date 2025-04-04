class Solution {
 public:
  string toHex(unsigned num) {
    if (num == 0)
      return "0";

    constexpr char hex[] = {'0', '1', '2', '3', '4', '5', '6', '7',
                            '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    string ans;

    while (num != 0) {
      ans += hex[num & 0xf];
      num >>= 4;
    }

    ranges::reverse(ans);
    return ans;
  }
};
