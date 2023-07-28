class Solution {
 public:
  int distributeCookies(vector<int>& cookies, int k) {
    int ans = INT_MAX;
    dfs(cookies, 0, k, vector<int>(k), ans);
    return ans;
  }

 private:
  void dfs(const vector<int>& cookies, int s, int k, vector<int>&& children,
           int& ans) {
    if (s == cookies.size()) {
      ans = min(ans, *max_element(children.begin(), children.end()));
      return;
    }

    for (int i = 0; i < k; ++i) {
      children[i] += cookies[s];
      dfs(cookies, s + 1, k, move(children), ans);
      children[i] -= cookies[s];
    }
  }
};
