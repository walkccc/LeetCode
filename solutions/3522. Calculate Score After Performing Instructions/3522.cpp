class Solution {
 public:
  long long calculateScore(vector<string>& instructions, vector<int>& values) {
    const int n = instructions.size();
    long ans = 0;
    int i = 0;
    vector<bool> seen(n);

    while (i >= 0 && i < n && !seen[i]) {
      seen[i] = true;
      if (instructions[i] == "add") {
        ans += values[i];
        ++i;
      } else if (instructions[i] == "jump") {
        i += values[i];
      }
    }

    return ans;
  }
};
