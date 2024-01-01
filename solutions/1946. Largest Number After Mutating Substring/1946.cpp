class Solution {
 public:
  string maximumNumber(string num, vector<int>& change) {
    bool mutated = false;

    for (char& c : num) {
      const int d = c - '0';
      c = '0' + max(d, change[d]);
      if (mutated && d > change[d])
        return num;
      if (d < change[d])
        mutated = true;
    }

    return num;
  }
};
