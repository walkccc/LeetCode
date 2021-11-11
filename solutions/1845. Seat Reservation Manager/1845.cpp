class SeatManager {
 public:
  SeatManager(int n) {}

  int reserve() {
    if (pq.empty())
      return ++num;

    const int minNum = pq.top();
    pq.pop();
    return minNum;
  }

  void unreserve(int seatNumber) {
    pq.push(seatNumber);
  }

 private:
  priority_queue<int, vector<int>, greater<>> pq;
  int num = 0;
};
