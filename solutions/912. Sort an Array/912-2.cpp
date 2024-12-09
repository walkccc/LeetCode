class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    heapSort(nums);
    return nums;
  }

 private:
  void heapSort(vector<int>& A) {
    buildMaxHeap(A);
    int heapSize = A.size();
    for (int i = A.size() - 1; i > 0; --i) {
      swap(A[i], A[0]);
      --heapSize;
      maxHeapify(A, 0, heapSize);
    }
  }

  void buildMaxHeap(vector<int>& A) {
    for (int i = A.size() / 2; i >= 0; --i)
      maxHeapify(A, i, A.size());
  }

  void maxHeapify(vector<int>& A, int i, int heapSize) {
    const int l = 2 * i + 1;
    const int r = 2 * i + 2;
    int largest = i;
    if (l < heapSize && A[largest] < A[l])
      largest = l;
    if (r < heapSize && A[largest] < A[r])
      largest = r;
    if (largest != i) {
      swap(A[largest], A[i]);
      maxHeapify(A, largest, heapSize);
    }
  }
};
