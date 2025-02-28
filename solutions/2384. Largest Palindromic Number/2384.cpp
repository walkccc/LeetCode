class Solution {
 public:
  string largestPalindromic(string num) {
    unordered_map<char, int> count;

    for (const char c : num)
      ++count[c];

    const string firstHalf = getFirstHalf(count);
    const string mid = getMid(count);
    const string ans = firstHalf + mid + reversed(firstHalf);
    return ans.empty() ? "0" : ans;
  }

 private:
  string getFirstHalf(const unordered_map<char, int>& count) {
    string firstHalf;
    for (char c = '9'; c >= '0'; --c) {
      const auto it = count.find(c);
      if (it == count.cend())
        continue;
      const int freq = it->second;
      firstHalf += string(freq / 2, c);
    }
    const int index = firstHalf.find_first_not_of('0');
    return index == string::npos ? "" : firstHalf.substr(index);
  }

  string getMid(const unordered_map<char, int>& count) {
    for (char c = '9'; c >= '0'; --c) {
      const auto it = count.find(c);
      if (it == count.cend())
        continue;
      const int freq = it->second;
      if (freq % 2 == 1)
        return string(1, c);
    }
    return "";
  }

  string reversed(const string& s) {
    return {s.rbegin(), s.rend()};
  }
};
