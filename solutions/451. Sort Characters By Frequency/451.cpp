class Solution {
 public:
  string frequencySort(string s) {
    const int n = s.length();
    string ans;
    vector<int> count(128);
    // buckets[i] := characters that appear i times in s
    vector<vector<char>> buckets(n + 1);

    for (const char c : s)
      ++count[c];

    for (int i = 0; i < 128; ++i) {
      const int freq = count[i];
      if (freq > 0)
        buckets[freq].push_back((char)i);
    }

    for (int freq = n; freq > 0; --freq)
      for (const char c : buckets[freq])
        ans += string(freq, c);

    return ans;
  }
};
