class Solution {
 public:
  string encode(int num) {
    string binaryStr = bitset<30>(num + 1).to_string();
    binaryStr.erase(0, binaryStr.find_first_not_of('0'));
    return binaryStr.substr(1);
  }
};
