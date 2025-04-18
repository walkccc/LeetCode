class SeatManager {
 public:
  SeatManager(int n) {}

  int reserve() {
    if (minHeap.empty())
      return ++num;

    const int minNum = minHeap.top();
    minHeap.pop();
    return minNum;
  }

  void unreserve(int seatNumber) {
    minHeap.push(seatNumber);
  }

 private:
  priority_queue<int, vector<int>, greater<>> minHeap;
  int num = 0;
};
