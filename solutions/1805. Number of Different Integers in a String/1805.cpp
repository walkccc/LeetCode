class Solution {
 public:
  int numDifferentIntegers(string word) {
    unordered_set<string> nums;
    string curr;

    for (const char c : word)
      if (isdigit(c)) {
        curr += c;
      } else if (curr.length() > 0) {
        nums.insert(removeLeadingZeros(curr));
        curr = "";
      }

    if (curr.length() > 0)
      nums.insert(removeLeadingZeros(curr));
    return nums.size();
  }

 private:
  string removeLeadingZeros(const string& s) {
    const int index = s.find_first_not_of('0');
    return index == string::npos ? "0" : s.substr(index);
  }
};
