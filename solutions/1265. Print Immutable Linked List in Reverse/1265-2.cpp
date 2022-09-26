/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 *  public:
 *   void printValue(); // print the value of the node.
 *   ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
 public:
  void printLinkedListInReverse(ImmutableListNode* head) {
    stack<ImmutableListNode*> stack;

    while (head) {
      stack.push(head);
      head = head->getNext();
    }

    while (!stack.empty())
      stack.top()->printValue(), stack.pop();
  }
};
