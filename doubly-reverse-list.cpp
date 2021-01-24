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
        if (new_info > last->info)
            last = new_node;
        else
            helper->next->prev = new_node;
        helper->next = new_node;
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

void reverseList()
{
    typeptr temp, helper;
    first = last;
    while (last != NULL)
    {
        // cout << "test";
        helper = last->prev;
        if (helper != NULL)
            cout << helper->info << '\n';
        last->prev = last->next;
        last->next = helper;
        if (helper == NULL)
            break;
        last = helper;
    }
    last->next = NULL;
}

int main()
{
    buatListBaru();
    sisipDepan(10);
    sisipDepan(50);
    sisipDepan(20);
    sisipDepan(21);
    sisipDepan(90);

    cetakList();
    reverseList();
    cetakList();
    getchar();
    return 0;
}
