class Solution {
 public:
  string orderlyQueue(string S, int K) {
    if (K > 1) {
      sort(begin(S), end(S));
      return S;
    }

    string ans = S;

    for (int i = 1; i < S.length(); ++i)
      ans = min(ans, S.substr(i) + S.substr(0, i));

    return ans;
  }
};
