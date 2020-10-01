class Solution {
 public:
  string complexNumberMultiply(string a, string b) {
    auto getRealAndImag = [](const string& s) -> pair<int, int> {
      const string real = s.substr(0, s.find_first_of('+'));
      const string imag = s.substr(s.find_first_of('+') + 1);
      return {stoi(real), stoi(imag)};
    };

    const auto& [A, B] = getRealAndImag(a);
    const auto& [C, D] = getRealAndImag(b);

    return to_string(A * C - B * D) + "+" + to_string(A * D + B * C) + "i";
  }
};