class Solution {
 public:
  string minimizeResult(string expression) {
    const int plusIndex = expression.find('+');
    const string left = expression.substr(0, plusIndex);
    const string right = expression.substr(plusIndex + 1);
    string ans;
    int mn = INT_MAX;

    // the expression -> a * (b + c) * d
    for (int i = 0; i < left.length(); ++i)
      for (int j = 0; j < right.length(); ++j) {
        const int a = i == 0 ? 1 : stoi(left.substr(0, i));
        const int b = stoi(left.substr(i));
        const int c = stoi(right.substr(0, j + 1));
        const int d = j == right.length() - 1 ? 1 : stoi(right.substr(j + 1));
        const int val = a * (b + c) * d;
        if (val < mn) {
          mn = val;
          ans = (i == 0 ? "" : to_string(a)) + '(' + to_string(b) + '+' +
                to_string(c) + ')' +
                (j == right.length() - 1 ? "" : to_string(d));
        }
      }

    return ans;
  }
};
