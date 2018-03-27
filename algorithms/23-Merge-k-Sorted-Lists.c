/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct _min_heap_t {
    struct ListNode** lists;
    int size;
} min_heap_t;
void swap(struct ListNode** lists, int i, int j)
{   
    struct ListNode* ntmp = lists[i];
    lists[i] = lists[j];
    lists[j] = ntmp;
}

void min_heapify(min_heap_t *pHead, int i)
{
    if (i < 0 || i >= pHead->size)  return;
    struct ListNode** lists = pHead->lists;
    int size = pHead->size;
    int cur = i, down;
    int lc, rc;
    while (1) {
        down = cur;
        lc = 2 * cur + 1;
        rc = lc + 1;
        if (lc < size && lists[lc]->val < lists[cur]->val)   down = lc;
        if (rc < size && lists[rc]->val < lists[down]->val ) down = rc;
        if (down == cur)    break;
        swap(lists, cur, down);
        cur = down;
    }
}
void make_heap(min_heap_t *pHeap)
{
    // move empty list to the end;
    for (int j = pHeap->size - 1, end = j; j >= 0; j--) {
        if (!pHeap->lists[j]) {
            swap(pHeap->lists, j, end--);
            pHeap->size--;
        }
    }
    for (int i = pHeap->size/2 - 1; i >= 0; i--)
        min_heapify(pHeap, i);
}

struct ListNode* getMin(min_heap_t *pHeap)
{
    if (!pHeap->size)    return NULL;
    struct ListNode* minNode = pHeap->lists[0];
    pHeap->lists[0] = minNode->next;
    
    if (!minNode->next)
        swap(pHeap->lists, 0, --pHeap->size);
    min_heapify(pHeap, 0);
    return minNode;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    min_heap_t minHeap;
    minHeap.lists = lists;
    minHeap.size = listsSize;
    make_heap(&minHeap);
    struct ListNode dummy;
    struct ListNode* cur = &dummy;
    while ((cur->next = getMin(&minHeap)))
        cur = cur->next;
    return dummy.next;
}
