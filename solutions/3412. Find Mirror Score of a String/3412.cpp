class Solution {
 public:
  long long calculateScore(string s) {
    long ans = 0;
    vector<stack<int>> indices(26);

    for (int i = 0; i < s.length(); ++i) {
      const int index = s[i] - 'a';
      const int oppositeIndex = 25 - index;
      if (!indices[oppositeIndex].empty())
        ans += i - indices[oppositeIndex].top(), indices[oppositeIndex].pop();
      else
        indices[index].push(i);
    }

    return ans;
  }
};
