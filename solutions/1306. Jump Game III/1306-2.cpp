class Solution {
 public:
  bool canReach(vector<int>& arr, int start) {
    return canReach(arr, start, vector<bool>(arr.size()));
  }

 private:
  bool canReach(const vector<int>& arr, int node, vector<bool>&& seen) {
    if (node < 0 || node >= arr.size())
      return false;
    if (seen[node])
      return false;
    if (arr[node] == 0)
      return true;
    seen[node] = true;
    return canReach(arr, node + arr[node], std::move(seen)) ||
           canReach(arr, node - arr[node], std::move(seen));
  }
};
