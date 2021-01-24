#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct node *typeptr;

struct node
{
    int info;
    typeptr next;
};

typeptr head;

bool listEmpty()
{
    if (head->next == head)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void buatListBaru()
{
    head = (node *)malloc(sizeof(node));
    head->next = head;
    head->info = 0;
}

void sisipDepan(int new_info)
{
    typeptr new_node;
    new_node = (node *)malloc(sizeof(node));
    new_node->info = new_info;
    new_node->next = NULL;

    if (listEmpty())
    {
        new_node->next = head;
        head->next = new_node;
    }
    else
    {
        new_node->next = head->next;
        head->next = new_node;
    }
    head->info++;
}

void sisipBelakang(int new_info)
{
    typeptr new_node;
    new_node = (node *)malloc(sizeof(node));
    new_node->info = new_info;
    new_node->next = head;

    if (listEmpty())
    {
        head->next = new_node;
    }
    else
    {
        typeptr helper;
        helper = head;
        while (helper->next != head)
            helper = helper->next;

        helper->next = new_node;
    }
    head->info++;
}

void cetakList()
{
    typeptr helper;
    helper = head->next;
    while (helper != head)
    {
        cout << helper->info << '\n';
        helper = helper->next;
    }
}

int main()
{
    buatListBaru();
    sisipDepan(50);
    sisipDepan(20);
    sisipDepan(10);
    sisipDepan(90);

    // sisipBelakang(50);
    // sisipBelakang(20);
    // sisipBelakang(10);
    // sisipBelakang(90);

    cetakList();
    getchar();
    return 0;
}
