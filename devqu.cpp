#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int i)
    {
        data = i;
        next = 0;
    }
    node()
    {
        next = 0;
    }
};
void create(node *&head, int i)
{
    node *n = new node(i);
    if (head == 0)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != 0)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void display(node *head)
{
    node *temp = head;
    while (temp != 0)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int listlength(node *head)
{
    int l = 0;
    while (head != 0)
    {
        l++;
        head = head->next;
    }
    return l;
}
int diff(int l1, int l2)
{
    if (l1 > l2)
        return (l1 - l2);
    else
        return (l2 - l1);
}
void addlistno(node *head1, node *head2, node *&result, int *carry)
{
    int sum;
    if (!head1)
        return;
    addlistno(head1->next, head2->next, result, carry);
    sum = head1->data + head2->data + (*carry);
    *carry = sum / 10;
    sum = sum % 10;
    node *temp = new node;
    temp->data = sum;
    temp->next = result;
    result = temp;
    cout<<"Function1 return"<<endl;
    return;
}
void addremainingno(node *head1, node *&result, int *carry, int diff)
{
    int sum = 0;
    if (!head1 || diff == 0)
        return;
    addremainingno(head1->next, result, carry, diff - 1);
    sum = head1->data + *carry;
    *carry = sum / 10;
    sum = sum % 10;
    node *temp = new node;
    temp->data = sum;
    temp->next = result;
    result = temp;
    cout<<"Function2 return"<<endl;
    return;
}
void addnowrapper(node *head1, node *head2, node *&result, int *carry)
{
    int l1, l2;
    l1 = listlength(head1);
    l2 = listlength(head2);
    node *current;
    if (l1 < l2)
    {
        current = head1;
        head1 = head2;
        head2 = current;
    }
    int d = 0;
    d = diff(l1, l2);
    current = head1;
    while (d--)
    {
        current = current->next;
    }
    addlistno(current, head2, result, carry);
    d = diff(l1, l2);
    addremainingno(head1, result, carry, d);
    if (*carry)
    {
        node *temp = new node;
        temp->data = *carry;
        temp->next = result;
        result = temp;
    }
    cout<<"main function return"<<endl;
        return;
}

int main()
{
    node *result = 0;
    node *head1 = 0;
    node *head2 = 0;
    create(head1, 5);
    create(head1, 5);
    create(head1, 1);
    display(head1);
    create(head2, 2);
    create(head2, 4);
    create(head2, 5);
    create(head2, 5);
    display(head2);
    addnowrapper(head1, head2, result, 0);
    display(result);
    return 0;
}