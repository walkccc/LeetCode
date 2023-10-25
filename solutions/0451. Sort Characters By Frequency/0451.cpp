class Solution {
 public:
  string frequencySort(string s) {
    const int n = s.length();
    string ans;
    vector<int> count(128);
    // bucket[i] := stores chars that appear i times in s
    vector<vector<char>> bucket(n + 1);

    for (const char c : s)
      ++count[c];

    for (int i = 0; i < 128; ++i) {
      const int freq = count[i];
      if (freq > 0)
        bucket[freq].push_back((char)i);
    }

    for (int freq = n; freq > 0; --freq)
      for (const char c : bucket[freq])
        ans += string(freq, c);

    return ans;
  }
};
