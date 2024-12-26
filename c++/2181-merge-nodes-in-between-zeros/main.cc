struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeNodes(ListNode *head) {
    ListNode *ans_head = new ListNode();
    ListNode *ans_tail = ans_head;

    for (const ListNode *node = head; node != nullptr; node = node->next) {
      if (!node->next) {
        break;
      }

      if (node->val == 0) {
        ans_tail->next = new ListNode(0);
        ans_tail = ans_tail->next;
        continue;
      }

      ans_tail->val += node->val;
    }

    ListNode *const ans_head_next = ans_head->next;

    delete ans_head;
    ans_head = nullptr;

    return ans_head_next;
  }
};
