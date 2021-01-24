#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct node *typeptr;

struct node
{
    int info;
    typeptr next, prev;
};

typeptr first, last;

bool listEmpty()
{
    if (first == NULL)
        return true;
    else
    {
        return false;
    }
}

void buatListBaru()
{
    typeptr list;
    list = NULL;
    first = list;
    last = list;
}

void sisipDepan(int new_info)
{
    typeptr new_node;
    new_node = (node *)malloc(sizeof(node));
    new_node->info = new_info;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (listEmpty())
    {
        last = new_node;
    }
    else
    {
        first->prev = new_node;
        new_node->next = first;
    }
    first = new_node;
}

void cetakList()
{
    typeptr helper;
    helper = first;
    while (helper != NULL)
    {
        cout << helper->info << '\n';
        helper = helper->next;
    }
}

void cetakListBelakang()
{
    typeptr helper;
    helper = last;
    while (helper != NULL)
    {
        cout << helper->info << '\n';
        helper = helper->prev;
    }
}

int main()
{
    buatListBaru();
    sisipDepan(50);
    sisipDepan(20);
    sisipDepan(10);
    sisipDepan(90);

    cetakList();
    getchar();
    return 0;
}
