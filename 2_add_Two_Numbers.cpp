// 链表的每一位相加，并向下传递 进位 信息
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return sub_add(l1, l2, false);
    }

private:
    ListNode* sub_add(ListNode *l1, ListNode *l2, bool add) {
        if (l1 == nullptr && l2 == nullptr && add == false) {
            return nullptr;
        }

        int val_1 = l1 == nullptr ? 0 : l1->val;
        int val_2 = l2 == nullptr ? 0 : l2->val;
        int sum = val_1 + val_2 + (add == true ? 1 : 0);
        ListNode *curr = new ListNode(sum % 10);
        curr->next = sub_add(l1 == nullptr ? nullptr : l1->next, l2 == nullptr ? nullptr : l2->next, (sum / 10) == 0 ? false : true);

        return curr;
    }
};

// 能够排除最前面是 0 的干扰
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *answer = sub_add(l1, l2, false);
        if (answer == nullptr) {
            answer = new ListNode(0);
        }
        return answer;
    }

private:
    ListNode* sub_add(ListNode *l1, ListNode *l2, bool add) {
        if (l1 == nullptr && l2 == nullptr && add == false) {
            return nullptr;
        }

        int val_1 = l1 == nullptr ? 0 : l1->val;
        int val_2 = l2 == nullptr ? 0 : l2->val;
        int sum = val_1 + val_2 + (add == true ? 1 : 0);
        ListNode *curr = new ListNode(sum % 10);
        curr->next = sub_add(l1 == nullptr ? nullptr : l1->next, l2 == nullptr ? nullptr : l2->next, (sum / 10) == 0 ? false : true);

		if (curr->next == nullptr && curr->val == 0) {
			delete curr;
			curr = nullptr;
		}
		
        return curr;
    }
};