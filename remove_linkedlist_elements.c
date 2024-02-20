/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
        if(head==NULL) return head;
		// This is for the case when a linked list is like this: 
		// 1->1->2->null , val = 1
		// 1->1->1->null , val = 1
        while(head!=NULL && head->val==val){
            head = head->next;
        }
        struct ListNode* curr = head;
        while(curr!=NULL  && curr->next!=NULL){
            if(curr->next->val==val){
                curr->next = curr->next->next;
				// After doing the above step, I am not updating "curr" because of these type of test cases:
				// 1->2->3->6->6->6->5->null  val = 6
            }
            else
                curr = curr->next;
        }
        return head;
    }
