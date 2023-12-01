class BoundedBlockingQueue {
  public BoundedBlockingQueue(int capacity) {
    this.enqueueSemaphore = new Semaphore(capacity);
  }

  public void enqueue(int element) throws InterruptedException {
    enqueueSemaphore.acquire();
    q.offer(element);
    dequeueSemaphore.release();
  }

  public int dequeue() throws InterruptedException {
    dequeueSemaphore.acquire();
    final int element = q.poll();
    enqueueSemaphore.release();
    return element;
  }

  public int size() {
    return q.size();
  }

  private Queue<Integer> q = new ArrayDeque<>();
  private Semaphore enqueueSemaphore;
  private Semaphore dequeueSemaphore = new Semaphore(0);
}
