class Solution {
 public:
  bool isRationalEqual(string s, string t) {
    return abs(valueOf(s) - valueOf(t)) < 1e-9;
  }

 private:
  const vector<double> ratios{1.0, 1.0 / 9, 1.0 / 99, 1.0 / 999, 1.0 / 9999};

  double valueOf(const string& s) {
    if (s.find('(') == string::npos)
      return stod(s);

    // Get the indices..
    const int leftParenIndex = s.find_first_of('(');
    const int rightParenIndex = s.find_first_of(')');
    const int dotIndex = s.find_first_of('.');

    // integerAndNonRepeating := <IntegerPart><.><NonRepeatingPart>
    const double integerAndNonRepeating = stod(s.substr(0, leftParenIndex));
    const int nonRepeatingLength = leftParenIndex - dotIndex - 1;

    // repeating := <RepeatingPart>
    const int repeating = stoi(s.substr(leftParenIndex + 1, rightParenIndex));
    const int repeatingLength = rightParenIndex - leftParenIndex - 1;
    return integerAndNonRepeating +
           repeating * pow(0.1, nonRepeatingLength) * ratios[repeatingLength];
  }
};
