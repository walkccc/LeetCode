class MyCircularQueue {
  /** Initialize your data structure here. Set the size of the queue to be k. */
  public MyCircularQueue(int k) {
    this.k = k;
    this.q = new int[k];
    this.rear = k - 1;
  }

  /** Insert an element into the circular queue. Return true if the operation is successful. */
  public boolean enQueue(int value) {
    if (isFull())
      return false;

    rear = ++rear % k;
    q[rear] = value;
    ++size;
    return true;
  }

  /** Delete an element from the circular queue. Return true if the operation is successful. */
  public boolean deQueue() {
    if (isEmpty())
      return false;

    front = ++front % k;
    --size;
    return true;
  }

  /** Get the front item from the queue. */
  public int Front() {
    return isEmpty() ? -1 : q[front];
  }

  /** Get the last item from the queue. */
  public int Rear() {
    return isEmpty() ? -1 : q[rear];
  }

  /** Checks whether the circular queue is empty or not. */
  public boolean isEmpty() {
    return size == 0;
  }

  /** Checks whether the circular queue is full or not. */
  public boolean isFull() {
    return size == k;
  }

  private final int k;
  private int[] q;
  private int size = 0;
  private int front = 0;
  private int rear;
}
