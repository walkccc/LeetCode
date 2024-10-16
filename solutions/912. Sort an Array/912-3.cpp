class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    quickSort(nums, 0, nums.size() - 1);
    return nums;
  }

 private:
  void quickSort(vector<int>& A, int l, int r) {
    if (l >= r)
      return;

    const int m = partition(A, l, r);
    quickSort(A, l, m - 1);
    quickSort(A, m + 1, r);
  }

  int partition(vector<int>& A, int l, int r) {
    const int randIndex = rand() % (r - l + 1) + l;
    swap(A[randIndex], A[r]);
    const int pivot = A[r];
    int nextSwapped = l;
    for (int i = l; i < r; ++i)
      if (A[i] <= pivot)
        swap(A[nextSwapped++], A[i]);
    swap(A[nextSwapped], A[r]);
    return nextSwapped;
  }
};
