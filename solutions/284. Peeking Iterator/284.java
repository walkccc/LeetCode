// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html

class PeekingIterator implements Iterator<Integer> {
  public PeekingIterator(Iterator<Integer> iterator) {
    this.iterator = iterator;
    buffer = iterator.hasNext() ? iterator.next() : null;
  }

  // Returns the next element in the iteration without advancing the iterator.
  public Integer peek() {
    return buffer;
  }

  // hasNext() and next() should behave the same as in the Iterator interface.
  // Override them if needed.
  @Override
  public Integer next() {
    Integer next = buffer;
    buffer = iterator.hasNext() ? iterator.next() : null;
    return next;
  }

  @Override
  public boolean hasNext() {
    return buffer != null;
  }

  private Iterator<Integer> iterator;
  private Integer buffer;
}
