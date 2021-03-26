#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */

typedef struct snode_t
{
    int data;
    struct snode_t *next;
} SListNode;

/* Struktur ADT SinglyList */

typedef struct slist_t
{
    unsigned _size;
    SListNode *_head;
} SinglyList;

/* DAFTAR FUNGSI YANG TERSEDIA */

void slist_init(SinglyList *list);
bool slist_isEmpty(SinglyList *list);
void slist_pushFront(SinglyList *list, int value);
void slist_popFront(SinglyList *list);
void slist_pushBack(SinglyList *list, int value);
void slist_popBack(SinglyList *list);
void slist_insertAt(SinglyList *list, int index, int value);
void slist_removeAt(SinglyList *list, int index);
void slist_remove(SinglyList *list, int value);
int slist_front(SinglyList *list);
int slist_back(SinglyList *list);
int slist_getAt(SinglyList *list, int index);

/* Function definition below */

void slist_init(SinglyList *list)
{
    list->_head = NULL;
    list->_size = 0;
}

bool slist_isEmpty(SinglyList *list)
{
    return (list->_head == NULL);
}

void slist_pushBack(SinglyList *list, int value)
{
    SListNode *newNode = (SListNode *)malloc(sizeof(SListNode));
    if (newNode)
    {
        list->_size++;
        newNode->data = value;
        newNode->next = NULL;

        if (slist_isEmpty(list))
            list->_head = newNode;
        else
        {
            SListNode *temp = list->_head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

int slist_back(SinglyList *list)
{
    if (!slist_isEmpty(list))
    {
        SListNode *temp = list->_head;
        while (temp->next != NULL)
            temp = temp->next;
        return temp->data;
    }
    return 0;
}

void slist_popBack(SinglyList *list)
{
    if (!slist_isEmpty(list))
    {
        SListNode *nextNode = list->_head->next;
        SListNode *currNode = list->_head;

        if (currNode->next == NULL)
        {
            free(currNode);
            list->_head = NULL;
            return;
        }

        while (nextNode->next != NULL)
        {
            currNode = nextNode;
            nextNode = nextNode->next;
        }
        currNode->next = NULL;
        free(nextNode);
        list->_size--;
    }
}

void forEachElement(SinglyList *list, void (*function)(int *data))
{
    SListNode *temp;
    temp = list->_head;
    while (temp != NULL)
    {
        function(&temp->data);
        temp = temp->next;
    }
}

void sumDigit(int *elem)
{
    int temp = 0;
    if (*elem < 10)
    {
        temp = *elem;
    }

    while (*elem != 0)
    {
        temp += (*elem % 10);
        *elem /= 10;
    }
    *elem = temp;
}

void multiply2(int *elem)
{
    *elem *= 2;
}

void printElement(int *elem)
{
    printf("%d ", *elem);
}

int main(int argc, char const *argv[])
{
    // Buat objek SinglyList
    SinglyList myList;

    // PENTING! Jangan lupa diinisialisasi
    slist_init(&myList);

    slist_pushBack(&myList, 10);
    slist_pushBack(&myList, 20);
    slist_pushBack(&myList, 30);
    slist_pushBack(&myList, 40);
    slist_pushBack(&myList, 50);
    //forEachElement(&myList, printElement);

    //perkalian
    forEachElement(&myList, multiply2);
    printf("Perkalian: ");
    forEachElement(&myList, printElement);
    printf("\n");

    //Sum digit
    printf("Sum Digit: ");
    forEachElement(&myList, sumDigit);
    forEachElement(&myList, printElement);

    printf("\n");
     //reverse linked list
    printf("Reverse: ");
    while (myList._head != NULL)
    {
        printf("%d ", slist_back(&myList));
        slist_popBack(&myList);
    }
}
