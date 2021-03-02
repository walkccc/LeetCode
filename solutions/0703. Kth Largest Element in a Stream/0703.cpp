class KthLargest {
 public:
  KthLargest(int k, vector<int>& nums) : k(k) {
    for (const int num : nums)
      heapify(num);
  }

  int add(int val) {
    heapify(val);
    return pq.top();
  }

 private:
  const int k;
  priority_queue<int, vector<int>, greater<>> pq;

  void heapify(int val) {
    pq.push(val);
    if (pq.size() > k)
      pq.pop();
  }
};
