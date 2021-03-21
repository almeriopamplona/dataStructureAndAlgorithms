/******************************************************************************
 *                            DATA STRUCTURES                                 *
 *                              LINKED LISTS                                  *
 ******************************************************************************
 * Author: Almério José Venâncio Pains Soares Pamplona                        *
 * E-mail: almeriopamplona@gmail.com                                          *
 ******************************************************************************
 * Creation:     20.03.2021                                                   *
 * Modification: 21.03.2021                                                   *
 ******************************************************************************
 * REFERENCE:                                                                 *
 *                                                                            *
 * [1] freeCodeCamping.org -> YouTube channel: Data Structures Easy to        *
 * Advanced Course - Full Tutorial from a Google Engineer                     *
 *                                                                            *
 * [2] https://github.com/willianfiset/data-strucutures                       *
 *                                                                            *
 ******************************************************************************/

#include "linkedList.h"
#include <stdio.h>

int main()
{
    /*Creating a head for the linked list*/
    linkedList_t *list = linkedListNew(3);
    linkedListTransverse(list);

    /*Adding several nodes at the END of the list*/
    register natural i;
    for(i = 4; i < 7; i++)
    {   
        linkedListAddEnd(list, i);
    }
    /*print the result*/
    linkedListTransverse(list);

    /*Adding several nodes at the BEGIN of the list*/
    for(i = 2; i > 0; i--)
    {   
        linkedListAddBegin(&list, i);
    }
    /*print the result*/
    linkedListTransverse(list);

    /*Getting a node at position 1, it should be 2.0*/
    natural index = 1;
    printf("linkedList[%d]::[ %1.1f", index,linkedListGet(list,index));
    printf(" ]\n");
    
    /*Adding data equals 15 at position 1 of the list*/
    linkedListAddByIndex(&list,15, 1);
    linkedListTransverse(list);

    /*Setting 10 to potions 3*/
    linkedListSet(list, 10, 3);
    linkedListTransverse(list);

    /*Removing node at position 2*/
    linkedListRemoveByIndex(&list, 2);
    linkedListTransverse(list);

    /*Removing node at last position*/
    linkedListRemoveLast(list);
    linkedListTransverse(list);

    /*Removing node at first position*/
    linkedListRemoveFirst(&list);
    linkedListTransverse(list);

    /*Free memory*/
    linkedListFree(list);

    return 0;
}
