**STACK / PILE**

A stack is an abstract data type to which some operations can be done : 
- push which adds an element
- pop which removes the latest element added
- and maybe peek returns the value of the latest element added
- Swap or exchange: the two topmost items on the stack exchange places.


LIFO refers to the order in which elements are added or removed from the stack, last in first out. Accessing a datum (single data) that is deep in the stack might turn out difficult and involves removing other items first.

A stack can be easily implemented through *(i) an linked list*, or *(ii) a simple array*, as it's just a special case of list. What determines that it's a stack is not the implementation but how it can be interacted with.

![image](https://user-images.githubusercontent.com/113340699/210344687-b25f13c3-5e9c-49bd-8bb4-a1949cc29323.png)

When using a singly linked list, a stack is then a pointer to the "head" of the list, with perhaps a counter to keep track of the size of the list. Every stack has a fixed location, in memory, at which it begins. As data items are added to the stack, the stack pointer is displaced to indicate the current extent of the stack, which expands away from the origin.  

```
structure frame:
    data : item
    next : frame or nil
```

```    
structure stack:
    head : frame or nil
    size : integer
```

```
procedure initialize(stk : stack):
    stk.head ← nil
    stk.size ← 0
```

Pushing and popping items happens at the head of the list; overflow is not possible in this implementation (unless memory is exhausted):

```
procedure push(stk : stack, x : item):
    newhead ← new frame
    newhead.data ← x
    newhead.next ← stk.head
    stk.head ← newhead
    stk.size ← stk.size + 1
```

```
procedure pop(stk : stack):
    if stk.head = nil:
        report underflow error
    r ← stk.head.data
    stk.head ← stk.head.next
    stk.size ← stk.size - 1
    return r
```

Source : https://en.wikipedia.org/wiki/Stack_(abstract_data_type)

**ANALYSIS OF ALGORYTHMS**

The analysis of algorythms is the process of finding the computational complexity of algorythms i.e the amount of time, storage or other ressources needed to execute them. Not sure how relevant this will be to my project so stopping research now. The hint was in the subject though. 

- Time complexity : size of an algo's input to the number of steps it takes
- Space complexity : number of storafe locations it uses

Source: https://en.wikipedia.org/wiki/Analysis_of_algorithms

**CREATING MY STACK THROUGH LINKED LIST**

Structures are used in C to package several data fields into one unit. If a pointer to the struct is given, then we can access
data fields within the struct using -> operator. For example,

```
typedef struct {
 unsigned int var1;
 char* var2;
} node; 
```

```
node mynode;
node* ptr = &mynode;
ptrvar1 = 100;
ptrvar2 = malloc(20); 
```

```ptr->var1 = 100;```  
```ptr->var2 = malloc(20);```   

A linked list is a collection of objects linked together by references from one object to
another object. By convention these objects are named as nodes. So the basic linked list
is collection of nodes where each node contains one or more data fields AND a reference
to the next node. The last node points to a NULL reference to indicate the end of the list.  

Unlike Arrays, nodes cannot be accessed by
an index since memory allocated for each individual node may not be contiguous. We
must begin from the head of the list and traverse the list sequentially to access the nodes
in the list.  

Linked list is a collection of linked nodes. A node is a struct with at least a data field and
a reference to a node of the same type. A node is called a self-referential object, since it
contains a pointer to a variable that refers to a variable of the same type. For example, a
struct Node that contains an int data field and a pointer to another node can be defined as
follows.   

```
struct Node {
 int data;
 struct Node* next;
}
typedef struct Node node;
node* head = NULL; 
```

![image](https://user-images.githubusercontent.com/113340699/210794439-2fbc37f4-48f8-4710-8ea9-39515d6f75b7.png)
