#ifndef TRIE_H
#define TRIE_H
#define NUM_LETTERS ((int)26)
#define A 'a'

typedef struct triNode
{
    char letter;
    long unsigned int count;
    int endOfWord;
    struct triNode *children[NUM_LETTERS];
} triNode;

typedef struct lnode
{
    char data;
    struct lnode *next;
} lnode;

typedef struct list
{
    struct lnode *head, *tail;
} list;
list makeEmptyList();
lnode *create_lnode(char c, lnode *next);
void addNodeToLast(list *lst, char c);
char *makeListToStr(const list *lst, size_t count, char *str);
void freeList(list *lst);
void printStr(char *str);
triNode *getTrieNode();
void insert(triNode *root, char *str);
void printTrieLexUp(triNode *root, int maxWordLength);
void preorder(triNode *root, char *str, int d);
void printTrieLexDown(triNode *root, int maxWordLength);
void postorder(triNode *root, char *str, int d);
void freeTrie(triNode *root);
#endif