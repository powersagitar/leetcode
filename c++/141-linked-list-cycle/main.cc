namespace {
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (!head) {
      return false;
    }

    const ListNode *fast = head;
    const ListNode *slow = head;

    do {
      if (fast->next == nullptr || fast->next->next == nullptr) {
        return false;
      }

      fast = fast->next->next;
      slow = slow->next;
    } while (fast != slow);

    return true;
  }
};
} // namespace
