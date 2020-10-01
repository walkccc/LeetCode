class MyCircularQueue {
 public:
  MyCircularQueue(int k) : k(k), q(k, 0), rear(k - 1) {}

  bool enQueue(int value) {
    if (isFull()) return false;

    rear = ++rear % k;
    q[rear] = value;
    ++length;
    return true;
  }

  bool deQueue() {
    if (isEmpty()) return false;

    front = ++front % k;
    --length;
    return true;
  }

  int Front() {
    return isEmpty() ? -1 : q[front];
  }

  int Rear() {
    return isEmpty() ? -1 : q[rear];
  }

  bool isEmpty() {
    return length == 0;
  }

  bool isFull() {
    return length == k;
  }

 private:
  const int k;
  vector<int> q;
  int front = 0;
  int rear;
  int length = 0;
};