class MyCircularQueue {
 public:
  /** Initialize your data structure here. Set the size of the queue to be k. */
  MyCircularQueue(int k) : k(k), q(k), rear(k - 1) {}

  /** Insert an element into the circular queue. Return true if the operation is
   * successful. */
  bool enQueue(int value) {
    if (isFull())
      return false;

    rear = ++rear % k;
    q[rear] = value;
    ++size;
    return true;
  }

  /** Delete an element from the circular queue. Return true if the operation is
   * successful. */
  bool deQueue() {
    if (isEmpty())
      return false;

    front = ++front % k;
    --size;
    return true;
  }

  /** Get the front item from the queue. */
  int Front() {
    return isEmpty() ? -1 : q[front];
  }

  /** Get the last item from the queue. */
  int Rear() {
    return isEmpty() ? -1 : q[rear];
  }

  /** Checks whether the circular queue is empty or not. */
  bool isEmpty() {
    return size == 0;
  }

  /** Checks whether the circular queue is full or not. */
  bool isFull() {
    return size == k;
  }

 private:
  const int k;
  vector<int> q;
  int size = 0;
  int front = 0;
  int rear;
};
