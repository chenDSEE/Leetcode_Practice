/* 长短相加，双指针最终长度一致 */
/**
 * AAAAAA
 * BBB
 * 
 * AAAAAA + BBB = AAAAAABBB
 * BBB + AAAAAA = BBBAAAAAA
 * 这时候，你用两个指针遍历就好
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }

        ListNode *check_a = headA, *check_b = headB;
        while (check_a != check_b) {
            check_a = check_a == nullptr ? headB : check_a->next;
            check_b = check_b == nullptr ? headA : check_b->next;
        }

        return check_a;
    }
};

/* Hash */
// 时间上其实很不可控
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }

        unordered_set<ListNode *> record;
        while (headA != nullptr) {
            record.insert(headA);
            headA = headA->next;
        }

        while (headB != nullptr) {
            if (record.count(headB) == 1) {
                return headB;
            }
            headB = headB->next;
        }

        return nullptr;
    }
};