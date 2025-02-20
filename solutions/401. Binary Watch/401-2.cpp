class Solution {
 public:
  vector<string> readBinaryWatch(int turnedOn) {
    vector<string> ans;

    for (unsigned h = 0; h < 12; ++h)
      for (unsigned m = 0; m < 60; ++m)
        if (popcount(h << 6 | m) == turnedOn)
          ans.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));

    return ans;
  }
};
