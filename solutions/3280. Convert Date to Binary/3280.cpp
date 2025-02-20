class Solution {
 public:
  string convertDateToBinary(string date) {
    const int year = stoi(date.substr(0, 4));
    const int month = stoi(date.substr(5, 2));
    const int day = stoi(date.substr(8, 2));
    return toBinary(year) + '-' + toBinary(month) + '-' + toBinary(day);
  }

 private:
  // Converts an integer to binary without leading zeros.
  string toBinary(int value) {
    const string binary = bitset<16>(value).to_string();
    return binary.substr(binary.find('1'));  // Remove leading zeros.
  }
};
