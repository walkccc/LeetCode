class Solution {
 public:
  int maxConsecutiveAnswers(string answerKey, int k) {
    int ans = 0;
    int maxCount = 0;
    vector<int> count(2);

    for (int l = 0, r = 0; r < answerKey.length(); ++r) {
      maxCount = max(maxCount, ++count[answerKey[r] == 'T']);
      while (maxCount + k < r - l + 1)
        --count[answerKey[l++] == 'T'];
      ans = max(ans, r - l + 1);
    }

    return ans;
  }
};
