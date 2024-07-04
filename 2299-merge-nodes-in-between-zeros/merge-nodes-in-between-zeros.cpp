/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    #define ll long long
    ListNode* mergeNodes(ListNode* head) {
        ListNode* lastZero = head;
        ListNode* temp = head->next;

        ll sum=0;
        while(temp != NULL){
            if(temp->val == 0){
                temp->val = sum;
                lastZero->next = temp;
                sum=0;
                lastZero = temp;
            }
            else{
                sum+=temp->val;
            }
            temp=temp->next;
        }
        return head->next;
    }
};