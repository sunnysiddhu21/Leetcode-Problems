/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    int length(ListNode *head){
        int cnt=0;
        ListNode *temp=head;

        while(temp!=NULL){
            temp=temp->next;
            cnt++;
        }
        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
        if(a==NULL){
            return NULL;
        }
        if(b==NULL){
            return NULL;
        }

        int l1=length(a);
        int l2=length(b);
        int d=0;

        ListNode *ptr1;
        ListNode *ptr2;

        if(l1>l2){
            d=l1-l2;
            ptr1=a;
            ptr2=b;
        }
        else{
            d=l2-l1;
            ptr1=b;
            ptr2=a;
        }

        while(d){
            ptr1=ptr1->next;
            if(ptr1==NULL){
                return NULL;
            }

            d--;
        }

        while(ptr1!=NULL && ptr2!=NULL){
            if(ptr1==ptr2){
                return ptr1;
            }

            ptr1=ptr1->next;
            ptr2=ptr2->next;

        }

        return NULL;

    
    }
};