class Solution {
 public:
  double trimMean(vector<int>& arr) {
    int offset = arr.size() / 20;
    nth_element(arr.begin(), arr.begin() + offset, arr.end());
    nth_element(arr.begin() + offset, arr.end() - offset, arr.end());
    double sum = accumulate(arr.begin() + offset, arr.end() - offset, 0.0);
    return sum / (arr.size() - offset * 2);
  }
};
