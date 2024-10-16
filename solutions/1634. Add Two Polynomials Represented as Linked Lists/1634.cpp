/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *   int coefficient, power;
 *   PolyNode *next;
 *   PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *   PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *   PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y),
 *                                           next(next) {};
 * };
 */

class Solution {
 public:
  PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
    PolyNode* dummy = new PolyNode();
    PolyNode* curr = dummy;
    PolyNode* p = poly1;  // poly1's pointer
    PolyNode* q = poly2;  // poly2's pointer

    while (p != nullptr && q != nullptr) {
      if (p->power > q->power) {
        curr->next = new PolyNode(p->coefficient, p->power);
        curr = curr->next;
        p = p->next;
      } else if (p->power < q->power) {
        curr->next = new PolyNode(q->coefficient, q->power);
        curr = curr->next;
        q = q->next;
      } else {  // p->power == q->power
        const int sumCoefficient = p->coefficient + q->coefficient;
        if (sumCoefficient != 0) {
          curr->next = new PolyNode(sumCoefficient, p->power);
          curr = curr->next;
        }
        p = p->next;
        q = q->next;
      }
    }

    while (p != nullptr) {
      curr->next = new PolyNode(p->coefficient, p->power);
      curr = curr->next;
      p = p->next;
    }

    while (q != nullptr) {
      curr->next = new PolyNode(q->coefficient, q->power);
      curr = curr->next;
      q = q->next;
    }

    return dummy->next;
  }
};
