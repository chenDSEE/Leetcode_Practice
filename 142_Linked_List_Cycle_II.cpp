/* 指针版本 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;

			// 先确保成功入环，然后再逐个扫描
            if (fast == slow) {
                ListNode *mark = fast, *curr = head, *travel = mark;
                while (travel != curr) {
                    if (travel == mark) {
                        curr = curr->next;
                    }
                    travel = travel->next;
                }

                return curr;
            }
        }

        return nullptr;   
    }
};

/* HASH Version */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> record;
        while (head != nullptr && record.count(head) == 0) {
            record.insert(head);
            head = head->next;
        }

        return head;
    }
};
