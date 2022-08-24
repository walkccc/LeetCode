class Solution {
 public:
  int bagOfTokensScore(vector<int>& tokens, int power) {
    int ans = 0;
    int score = 0;
    int i = 0;                  // index of smallest token
    int j = tokens.size() - 1;  // index of largest token

    sort(begin(tokens), end(tokens));

    while (i <= j && (power >= tokens[i] || score)) {
      while (i <= j && power >= tokens[i]) {
        // play the smallest face up
        power -= tokens[i++];
        ++score;
      }
      ans = max(ans, score);
      if (i <= j && score) {
        // play the largest face down
        power += tokens[j--];
        --score;
      }
    }

    return ans;
  }
};
