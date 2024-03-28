class MyCircularDeque {
  /** Initialize your data structure here. Set the size of the deque to be k. */
  public MyCircularDeque(int k) {
    this.k = k;
    this.q = new int[k];
    this.rear = k - 1;
  }

  /** Adds an item at the front of Deque. Return true if the operation is successful. */
  public boolean insertFront(int value) {
    if (isFull())
      return false;

    front = (--front + k) % k;
    q[front] = value;
    ++size;
    return true;
  }

  /** Adds an item at the rear of Deque. Return true if the operation is successful. */
  public boolean insertLast(int value) {
    if (isFull())
      return false;

    rear = ++rear % k;
    q[rear] = value;
    ++size;
    return true;
  }

  /** Deletes an item from the front of Deque. Return true if the operation is successful. */
  public boolean deleteFront() {
    if (isEmpty())
      return false;

    front = ++front % k;
    --size;
    return true;
  }

  /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
  public boolean deleteLast() {
    if (isEmpty())
      return false;

    rear = (--rear + k) % k;
    --size;
    return true;
  }

  /** Get the front item from the deque. */
  public int getFront() {
    return isEmpty() ? -1 : q[front];
  }

  /** Get the last item from the deque. */
  public int getRear() {
    return isEmpty() ? -1 : q[rear];
  }

  /** Checks whether the circular deque is empty or not. */
  public boolean isEmpty() {
    return size == 0;
  }

  /** Checks whether the circular deque is full or not. */
  public boolean isFull() {
    return size == k;
  }

  private final int k;
  private int[] q;
  private int size = 0;
  private int front = 0;
  private int rear;
}
