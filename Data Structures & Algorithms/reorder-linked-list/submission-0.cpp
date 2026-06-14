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
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL) return;
        ListNode* slow=head;
        ListNode* fast=head;
        //1->2->3->4->5
        //1->2<-3->4
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        //now reverse from slow
        ListNode* second=slow->next;
        slow->next=NULL;
        ListNode* temp=second;
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode* nei=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nei;
        }
        second->next=NULL;
        second=prev;
        //now first head and second hand 
        //1->2->3
        //5->4
        ListNode* front=head;
        while(second!=NULL){
            ListNode* h1=front->next;
            ListNode* h2=second;
            second=second->next;
            front->next=h2;
            h2->next=h1;
            front=h1;
        }
    }
};
