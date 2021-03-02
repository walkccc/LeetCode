class PeekingIterator : public Iterator {
 public:
  PeekingIterator(const vector<int>& nums) : Iterator(nums) {}

  // Returns the next element in the iteration without advancing the iterator.
  int peek() {
    // Iterator(*this) makes a copy of current iterator, then call next on the
    // copied iterator to get the next value without affecting current iterator
    return Iterator(*this).next();
  }

  // hasNext() and next() should behave the same as in the Iterator interface.
  // Override them if needed.
  int next() {
    return Iterator::next();
  }

  bool hasNext() const {
    return Iterator::hasNext();
  }
};
