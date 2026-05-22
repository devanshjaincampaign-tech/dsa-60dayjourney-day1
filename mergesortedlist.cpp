/*Let’s go back to the playground recess!

This time, we have **two separate lines of kids** waiting to get onto the bus. Both lines are already sorted perfectly from the shortest kid to the tallest kid.

* **Line 1 (`list1`):** Kid 1 $\rightarrow$ Kid 3 $\rightarrow$ Finish Line (`nullptr`)
* **Line 2 (`list2`):** Kid 2 $\rightarrow$ Kid 4 $\rightarrow$ Finish Line (`nullptr`)

Our goal is to merge them into **one single line** that stays perfectly sorted from shortest to tallest.

To do this without getting confused about who is at the front, we bring in a friendly teacher's assistant named **Dummy**. Dummy stands at the very front of the new bus line to act as a permanent anchor. We also track the current end of our new line with a pointer called **Tail**.

---

## The Dry Run: Step-by-Step

### Start Setup

* `Dummy` is placed at the front.
* `Tail` starts right where `Dummy` is standing.

---

### Round 1: Who is shorter?

We look at the front of both lines: **Kid 1** vs **Kid 2**.

1. **The Comparison:** Kid 1 is shorter than Kid 2 ($1 \leq 2$).
2. **Make the Link:** `Tail` tells **Kid 1** to step over and hold onto the new line.
`tail->next = list1;`
3. **Move the Line Leader:** Line 1 moves forward, so **Kid 3** is now the leader of Line 1.
`list1 = list1->next;`
4. **Move the Tail:** Our new line just grew! `Tail` steps up to stand with Kid 1.
`tail = tail->next;`

**Current New Line:** `[Dummy] -> 1` *(Tail is at 1)*

---

### Round 2: Who is shorter?

We look at the leaders again: **Kid 3** (Line 1) vs **Kid 2** (Line 2).

1. **The Comparison:** Kid 2 is shorter than Kid 3 ($2 < 3$).
2. **Make the Link:** `Tail` tells **Kid 2** to step over and hold Kid 1's hand.
`tail->next = list2;`
3. **Move the Line Leader:** Line 2 moves forward, so **Kid 4** is now the leader of Line 2.
`list2 = list2->next;`
4. **Move the Tail:** `Tail` steps up to stand with Kid 2.
`tail = tail->next;`

**Current New Line:** `[Dummy] -> 1 -> 2` *(Tail is at 2)*

---

### Round 3: Who is shorter?

We look at the leaders again: **Kid 3** (Line 1) vs **Kid 4** (Line 2).

1. **The Comparison:** Kid 3 is shorter than Kid 4 ($3 \leq 4$).
2. **Make the Link:** `Tail` tells **Kid 3** to step over and hold Kid 2's hand.
`tail->next = list1;`
3. **Move the Line Leader:** Line 1 moves forward and hits the end of the line! Line 1 is now empty (`nullptr`).
`list1 = list1->next;`
4. **Move the Tail:** `Tail` steps up to stand with Kid 3.
`tail = tail->next;`

**Current New Line:** `[Dummy] -> 1 -> 2 -> 3` *(Tail is at 3)*

---

### The Fast Finish (Step 4 of Code)

The loop stops because Line 1 has run completely out of kids.

We look over at Line 2 and see **Kid 4** still standing there. Because Line 2 was already perfectly sorted, we don't need to do any more math!

`Tail` (standing at Kid 3) simply reaches out and holds **Kid 4**'s hand. Because Kid 4 was already holding onto the Finish Line, the entire rest of the chain snaps into place instantly:

`tail->next = list2;`

**Final Line Built:** `[Dummy] -> 1 -> 2 -> 3 -> 4 -> nullptr`

---

### Leaving the Playground

The game is over, but the bus driver doesn't want to see our helper `Dummy` at the front of the line. The driver only cares about the actual kids!

So, we tell the driver to look right behind Dummy: `return dummy.next;` which gives them **Kid 1**, the true leader of our beautifully merged line!*/

#include <iostream>

struct Listnode
{
    int val;
    Listnode*next;
    Listnode(int x):val(x),next(nullptr){}
};

class solution{
    public:
    Listnode* mergeTwoList(Listnode*list1,Listnode*list2){
        Listnode dummy(0);
        Listnode*tail=&dummy;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val<=list2->val){
                tail->next=list1;
                list1=list1->next;
            }
            else{
                tail->next=list2;
                list2=list2->next;
            }
            tail=tail->next;

        }
        if(list1!=nullptr){
            tail->next=list1;
        }
        else{
            tail->next=list2;
        }
        return dummy.next;
    }
};
