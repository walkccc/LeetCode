class Solution {
 public:
  vector<int> findBuildings(vector<int>& heights) {
    vector<int> stack;

    for (int i = 0; i < heights.size(); ++i) {
      while (!stack.empty() && heights[stack.back()] <= heights[i])
        stack.pop_back();
      stack.push_back(i);
    }

    return stack;
  }
};
