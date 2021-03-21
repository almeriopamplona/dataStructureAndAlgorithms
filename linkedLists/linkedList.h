/******************************************************************************
 *                             LINKED LISTS                                   *
 ******************************************************************************
 * Author: Almério José Venâncio Pains Soares                                 *
 * E-mail: almeriopamplona@gmail.com                                          *
 ******************************************************************************
 * Creation:     20.03.2021                                                   *
 * Modification: 21.03.2021                                                   *
 ******************************************************************************
 * Description:                                                               * 
 *                                                                            *
 * This is a single linked list, which has various functions to create, add,  *
 * remove, set and get a node. Furthermore, there is a method to transverse   *
 * the linked list.                                                           *
 *                                                                            *
 ******************************************************************************/

#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

/******************************************************************************
 * DATA TYPE DEFINITION                                                       *
 ******************************************************************************/
typedef unsigned int natural;
typedef double       real;     

typedef struct linkedList
{   
    real               data;
    struct linkedList *next;

} linkedList_t;

/******************************************************************************
 * HANDLE FUNCTIONS                                                           *
 ******************************************************************************/

linkedList_t *linkedListNew(real data);
void linkedListFree(linkedList_t *list);
void linkedListAddBegin(linkedList_t **list, real data);
void linkedListAddEnd(linkedList_t *list, real data);
void linkedListAddByIndex(linkedList_t **list, real data, natural index);
void linkedListRemoveLast(linkedList_t *list);
void linkedListRemoveFirst(linkedList_t **list);
void linkedListRemoveByIndex(linkedList_t **List, natural index);
void linkedListSet(linkedList_t *list, real data, natural index);
real linkedListGet(linkedList_t *list, natural index);
void linkedListTransverse(linkedList_t *list);

#endif
/*****END*****/
