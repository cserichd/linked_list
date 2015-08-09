#include <stdio.h>
#include "linked_list.h"

#define SINGLE_DEBUG

#define CONTOF(STRUCT,ELEM,ADD)  (STRUCT*)(ADD - (unsigned char)&(((STRUCT*)0)->ELEM))

#ifdef CIRC_DEBUG
C_LIST LIST_OF_FRUITS;

typedef struct fruit {
    C_NODE        list_member;
    unsigned char amount;
    unsigned char color;
    char*         name;
} fruit_td;
#endif

#ifdef SINGLE_DEBUG
S_LIST LIST_OF_FRUITS;

typedef struct fruit {
    S_NODE        list_member;
    unsigned char amount;
    unsigned char color;
    char*         name;
} fruit_td;
#endif

int compare(S_NODE *act_node, int value);

int main () {
    unsigned int len;
    unsigned int in_list, empty;
#ifdef CIRC_DEBUG
    fruit_td alma, korte, fuge, barack, szilva;
    C_NODE* act_node;
    C_NODE *node;
    ;
    fuge.amount = 12;
    fuge.color  = 5;
    fuge.name   = "fuge";
    
    alma.amount = 5;
    alma.color  = 1;
    alma.name = "alma";
    printf("%x\t%x\n",(CONTOF(fruit_td,color,&(alma.color)))->color,alma.color);
    
    barack.amount = 4;
    barack.color  = 3;
    barack.name   = "barack";
    
    szilva.amount = 10;
    szilva.color  = 8;
    szilva.name   = "szilva";
    
    printf("FUGE: %x\n",(unsigned int)&fuge.list_member);
    printf("ALMA: %x\n",(unsigned int)&alma.list_member);
    
    INIT_C_LIST(&LIST_OF_FRUITS);
    LIST_EMPTY(&LIST_OF_FRUITS,empty);
    printf("empty list: %d\n",empty);
    
    INSERT_ARRANGED(&LIST_OF_FRUITS, &(fuge.list_member), compare, fuge.color);
    INSERT_ARRANGED(&LIST_OF_FRUITS, &(szilva.list_member), compare, szilva.color);
    INSERT_ARRANGED(&LIST_OF_FRUITS, &(barack.list_member), compare, barack.color);
    INSERT_ARRANGED(&LIST_OF_FRUITS, &(alma.list_member), compare, alma.color);
    
    // LIST_EMPTY(&LIST_OF_FRUITS,empty);
    //  printf("empty list: %d\n",empty);
    
    FOR_EACH_FWD(&LIST_OF_FRUITS,act_node) {
        printf("COLOR: %d\n", (CONTOF(fruit_td,list_member,act_node))->color);
    }
    
    
    FIND_VALUE_IN_LIST(&LIST_OF_FRUITS,barack.color,compare,in_list);
    printf("in the list: %d\n",in_list);
    
    // INSERT_AFTER_HEAD(&LIST_OF_FRUITS,&fuge.list_member);
    // INSERT_BEFORE_HEAD(&LIST_OF_FRUITS,&alma.list_member);
    
    FOR_EACH_FWD(&LIST_OF_FRUITS,act_node) {
        printf("FOR_EACH_FWD: %x\n", act_node);
    }
    FOR_EACH_BWD(&LIST_OF_FRUITS,act_node) {
        printf("FOR_EACH_BWD: %x\n", act_node);
    }
    
    FIND_NODE_INDEX(&LIST_OF_FRUITS,0,act_node);
    printf("FIND_INDEX: %x\n", act_node);
    INSERT_AFTER(act_node, &(szilva.list_member));
    FIND_NODE_INDEX(&LIST_OF_FRUITS,1,act_node);
    printf("FIND_INDEX: %x\n", act_node);
    //FOR_EACH_FWD(&LIST_OF_FRUITS,act_node) {
    //  printf("COLOR: %d\n", (CONTOF(fruit_td,list_member,act_node))->color);
    //}
    //-----------------------------------------
    IN_THE_LIST_NODE(&LIST_OF_FRUITS,act_node,in_list);
    printf("In the list: %d\n", in_list);
    
    REMOVE_FROM_LIST(act_node);
    IN_THE_LIST_NODE(&LIST_OF_FRUITS,act_node,in_list);
    printf("In the list: %d\n", in_list);
    //------------------------------
    LIST_LENGTH(&LIST_OF_FRUITS,len);
    printf("LIST_LEN: %d\n",len);
    
    REMOVE_BEFORE_HEAD(&LIST_OF_FRUITS);
    REMOVE_AFTER_HEAD(&LIST_OF_FRUITS);
    
    FOR_EACH_FWD(&LIST_OF_FRUITS,act_node) {
        printf("%x\n", act_node);
    }
    getchar();
#endif
    
#ifdef SINGLE_DEBUG
    fruit_td alma, korte, fuge, barack, szilva;
    S_NODE* act_node;
    S_NODE *node;
    
    fuge.amount = 12;
    fuge.color  = 5;
    fuge.name   = "fuge";
    printf("Fuge->color: %x\t%x\n",(CONTOF(fruit_td,list_member,&(fuge.list_member)))->color,fuge.color);
    
    alma.amount = 5;
    alma.color  = 1;
    alma.name = "alma";
    printf("Alma->color: %x\t%x\n",(CONTOF(fruit_td,list_member,&(alma.list_member)))->color,alma.color);
    
    barack.amount = 4;
    barack.color  = 3;
    barack.name   = "barack";
    printf("Barack->color: %x\t%x\n",(CONTOF(fruit_td,list_member,&(barack.list_member)))->color,barack.color);
    
    szilva.amount = 10;
    szilva.color  = 8;
    szilva.name   = "szilva";
    printf("Szilva->color: %x\t%x\n",(CONTOF(fruit_td,list_member,&(szilva.list_member)))->color,szilva.color);
    
    printf("FUGE: %x\n",(unsigned int)&fuge.list_member);
    printf("ALMA: %x\n",(unsigned int)&alma.list_member);
    printf("BARCK: %x\n",(unsigned int)&barack.list_member);
    printf("SZILVA: %x\n",(unsigned int)&szilva.list_member);
    
    INIT_S_LIST(&LIST_OF_FRUITS);
    // INSERT_BEFORE_S(S_LIST, NODE, S_NEW_NODE)
    // INSERT_AFTER_S(S_LIST, S_NODE)
    
    LIST_EMPTY_S(&LIST_OF_FRUITS,empty);
    printf("EMPTY LIST: %d\n", empty);
    
    //INSERT_AFTER_HEAD_S(&LIST_OF_FRUITS,&(fuge.list_member));
    //IN_THE_LIST_NODE_S(&LIST_OF_FRUITS,&(alma.list_member),in_list);
    //printf("IN_THE_LIST: %d\n",in_list);
    
    //LIST_LENGTH_S(&LIST_OF_FRUITS,len);
    //printf("len of the list: %d\n",len);
    
    //LIST_EMPTY_S(&LIST_OF_FRUITS,empty);
    //printf("EMPTY LIST: %d\n", empty);
    
    //INSERT_END_S(&LIST_OF_FRUITS,&(alma.list_member));
    //IN_THE_LIST_NODE_S(&LIST_OF_FRUITS,&(alma.list_member),in_list);
    //printf("IN_THE_LIST: %d\n",in_list);
    
    //LIST_LENGTH_S(&LIST_OF_FRUITS,len);
    //printf("len of the list: %d\n",len);
    
    //INSERT_END_S(&LIST_OF_FRUITS,&(szilva.list_member));
 
    INSERT_ARRANGED_S(&LIST_OF_FRUITS,&(fuge.list_member),compare,fuge.color);
    INSERT_ARRANGED_S(&LIST_OF_FRUITS,&(alma.list_member),compare,alma.color);
    INSERT_ARRANGED_S(&LIST_OF_FRUITS,&(szilva.list_member),compare,szilva.color);
    INSERT_ARRANGED_S(&LIST_OF_FRUITS,&(barack.list_member),compare,barack.color);
    
    printf("COLOR_MYSELF: %d\t%d",(CONTOF(fruit_td,color,(&LIST_OF_FRUITS)->next))->color,alma.color);
    FOR_EACH_S(&LIST_OF_FRUITS,act_node) {
        printf("COLOR: %d\n",(CONTOF(fruit_td,list_member,act_node))->color);
    }
    
    FIND_NODE_INDEX_S(&LIST_OF_FRUITS,1,act_node);
    printf("FIND_NODE_BY_INDEX: %x\n", *act_node);

    REMOVE_FROM_LIST_S(&LIST_OF_FRUITS, &(alma.list_member));
    REMOVE_AFTER_HEAD_S(&LIST_OF_FRUITS);
    
    FOR_EACH_S(&LIST_OF_FRUITS,act_node) {
        printf("FOR_EACH_S_2: %x\n",act_node);
    }
    
    
    // FIND_VALUE_IN_LIST_S(S_LIST,VALUE,COMPARE_FUNC,IN_THE_LIST)
    // INSERT_ARRANGED_S(S_LIST,NODE,COMPARE_FUNC,VALUE)
    
    getchar();
    
#endif
    
    return 0;
}

int compare(S_NODE *act_node, int value) {
    if (!act_node) {
        return 2;
    }
    if (value < (CONTOF(fruit_td,list_member,act_node))->color) {
        return 1;
    } else if (value == (CONTOF(fruit_td,list_member,act_node))->color) {
        return 0;
    } else {
        return -1;
    }
}

