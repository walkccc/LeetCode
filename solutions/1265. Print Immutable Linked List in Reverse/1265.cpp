/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 *  public:
 *   void printValue(); // Print the value of the node.
 *   ImmutableListNode* getNext(); // Returns the next node.
 * };
 */

class Solution {
 public:
  void printLinkedListInReverse(ImmutableListNode* head) {
    if (head == nullptr)
      return;

    printLinkedListInReverse(head->getNext());
    head->printValue();
  }
};
