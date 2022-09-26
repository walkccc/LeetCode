class Solution {
 public:
  bool isRationalEqual(string S, string T) {
    return abs(valueOf(S) - valueOf(T)) < 1e-9;
  }

 private:
  vector<double> ratios{1.0, 1.0 / 9, 1.0 / 99, 1.0 / 999, 1.0 / 9999};

  double valueOf(const string& s) {
    if (s.find('(') == string::npos)
      return stod(s);

    double integer_nonRepeating = stod(s.substr(0, s.find_first_of('(')));
    int nonRepeatingLength = s.find_first_of('(') - s.find_first_of('.') - 1;
    int repeating =
        stoi(s.substr(s.find_first_of('(') + 1, s.find_first_of(')')));
    int repeatingLength = s.find_first_of(')') - s.find_first_of('(') - 1;

    return integer_nonRepeating +
           repeating * pow(0.1, nonRepeatingLength) * ratios[repeatingLength];
  }
};
