#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

struct triNode *getTrieNode()
{
    triNode *trinode = (triNode *)malloc(sizeof(triNode));
    trinode->count = 0;
    trinode->letter = ' ';
    trinode->endOfWord = 0;
    for (size_t i = 0; i < NUM_LETTERS; i++)
    {
        trinode->children[i] = NULL;
    }
    return trinode;
}
void insert(triNode *root, char *str)
{
    triNode *curr = root;
    while (*str)
    {
        if (curr->children[*str - 'a'] == NULL)
            curr->children[*str - 'a'] = getTrieNode();
        curr = curr->children[*str - 'a'];
        str++;
    }
    if (curr->endOfWord == 0)
    {
        curr->endOfWord = 1;
        curr->count = 1;
    }
    else
    {
        curr->count++;
    }
}
list makeEmptyList() // intialize the list
{
    list lst;
    lst.head = lst.tail = NULL;
    return lst;
}
int isEmpty(const list *lst)
{
    return (lst->head == NULL);
}
lnode *create_lnode(char c, lnode *next)
{
    lnode *newNode = (lnode *)calloc(1, sizeof(lnode));
    if (newNode != NULL)
    {
        newNode->data = c;
        newNode->next = next;
        return newNode;
    }
    else
    {
        printf("The calloc didnt succeed");
    }
    return NULL;
}
void addNodeToLast(list *lst, char c)
{
    lnode *nodeToAdd = create_lnode(c, NULL);
    if (isEmpty(lst))
        lst->head = lst->tail = nodeToAdd;
    else
    {
        lst->tail->next = nodeToAdd;
        lst->tail = nodeToAdd;
    }
}
char *makeListToStr(const list *lst, size_t count, char *str)
{
    str = (char *)malloc(count + 1);
    if (str != NULL)
    {
        lnode *current = lst->head;
        while (current != NULL)
        {
            *str = current->data;
            current = current->next;
            str++;
        }
        *str = 0;     /* end of string '\0' */
        str -= count; /*  return to the first address of the string */
        return str;
    }
    else
        printf("The malloc didnt succeced the return address is null");
    str = NULL;
    return str;
}
void freeList(list *lst)
{
    lnode *current = lst->head;
    lnode *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    lst->head = lst->tail = NULL;
}

void printTrieLexUp(triNode *root, int maxWordLength)
{
    int d = 0;
    char *str;
    str = (char *)malloc(sizeof(maxWordLength + 1));
    if (str != NULL)
    {
        preorder(root, str, d);
        free(str);
    }
    else
    {
        printf("didnt succedd to malloc");
    }
}
void printTrieLexDown(triNode *root, int maxWordLength)
{
    int d = 0;
    char *str;
    str = (char *)malloc(sizeof(maxWordLength + 1));
    if (str != NULL)
    {
        postorder(root, str, d);
        free(str);
    }
    else
    {
        printf("didnt succedd to malloc");
    }
}
void preorder(struct triNode *follow, char str[], int d)
{
    int i = 0;
    if (follow == NULL)
    {
        return;
    }
    /* Print the word at the beginning instead of the end */
    if (follow->endOfWord)
    {

        int b = follow->count;
        str[d] = 0;
        printf("%s %d \n", str, b);
    }

    for (i = 0; i < 26; i++)
    {
        /* preorder returns immediately if its argument is NULL, so
     * there's no need to check twice. Perhaps even better would be
     * to do the check here, and not do it at the beginning.
     */
        str[d] = 'a' + i;
        preorder(follow->children[i], str, d + 1);
    }
}
/*
*just changed the position of the print.
*/
void postorder(struct triNode *follow, char str[], int d)
{
    int i = 0;
    if (follow == NULL)
    {
        return;
    }

    for (i = NUM_LETTERS - 1; i >= 0; i--)
    {
        str[d] = 'a' + i;
        postorder(follow->children[i], str, d + 1);
    }
    if (follow->endOfWord)
    {
        int b = follow->count;
        str[d] = 0;
        printf("%s %d \n", str, b);
    }
}
void freeTrie(triNode *root)
{
    int i = 0;
    while (i < NUM_LETTERS)
    {
        if (root->children[i] != NULL)
        {
            freeTrie(root->children[i]);
            if (root->children[i] != NULL)
                free(root->children[i]);
            i++;
        }
        else
            i++;
    }
}
