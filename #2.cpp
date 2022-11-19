//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode *next) : val(x), next(next) {}
//};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode* ret=new ListNode();
		ListNode* pos=ret;
		
		bool up=false;
		while(l1!=nullptr || l2!=nullptr)
		{
			int take=0;
			if(l1!=nullptr)take+=l1->val, l1=l1->next;
			if(l2!=nullptr)take+=l2->val, l2=l2->next;
			if(up)take++,up=false;
			if(take>9)take-=10,up=true;
			pos->next=new ListNode(take);
			pos=pos->next;
		}
		if(up)pos->next=new ListNode(1);
		return ret->next;
    }
};
