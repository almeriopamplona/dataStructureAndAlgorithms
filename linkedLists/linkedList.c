/******************************************************************************
 *                             LINKED LISTS                                   *
 ******************************************************************************
 * Author: Almério José Venâncio Pains Soares                                 *
 * E-mail: almeriopamplona@gmail.com                                          *
 ******************************************************************************
 * Creation:     20.03.2021                                                   *
 * Modification: 21.03.2021                                                   *
 ******************************************************************************/

#include "linkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


/******************************************************************************
 * linkedListNew                                                              *
 ******************************************************************************
 * description: creates a new node that can be used as a head for a new       *
 *              linked list, or one more node to be added into a linked list. *
 ******************************************************************************
 * parameters:                                                                *
 *      real           data  : a double data value.                           *
 *                                                                            *
 * output:                                                                    *
 *      linkedList_t   head  : a node with data and a pointer to an empty     *
                               address.                                       *
 ******************************************************************************/
linkedList_t *linkedListNew(real data)
{
    /*Creating the head of the list*/
    linkedList_t *head = (linkedList_t*) malloc(sizeof(linkedList_t));
    /*Attributing values to the node*/              
    head->data = data;
    /*The next node should be NULL, showing that it is the current ending*/
    head->next = NULL;    

    return head;
}

/******************************************************************************
 * linkedListNew                                                              *
 ******************************************************************************
 * description: free memory in the linked list and reduces it to a simple     *
 *              empty head.                                                   *
 ******************************************************************************
 * parameters:                                                                *
 *      linkedList_t   list  : required full linked list.                     *
 *                                                                            *
 * output:                                                                    *
 *      void                 : required empty linked list.                    *
 ******************************************************************************/
void linkedListFree(linkedList_t *list)
{
    free(list);
    list->next = NULL;
}

/******************************************************************************
 * linkedListAddBegin                                                         *
 ******************************************************************************
 * description: adds a new node at the beginning of the linked list. To do so,*
 *              it receives the desired linked list and the data value.       *
 ******************************************************************************
 * parameters:                                                                *
 *      linkedList_t **list  : receives the list head address (e.g, &list).   *
 *      real           data  : a double data value.                           *
 *                                                                            *
 * output:                                                                    *
 *      void                 : a new node is added at the beginning of the    *
 *                             linked list.                                   *
 ******************************************************************************/
void linkedListAddBegin(linkedList_t **list, real data)
{
    /*Creating the node element*/
    linkedList_t *node = linkedListNew(data);

    /*Head and every of its elements become the next node*/
    node->next = (*list);
    
    /*As node is the head, we rearrange things so list returns to be the head
     but with the new node as the first element of the linked list.*/
    (*list) = node; 
}

/******************************************************************************
 * linkedListAddEnd                                                           *
 ******************************************************************************
 * description: adds a new node at the end of the linked list. To do so,      *
 *              it receives the desired linked list and the data value.       *
 ******************************************************************************
 * parameters:                                                                *
 *      linkedList_t  *list  : receives the list (e.g, list).                 *
 *      real           data  : a double data value.                           *
 *                                                                            *
 * output:                                                                    *
 *      void                 : a new node is added at the end of the linked   *
 *                             list.                                          *
 ******************************************************************************/
void linkedListAddEnd(linkedList_t *list, real data)
{
    /*Moving the memory address until the last available node*/
    linkedList_t *current = list;
    while(current->next != NULL) 
    {
        current = current->next;
    }
    /*Appending a new node to the last node of the list*/
    current->next = linkedListNew(data);
}

/******************************************************************************
 * linkedListInsert                                                           *
 ******************************************************************************
 * description: adds a new node at some specific position of the linked list. *
 *              To do so, it receives the desired linked list, the data value,*
 *              and the index.                                                *
 ******************************************************************************
 * parameters:                                                                *
 *      linkedList_t  *list  : receives the list (e.g, list).                 *
 *      real           data  : a double data value.                           *
 *      natural        index : unsigned int index value.                      *
 *                                                                            *
 * output:                                                                    *
 *      void                 : a new node at the desired position in the list.*
 ******************************************************************************/
void linkedListAddByIndex(linkedList_t **list, real data, natural index)
{
    /*If the addition is at the beginning, we call an already made function 
      for this purpose.                                                       */
    if (index == 0)
    {
        linkedListAddBegin(list, data);
    }
    /*Else, we begin a search for the desired position.*/
    else
    {
        /*moving through the list until the desired position*/
        linkedList_t **current  = list;
        register natural i;
        for(i = 0; i < index-1; i++) 
        {    
            /*if the last position, we call a specific function for this*/  
            if ((*current)->next == NULL) 
            {
                linkedListAddEnd((*list), data);
                return ;
            }
            (*current) = (*current)->next;
        }

        /*creating a new node with the input data*/
        linkedList_t *tempList = linkedListNew(data);
        /*append the rest of the list in the node pointer*/
        tempList->next = (*current)->next;
        /*saving all the changes as the current list*/
        (*current)->next = tempList; 
    }
}

/******************************************************************************
 * linkedListRemoveLast                                                       *
 ******************************************************************************
 * description: removes the last node of the linked list.                     *
 ******************************************************************************
 * parameters:                                                                *
 *      linkedList_t  *list  : receives the list (e.g, list).                 *
 *                                                                            *
 * output:                                                                    *
 *      void                 : a list without the last node.                  *
 ******************************************************************************/
void linkedListRemoveLast(linkedList_t *list)
{
    /*if the linked list has only one node*/
    if (list->next == NULL) 
    {
        linkedListFree(list);
    }
    /*if the linked list has more than one*/
    else
    {
        linkedList_t *current = list;
        /*looking for the node one position before the last node*/
        while(current->next->next != NULL) 
        {
            current = current->next;
        }
        /*free the memory of the last node*/
        free(current->next);
        current->next = NULL;
    }
}

/******************************************************************************
 * linkedListRemoveFirst                                                      *
 ******************************************************************************
 * description: removes the first node of the linked list.                    *
 ******************************************************************************
 * parameters:                                                                *
 *      linkedList_t  **list  : receives the list head address (e.g, &list).  *
 *                                                                            *
 * output:                                                                    *
 *      void                  : a list without the first node.                 *                                         *
 ******************************************************************************/
void linkedListRemoveFirst(linkedList_t **list)
{
    /*Creating a support list to hold part of the linked list*/
    linkedList_t *nextList = NULL;
    /*If the list is empty, return an error*/
    if (*list == NULL) 
    {   
        printf("ERROR::list is empty"); 
        return ;
    }
    /*saving all the list elements, starting from the first node after the 
      first position.                                                        */
    nextList = (*list)->next;
    /* now, free the input list memory*/
    free(*list);
    /*returns the rest of the list elements*/
    *list = nextList; 
}

/******************************************************************************
 * linkedListRemoveByIndex                                                    *
 ******************************************************************************
 * description: removes a node at a specific position.                        *
 ******************************************************************************
 * parameters:                                                                *
 *      linkedList_t  **list  : receives the list head address (e.g, &list).  *
 *      natural         index : desired position in the list                  *
 *                                                                            *
 * output:                                                                    *
 *      void                  : a list without the node at the desired        *
 *                              position                                      *
 ******************************************************************************/
void linkedListRemoveByIndex(linkedList_t **list, natural index)
{
    if (index == 0)
    {
        linkedListRemoveFirst(list);
        return;
    }
    else
    {
        linkedList_t *current  = *list;
        linkedList_t *tempList = NULL;
        register natural i;
        for(i = 0; i < index-1; i++)
        {
            if(current->next == NULL) return;

            current = current->next;
        }

        tempList = current->next;
        current->next = tempList->next;

        free(tempList);
    }
}

/******************************************************************************
 * linkedListGet                                                              *
 ******************************************************************************
 * description: removes the first node of the linked list.                    *
 ******************************************************************************
 * parameters:                                                                *
 *      linkedList_t   *list  : receives the list (e.g, list).                *
 *      natural         index : desired position in the list                  *
 *                                                                            *
 * output:                                                                    *
 *      void                  : data at the desired postion in the linked list*
 ******************************************************************************/
real linkedListGet(linkedList_t *list, natural index)
{
    /*Return the first element, if required:*/
    if (index == 0) return list->data;

    linkedList_t *current  = list;

    /*Searching for the n-th required element*/
    register natural i;
    
    for (i = 0; i < index-1; i++)
    {
        if (current->next == NULL) 
        {
            printf("ERROR::There is no data or node for index %d\n", index);
            return -1;
        }

        current = current->next;
    } 

    return current->next->data;
}

/******************************************************************************
 * linkedListSet                                                              *
 ******************************************************************************
 * description: removes the first node of the linked list.                    *
 ******************************************************************************
 * parameters:                                                                *
 *      linkedList_t  **list  : receives the list head address (e.g, &list).  *
 *      natural         index : desired position in the list                  *
 *                                                                            *
 * output:                                                                    *
 *      void                  : a new value is set at the desired position    *
 *                              of the linked list.                           *
 ******************************************************************************/
void linkedListSet(linkedList_t *list, real data, natural index)
{
    /*for the first element*/
    if (index == 0)
    {
        list->data = data;
    }
    /*for others elements*/
    else
    {
        linkedList_t *current  = list;
        register natural i;
        for(i = 0; i < index-1; i++) 
        {    
            if (current->next == NULL) return;

            current = current->next;
        }

        current->next->data = data;
    }
}

/******************************************************************************
 * linkedListTransverse                                                       *
 ******************************************************************************
 * description: removes the first node of the linked list.                    *
 ******************************************************************************
 * parameters:                                                                *
 *      linkedList_t  **list  : receives the list head address (e.g, &list).  *
 *                                                                            *
 * output:                                                                    *
 *      void                  : printed list on the terminal screen.          *
 ******************************************************************************/
void linkedListTransverse(linkedList_t *list)
{   
    /*Copying our list into a new one, in order to not modify it*/
    linkedList_t *current = list;

    /*Moving through the list while printing the current data*/
    printf("linkedList::[");
    while(current != NULL)
    {
        printf(" %1.1f", current->data);
        current = current->next;
    }
    printf(" ]\n");
}
