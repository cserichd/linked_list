#ifndef LINKED_LIST_H
#define LINKED_LIST_H_

//--------------------------------------------------------------
// General Linked list library
//    - singly linked list
//	  - doubly circular linked list
//--------------------------------------------------------------

//-------------------------------------------------
// Struct for the circular doubly linked list
//   *next: pointer to the next item
//   *prev: pointer to the previous item
//-------------------------------------------------
typedef struct C_NODE_TD {
    struct C_NODE_TD* next;
    struct C_NODE_TD* prev;
} C_NODE;

//-------------------------------------------------
// Struct for the singly linked list
//   *next: pointer to the next item
//-------------------------------------------------
typedef struct S_NODE_TD {
    struct S_NODE_TD* next;
} S_NODE;

// typedef for the guard of the circular doubly linked list
typedef C_NODE C_LIST;

// typedef for the guard of the singly linked list
typedef S_NODE S_LIST;

//---------------------------------------------------------------------------------------------------------

//-----------------------------
// DOUBLY CIRCULAR LINKED LIST
//-----------------------------

//-------------------------------------------------
// INIT_C_LIST
//    - initialize the doubly circular linked list
//    - base case: C_LIST guard points to itself
//  - input value:
//     - C_LIST: guard of the list
//-------------------------------------------------
#define INIT_C_LIST(C_LIST) \
(C_LIST)->next = (C_LIST),\
(C_LIST)->prev = (C_LIST)
//-------------------------------------------------
// INSERT_BEFORE
//    - insert the C_NODE before C_LIST
//  - input value:
//     - C_LIST: base item
//     - C_NODE: node to insert before
//-------------------------------------------------
#define INSERT_BEFORE(C_LIST, NODE) \
(NODE)->next = (C_LIST), \
(NODE)->prev = (C_LIST)->prev, \
(C_LIST)->prev->next = (NODE), \
(C_LIST)->prev = (NODE)

//-------------------------------------------------
// INSERT_AFTER
//    - insert the C_NODE after C_LIST
//  - input value:
//     - C_LIST: base item
//     - C_NODE: node to insert after
//-------------------------------------------------
#define INSERT_AFTER(C_LIST, NODE) \
(NODE)->next = (C_LIST)->next, \
(C_LIST)->next->prev = (NODE), \
(NODE)->prev = (C_LIST), \
(C_LIST)->next = (NODE)


//-------------------------------------------------
// INSERT_AFTER_HEAD
//    - insert the C_NODE after guard of the list
//  - input value:
//     - C_LIST: guard item
//     - C_NODE: node to insert after
//-------------------------------------------------
#define INSERT_AFTER_HEAD(C_LIST,NODE)  INSERT_AFTER(C_LIST,(NODE))

//-------------------------------------------------
// INSERT_BEFORE_HEAD
//    - insert the C_NODE before guard of the list
//  - input value:
//     - C_LIST: guard item
//     - C_NODE: node to insert before
//-------------------------------------------------
#define INSERT_BEFORE_HEAD(C_LIST,NODE) INSERT_BEFORE(C_LIST,(NODE))

//-------------------------------------------------
// REMOVE_FROM_LIST
//    - remove the C_NODE from the list
//  - input value:
//     - C_NODE: node to delete
//-------------------------------------------------
#define REMOVE_FROM_LIST(NODE)  \
(NODE)->prev->next = (NODE)->next, \
(NODE)->next->prev = (NODE)->prev

//-------------------------------------------------
// REMOVE_BEFORE_HEAD
//    - remove a node before the guard
//  - input value:
//     - C_LIST: guard of the list
//-------------------------------------------------
#define REMOVE_BEFORE_HEAD(C_LIST) \
(C_LIST)->prev = (C_LIST)->prev->prev, \
(C_LIST)->prev->next = (C_LIST)

//-------------------------------------------------
// REMOVE_AFTER_HEAD
//    - remove a node before the guard
//  - input value:
//     - C_LIST: guard of the list
//-------------------------------------------------
#define REMOVE_AFTER_HEAD(C_LIST) \
(C_LIST)->next = (C_LIST)->next->next, \
(C_LIST)->next->prev = (C_LIST)

//-------------------------------------------------
// FOR_EACH_FWD:
//    - goes through the list forward
//  - input value:
//     - C_LIST: guard of the list
//-------------------------------------------------
#define FOR_EACH_FWD(C_LIST, ACT_NODE) \
for((ACT_NODE) = (C_LIST)->next; (ACT_NODE) != (C_LIST); (ACT_NODE) = (ACT_NODE)->next)

//-------------------------------------------------
// FOR_EACH_BWD:
//    - goes through the list backward
//  - input value:
//     - C_LIST: guard of the list
//-------------------------------------------------
#define FOR_EACH_BWD(C_LIST, ACT_NODE) \
for((ACT_NODE) = (C_LIST)->prev; (ACT_NODE) != (C_LIST); (ACT_NODE) = (ACT_NODE)->prev)

//-------------------------------------------------
// IN_THE_LIST_NODE:
//    - find the node in the list
//  - input value:
//     - C_LIST: guard of the list
//     - C_NODE: node to find
//  - return value:
//     - 1 if the node is in the list
//     - 0 if the node is not in the list
//-------------------------------------------------
#define IN_THE_LIST_NODE(LIST,NODE,IN_LIST)  \
do { \
C_NODE *node; \
(IN_LIST) = 0; \
for(node = (LIST)->next; ((node != (LIST)) && (node != (NODE))); node = node->next); \
if(node == (LIST)) { \
(IN_LIST) = 1; \
} \
} while(0)

//-------------------------------------------------
// FIND_NODE_INDEX:
//    - find the node by index
//  - input value:
//     - C_LIST: guard of the list
//     - INDEX:  index of node
//-------------------------------------------------
#define FIND_NODE_INDEX(C_LIST,INDEX,NODE) \
do { \
unsigned int i; \
for(i = 0, (NODE) = (C_LIST)->next; (((NODE) != (C_LIST)) && (i != (INDEX))); i++, (NODE) = (NODE)->next); \
if((NODE) == (C_LIST)) { \
(NODE) = 0; \
} \
} while(0)

//-------------------------------------------------
// LIST_EMPTY:
//    - gives back wether the list is empty or not
//  - input value:
//     - C_LIST: guard of the list
//  - return value:
//     - 0 if list is empty, 1 if list is not empty
//-------------------------------------------------
#define LIST_EMPTY(C_LIST,EMPTY) \
do{ \
if((C_LIST)->next == (C_LIST)) { \
(EMPTY) = 0; \
} else { \
(EMPTY) = 1; \
}\
} while(0)

//-------------------------------------------------
// LIST_LENGTH:
//    - gives back the length of the list
//  - input value:
//     - C_LIST: guard of the list
//  - return value:
//     - length of the list
//-------------------------------------------------
#define LIST_LENGTH(C_LIST,LENGTH) \
do{ \
C_NODE *act_node; \
(LENGTH) = 0; \
FOR_EACH_FWD((C_LIST),(act_node)) { \
(LENGTH)++; \
}\
} while(0)

//-------------------------------------------------
// FIND_VALUE_IN_LIST:
//    - looking for the node: checks if the node is
//        in the list by a compare rule
//  - input value:
//     - C_LIST:       guard of the list
//     - value:        value to match
//     - compare_func: rule of the comparing
//  - return value:
//     - 1 if not in the list
//     - 0 if in the list
//-------------------------------------------------
#define FIND_VALUE_IN_LIST(C_LIST,VALUE,COMPARE_FUNC,IN_LIST) \
do { \
C_NODE *act_node; \
(IN_LIST) = 0; \
for(act_node = (C_LIST)->next; (COMPARE_FUNC(act_node,VALUE)) && (act_node != (C_LIST)); act_node = act_node->next); \
if(act_node == (C_LIST)) { \
(IN_LIST) = 1; \
}\
} while(0)

//-------------------------------------------------
// INSERT_ARRANGED:
//    - insert into the list by order
//  - input value:
//     - C_LIST:       guard of the list
//     - C_NODE:       node to add
//     - COMPARE_FUNC: rule to add
//     - VALUE:        value to order by
//-------------------------------------------------
#define INSERT_ARRANGED(C_LIST,NODE,COMPARE_FUNC,VALUE) \
do{ \
C_NODE* act_node; \
if((C_LIST)->next == (C_LIST)) { \
INSERT_AFTER_HEAD((C_LIST),(NODE));\
} else {\
for(act_node = (C_LIST)->next; !((COMPARE_FUNC(act_node,VALUE) == 1) || (COMPARE_FUNC(act_node,VALUE) == 0)); act_node = act_node->next); \
INSERT_BEFORE(act_node,(NODE)); \
} \
} while(0)

//---------------------------------------------------------------------------------------------------------

//-----------------------------
// SINGLY LINKED LIST
//-----------------------------

//-------------------------------------------------
// INIT_S_LIST
//    - initialize the single linked list
//    - base case: C_LIST guard points to NULL
//  - input value:
//     - C_LIST: guard of the list
//-------------------------------------------------
#define INIT_S_LIST(S_LIST) \
(S_LIST)->next = 0

//-------------------------------------------------
// INSERT_BEFORE_S
//    - insert the S_NODE before S_LIST
//  - input value:
//     - S_LIST: base item
//     - S_NODE: node to insert before
//-------------------------------------------------
#define INSERT_BEFORE_S(S_LIST, NODE, S_NEW_NODE) \
do{ \
S_NODE* act_node; \
for(act_node = (S_LIST)->next; (act_node != (S_LIST)) && (act_node->next != (NODE)); act_node = act_node->next); \
(S_NEW_NODE)->next = act_node->next->next; \
act_node->next   = (S_NEW_NODE); \
} while(0)

//-------------------------------------------------
// INSERT_AFTER_S
//    - insert the S_NODE after S_LIST
//  - input value:
//     - S_LIST: base item
//     - S_NODE: node to insert after
//-------------------------------------------------
#define INSERT_AFTER_S(S_LIST, S_NODE) \
do { \
if(!((S_LIST)->next)) { \
(S_LIST)->next = (S_NODE); \
(S_NODE)->next = 0; \
} else { \
(S_NODE)->next = (S_LIST)->next; \
(S_LIST)->next = (S_NODE); \
} \
} while(0)

//-------------------------------------------------
// INSERT_AFTER_HEAD_S
//    - insert the S_NODE after guard of the list
//  - input value:
//     - S_LIST: guard item
//     - S_NODE: node to insert after
//-------------------------------------------------
#define INSERT_AFTER_HEAD_S(S_LIST,NODE)   INSERT_AFTER_S((S_LIST),(NODE))

//-------------------------------------------------
// INSERT_END_S(S_LIST,S_NODE)
//    - insert a node to the end of the list
//  - input value:
//     - S_LIST: guard item
//     - S_NODE: node to insert to the end
//-------------------------------------------------
#define INSERT_END_S(S_LIST,NODE) \
do { \
S_NODE* act_node; \
for(act_node = (S_LIST)->next; act_node->next != 0; act_node = act_node->next); \
INSERT_AFTER_S(act_node, (NODE)); \
} while(0)

//-------------------------------------------------
// REMOVE_FROM_LIST_S
//    - remove the S_NODE from the list
//  - input value:
//     - S_LIST: guard item
//     - S_NODE: node to delete
//-------------------------------------------------
#define REMOVE_FROM_LIST_S(S_LIST, NODE) \
do { \
  S_NODE* act_node; \
  for(act_node = (S_LIST); act_node->next != (NODE); act_node = act_node->next); \
  act_node->next = act_node->next->next; \
} while(0)

//-------------------------------------------------
// REMOVE_AFTER_HEAD_S
//    - remove a node before the guard
//  - input value:
//     - S_LIST: guard of the list
//-------------------------------------------------
#define REMOVE_AFTER_HEAD_S(S_LIST) \
(S_LIST)->next = (S_LIST)->next->next

//-------------------------------------------------
// FOR_EACH_S:
//    - goes through the list
//  - input value:
//     - S_LIST: guard of the list
//-------------------------------------------------
#define FOR_EACH_S(S_LIST,ACT_NODE) \
for((ACT_NODE) = (S_LIST)->next; (ACT_NODE) != 0; (ACT_NODE) = (ACT_NODE)->next)

//-------------------------------------------------
// IN_THE_LIST_NODE_S:
//    - find the node in the list
//  - input value:
//     - S_LIST: guard of the list
//     - S_NODE: node to find
//  - return value:
//     - 1 if the node is in the list
//     - 0 if the node is not in the list
//-------------------------------------------------
#define IN_THE_LIST_NODE_S(S_LIST,NODE,IN_LIST) \
do { \
S_NODE* act_node; \
(IN_LIST) = 0; \
for(act_node = (S_LIST)->next; ((act_node != 0) && (act_node != (NODE))); act_node = act_node->next); \
if(!act_node) { \
(IN_LIST) = 1; \
} \
} while(0)

//-------------------------------------------------
// FIND_NODE_INDEX_S:
//    - find the node by index
//  - input value:
//     - S_LIST: guard of the list
//     - INDEX:  index of node
//  - return value:
//     - address of the node: 0 if the node is not
//           in the list
//-------------------------------------------------
#define FIND_NODE_INDEX_S(S_LIST,INDEX,NODE_ADD) \
do { \
unsigned int i; \
for(i = 0, (NODE_ADD) = (S_LIST)->next; (i != INDEX) && ((NODE_ADD) != 0); i++, (NODE_ADD) = (NODE_ADD)->next); \
} while(0)

//-------------------------------------------------
// LIST_LENGTH_S:
//    - gives back the length of the list
//  - input value:
//     - S_LIST: guard of the list
//  - return value:
//     - length of the list
//-------------------------------------------------
#define LIST_LENGTH_S(S_LIST,LIST_LENGTH) \
do { \
S_NODE* act_node; \
(LIST_LENGTH) = 0; \
FOR_EACH_S((S_LIST),act_node) { \
(LIST_LENGTH)++; \
}\
} while(0)

//-------------------------------------------------
// FIND_VALUE_IN_LIST_S:
//    - looking for a node in the list by a proper
//       comparing rule, if the node is in the list
//       it gives back 0
//  - input value:
//     - S_LIST:       guard of the list
//     - value:        value to match
//     - compare_func: rule of the comparing
//  - return value:
//     - address of the node
//-------------------------------------------------
#define FIND_VALUE_IN_LIST_S(S_LIST,VALUE,COMPARE_FUNC,IN_THE_LIST) \
do { \
  (IN_THE_LIST) = 0; \
  S_NODE *act_node; \
  for(act_node = (S_LIST)->next; ((COMPARE_FUNC(act_node,(VALUE))) && (act_node != 0)), act_node = act_node->next); \
  if(!act_node) { \
    (IN_THE_LIST) = 1; \
  }\
} while(0)


//-------------------------------------------------
// INSERT_ARRANGED_S:
//    - insert into the list by order
//  - input value:
//     - S_LIST:       guard of the list
//     - S_NODE:       node to add
//     - COMPARE_FUNC: rule to add
//     - VALUE:        value to order by
//-------------------------------------------------
#define INSERT_ARRANGED_S(S_LIST,NODE,COMPARE_FUNC,VALUE) \
do { \
  S_NODE* act_node; \
  if(!((S_LIST)->next)) { \
    INSERT_AFTER_HEAD_S((S_LIST),(NODE)); \
  } else { \
  for(act_node = (S_LIST); (COMPARE_FUNC(act_node->next,(VALUE)) == -1) && (act_node->next != 0); act_node = act_node->next); \
  INSERT_AFTER_S(act_node,(NODE)); \
  } \
} while(0)

//-------------------------------------------------
// LIST_EMPTY_S:
//    - gives back wether the list is empty or not
//  - input value:
//     - S_LIST: guard of the list
//  - return value:
//     - 0 if list is empty, 1 if list is not empty
//-------------------------------------------------
#define LIST_EMPTY_S(S_LIST,EMPTY) \
do{ \
  if(!((S_LIST)->next)) { \
    (EMPTY) = 0; \
  } else { \
    (EMPTY) = 1; \
  }\
} while(0)

#endif