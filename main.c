#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

int main(int argc, char const *argv[])
{
    list lst = makeEmptyList();
    char c = 0, *str = NULL;
    triNode *root = getTrieNode();
    int isR = 1;
    int counter = 0, theBiggestWord = 0;
    if (argc == 2 && strcmp(argv[1], "r") == 0)
    { // check if there is an input from user
        isR = 0;
    }
    while ((c = getc(stdin)) != EOF)
    {
        if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        {
            counter++;

            if (c >= 65 && c <= 90)
            {
                c = c + 32;
            }
            addNodeToLast(&lst, c);
        }
        if (c == ' ' || c == '\t' || c == '\n')
        {
            str = makeListToStr(&lst, counter, str);
            if (counter != 0)
                insert(root, str);
            if (counter > theBiggestWord)
                theBiggestWord = counter;
            freeList(&lst);
            counter = 0;
        }
    }
    if (isR)
    {
        printTrieLexUp(root, theBiggestWord);
    }
    else
    {
        printTrieLexDown(root, theBiggestWord);
    }
    freeTrie(root);
    free(root);
    root = NULL;

    return 0;
}