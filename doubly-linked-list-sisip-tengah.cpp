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

void sisipDiantara(int new_info)
{
    typeptr new_node;
    new_node = (node *)malloc(sizeof(node));
    new_node->info = new_info;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (listEmpty())
    {
        first = new_node;
        last = new_node;
    }
    else if (new_info <= first->info) // sisip depan
    {
        new_node->next = first;
        first = new_node;
    }
    else
    {
        typeptr helper;
        helper = first;
        while (helper->next != NULL && new_info > helper->next->info)
            helper = helper->next;

        new_node->prev = helper;
        new_node->next = helper->next; // Sisip di tengah atau di belakang
        helper->next = new_node;
        if (new_info > last->info)
            last = new_node;
    }
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
    sisipDiantara(10);
    sisipDiantara(50);
    sisipDiantara(20);
    sisipDiantara(90);

    cetakList();
    getchar();
    return 0;
}
