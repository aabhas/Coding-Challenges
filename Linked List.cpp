class LinkedListNode {
  public:
    LinkedListNode *next;
    int visited;
};


LinkedListNode *nodeA = new LinkedListNode();
LinkedListNode *nodeB = new LinkedListNode();
LinkedListNode *nodeC = new LinkedListNode();
LinkedListNode *nodeD = new LinkedListNode();


nodeA->next = nodeB;
nodeA->visited = 0;
nodeB->next = nodeC;
nodeB->visited = 0;
nodeC->next = nodeD;
nodeC->visited = 0;
nodeD->next = nodeB;
nodeD->visited = 0;

Normal:
nodeA --> nodeB --> nodeC --> nodeD --> null


nodeA --> nodeB --> nodeC --> nodeD --\
            ^-------------------------/ 


abstract class Set {
  public:
    void add(void *);
    bool contains(void *);   // O(1) true if pointer was previously added, false otherwise
};


bool hasCycle(LinkedListNode *node) {
  // Returns:
  // true if there is a cycle
  // false if there is no cycle
      LinkedListNode *curr = node;
      while(curr->next != NULL)
      {
          if(curr->visited == 0) curr->visited = 1;
          else
          {
              cout << "loop exists";
              return 1;
          }
      }
      cout << "No loop" <<endl;
      return 0;
}


bool hasCycle2(LinkedListNode *node) {
  // Returns:
  // true if there is a cycle
  // false if there is no cycle
    LinkedListNode *curr = node;
    LinkedListNode *curr_fast = node;
      while(curr_fast->next != NULL)
      {
          if(curr == curr_fast)
          {
           cout << "loop exists";
           return 1;
          }
          curr = curr->next;
          curr_fast = curr_fast->next;
          if(curr_fast->next != NULL) curr_fast = curr_fast->next;
      }
      cout << "No loop" <<endl;
      return 0;
