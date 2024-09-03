class Solution {
 public:
  string getSmallestString(string s, int k) {
    string ans = s;

    for (char& c : ans) {
      if (k == 0)
        break;
      const int distToA = min(c - 'a', 'z' - c + 1);
      if (k >= distToA) {
        k -= distToA;
        c = 'a';
      } else {
        // k is not enough to change the current letter to 'a', so move as
        // closer to 'a' as possible.
        c -= k;
        k = 0;
      }
    }

    return ans;
  }
};
