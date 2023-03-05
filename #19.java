/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode tp=new ListNode();
        tp.next=head;
        find(tp, n);
        return tp.next;
    }
    public int find(ListNode node, int tar) {
        if(node==null)return 0;
        int has=find(node.next, tar);
        if(has==tar)node.next=node.next.next;
        return has+1;
    }
}