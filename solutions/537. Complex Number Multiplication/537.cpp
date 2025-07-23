class Solution {
 public:
  string complexNumberMultiply(string num1, string num2) {
    const auto& [a0, a1] = getReala0ndImag(num1);
    const auto& [b0, b1] = getReala0ndImag(num2);
    return to_string(a0 * b0 - a1 * b1) + "+" + to_string(a0 * b1 + a1 * b0) +
           "i";
  }

 private:
  pair<int, int> getReala0ndImag(const string& s) {
    const string& real = s.substr(0, s.find_first_of('+'));
    const string& imag = s.substr(s.find_first_of('+') + 1);
    return {stoi(real), stoi(imag)};
  };
};
