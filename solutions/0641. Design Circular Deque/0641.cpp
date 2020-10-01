class MyCircularDeque {
 public:
  MyCircularDeque(int k) : k(k), q(k, 0), rear(k - 1) {}

  bool insertFront(int value) {
    if (isFull()) return false;

    front = (--front + k) % k;
    q[front] = value;
    ++length;
    return true;
  }

  bool insertLast(int value) {
    if (isFull()) return false;

    rear = ++rear % k;
    q[rear] = value;
    ++length;
    return true;
  }

  bool deleteFront() {
    if (isEmpty()) return false;

    front = ++front % k;
    --length;
    return true;
  }

  bool deleteLast() {
    if (isEmpty()) return false;

    rear = (--rear + k) % k;
    --length;
    return true;
  }

  int getFront() {
    return isEmpty() ? -1 : q[front];
  }

  int getRear() {
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