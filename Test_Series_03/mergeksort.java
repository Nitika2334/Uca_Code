package Test_Series_03;

import java.util.PriorityQueue;

class ListNode{
    int data;
    ListNode next;

    ListNode(){}
    ListNode(int data){
        this.data=data;
        next=null;
    }
}

public class mergeksort {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }

        PriorityQueue<ListNode> minHeap = new PriorityQueue<>((a, b) -> a.val - b.val);

        // Add the heads of all linked lists to the min heap
        for (ListNode list : lists) {
            if (list != null) {
                minHeap.offer(list);
            }
        }

        ListNode dummy = new ListNode(0);
        ListNode current = dummy;

        while (!minHeap.isEmpty()) {
            // Poll the smallest element from the min heap
            ListNode smallest = minHeap.poll();
            current.next = smallest;
            current = current.next;

            // Move to the next node in the linked list
            if (smallest.next != null) {
                minHeap.offer(smallest.next);
            }
        }

        return dummy.next;
    
    }
}
