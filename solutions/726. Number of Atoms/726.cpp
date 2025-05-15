class Solution {
 public:
  string countOfAtoms(string formula) {
    string ans;
    int i = 0;

    for (const auto& [elem, freq] : parse(formula, i)) {
      ans += elem;
      if (freq > 1)
        ans += to_string(freq);
    }

    return ans;
  }

 private:
  map<string, int> parse(const string& s, int& i) {
    map<string, int> count;

    while (i < s.length())
      if (s[i] == '(') {
        for (const auto& [elem, freq] : parse(s, ++i))
          count[elem] += freq;
      } else if (s[i] == ')') {
        const int num = getNum(s, ++i);
        for (auto&& [_, freq] : count)
          freq *= num;
        return count;  // Return back to the previous scope.
      } else {         // `s[i]` must be uppercased.
        const string& elem = getElem(s, i);
        const int num = getNum(s, i);
        count[elem] += num;
      }

    return count;
  }

  string getElem(const string& s, int& i) {
    const int elemStart = i++;  // `s[elemStart]` is uppercased.
    while (i < s.length() && islower(s[i]))
      ++i;
    return s.substr(elemStart, i - elemStart);
  }

  int getNum(const string& s, int& i) {
    const int numStart = i;
    while (i < s.length() && isdigit(s[i]))
      ++i;
    const string& numString = s.substr(numStart, i - numStart);
    return numString.empty() ? 1 : stoi(numString);
  }
};
