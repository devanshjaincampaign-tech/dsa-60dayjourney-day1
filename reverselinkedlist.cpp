/*Let's imagine the linked list is a game of **Follow the Leader** at recess.

Right now, three friends are standing in a line, holding hands like this:

$$1 \rightarrow 2 \rightarrow 3 \rightarrow \text{Finish Line}$$

* **Kid 1** is holding **Kid 2**'s hand.
* **Kid 2** is holding **Kid 3**'s hand.
* **Kid 3** is holding onto the **Finish Line** (which is empty space, or nullptr).

Our goal is to make them turn around and hold hands backwards, so it looks like this:

$$\text{Finish Line} \leftarrow 1 \leftarrow 2 \leftarrow 3$$

To do this without anyone getting lost or left behind, we use three jobs:

1. prev: The kid *behind* us (starts as nobody, or nullptr).
2. curr: The kid we are looking at *right now* (starts at Kid 1).
3. next_node: The kid *ahead* of us, who we hold onto so they don't run away.

---

## The Dry Run: Step-by-Step

Let's watch exactly what happens inside the loop, step-by-step!

### Start Setup

* prev = Nobody (nullptr)
* curr = Kid 1

---

### Round 1: Looking at Kid 1

> **The Goal:** Make Kid 1 turn around.

1. **Save the next kid:** Kid 1 looks ahead and taps Kid 2 on the shoulder.
next_node = Kid 2. *(We won't lose Kid 2 now!)*
2. **Turn the hand around:** Kid 1 lets go of Kid 2 and reaches backward to hold prev's hand (which is Nobody).
curr->next = Nobody.
3. **Move the labels forward:**
* Kid 1 is now the "kid behind" (prev = Kid 1).
* We step forward to look at Kid 2 (curr = Kid 2).



**What the line looks like now:**

Nobody <- 1 ... and 2 -> 3 -> Finish Line are waiting.

---

### Round 2: Looking at Kid 2

> **The Goal:** Make Kid 2 turn around.

1. **Save the next kid:** Kid 2 looks ahead and taps Kid 3 on the shoulder.
next_node = Kid 3.
2. **Turn the hand around:** Kid 2 lets go of Kid 3 and reaches backward to hold Kid 1's hand (prev).
curr->next = Kid 1.
3. **Move the labels forward:**
* Kid 2 becomes the new "kid behind" (prev = Kid 2).
* We step forward to look at Kid 3 (curr = Kid 3).



**What the line looks like now:**

Nobody <- 1 <- 2 ... and 3 -> Finish Line is waiting.

---

### Round 3: Looking at Kid 3

> **The Goal:** Make Kid 3 turn around.

1. **Save the next kid:** Kid 3 looks ahead and sees the Finish Line.
next_node = Finish Line (nullptr).
2. **Turn the hand around:** Kid 3 lets go of the Finish Line and reaches backward to hold Kid 2's hand (prev).
curr->next = Kid 2.
3. **Move the labels forward:**
* Kid 3 becomes the final "kid behind" (prev = Kid 3).
* We step forward into the Finish Line (curr = nullptr).



**What the line looks like now:**

Nobody <- 1 <- 2 <- 3

---

### Game Over!

The loop stops because curr is now at the Finish Line (nullptr).

We look at who prev is pointing to—it's **Kid 3**! Kid 3 is now the brand-new leader at the front of the reversed line, so we return prev.*/

#include <iostream>

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};

class solution{
    public:
    ListNode* reverseList(ListNode* head){
        ListNode*prev= nullptr;
        ListNode*current=head;
        ListNode*next_node=nullptr;

        while(current!=nullptr){
            next_node=current->next;
            current->next=prev;

            prev=current;
            current=next_node;
        }
        return prev;
    }
};