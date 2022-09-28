// 19. Remove Nth Node From End of List

***********APPROACH***************
using slow and fast pointers to find the just previous node of node to be deleted

making fast =  head + n; so that it always stays n node n+1 node ahead of slow(initially NULL)

  
  // code
  public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode *slow = nullptr, *fast = head;
        for(int i = 0; i < n; i++)
        {
            if(fast == nullptr)
                break;
            fast = fast->next;
        }

        while(fast != nullptr)
        {
            if(slow == nullptr)
                slow = head;
            else
                slow = slow->next;
            fast = fast -> next;
        }
        if(slow == nullptr)
            return head->next;
        slow ->next = slow -> next -> next;
        return head;
    }
};
