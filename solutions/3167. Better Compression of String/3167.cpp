class Solution {
 public:
  string betterCompression(string compressed) {
    string ans;
    vector<int> count(26);

    for (int i = 0; i < compressed.length();) {
      const char c = compressed[i++];
      int freq = 0;
      while (i < compressed.length() && isdigit(compressed[i]))
        freq = freq * 10 + (compressed[i++] - '0');
      count[c - 'a'] += freq;
    }

    for (char c = 'a'; c <= 'z'; ++c)
      if (count[c - 'a'] > 0)
        ans += c + to_string(count[c - 'a']);

    return ans;
  }
};
