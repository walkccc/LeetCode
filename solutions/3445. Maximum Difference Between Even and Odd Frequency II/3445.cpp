class Solution {
 public:
  int maxDifference(string s, int k) {
    int ans = INT_MIN;

    for (const auto& [a, b] : getPermutations()) {
      // minDiff[parityA][parityB] := min(a - b) of all valid windows with
      // parityA and parityB
      vector<vector<int>> minDiff(2, vector<int>(2, INT_MAX / 2));
      vector<int> prefixA{0};  // prefixA[i] := the number of 'a's in s[0..i)
      vector<int> prefixB{0};  // prefixB[i] := the number of 'b's in s[0..i)
      for (int l = 0, r = 0; r < s.length(); ++r) {
        prefixA.push_back(prefixA.back() + (s[r] == a ? 1 : 0));
        prefixB.push_back(prefixB.back() + (s[r] == b ? 1 : 0));
        while (r - l + 1 >= k &&               // the window size >= k
               prefixA[l] < prefixA.back() &&  // the number of 'a's > 0
               prefixB[l] < prefixB.back()) {  // the number of 'b's > 0
          minDiff[prefixA[l] % 2][prefixB[l] % 2] = min(
              minDiff[prefixA[l] % 2][prefixB[l] % 2], prefixA[l] - prefixB[l]);
          ++l;
        }
        ans = max(ans, (prefixA.back() - prefixB.back()) -
                           minDiff[1 - prefixA.back() % 2][prefixB.back() % 2]);
      }
    }

    return ans;
  }

 private:
  vector<pair<char, char>> getPermutations() {
    vector<pair<char, char>> permutations;
    for (const char a : "01234")
      for (const char b : "01234")
        if (a != b)
          permutations.emplace_back(a, b);
    return permutations;
  }
};
