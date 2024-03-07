#include <iostream>
using namespace std;

class node
{
public:
    int coefficient; // For the coeffcient of polynomial
    int exponent;    // For the power of x(polynomial)
    node *next;

public:
    // Constructor
    node(int coeff, int exp)
    {
        this->coefficient = coeff;
        this->exponent = exp;
        this->next = NULL; // For that node next is NULL
    }
};

class List
{
private:
    node *head; // jo ki linked list ke head ko point karegaa

public:
    // Constructor
    List()
    {
        this->head = NULL;
    }

    // For pushing the node in the linked list
    void push(int coeff, int exp)
    {
        node *newNode = new node(coeff, exp); // Creating a node which have coeff and exponent as given
        if (head == NULL)
        { // case where linked list is empty
            head = newNode;
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next; // taking the pointer to the last node
            }
            temp->next = newNode; // means we are inserting node at end
        }
    }

    void push_comp(List &li, int coeff, int exp)
    {
        node *temp = li.head;
        bool flag = true;

        while (temp != NULL)
        {
            if (exp == temp->exponent)
            {
                temp->coefficient = temp->coefficient + coeff;
                flag = false;
            }
            temp = temp->next;
        }

        if (flag == true)
        {
            push(coeff, exp);
        }
    }
    // For printing the polynomial
    void show()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->coefficient << "x^" << temp->exponent; // Printing the node value
            temp = temp->next;                                   // Shifting to the next node
            if (temp != NULL)
            {
                cout << "+";
            }
        }
        cout << endl;
    }

    // Now adding the polynomial
    List operator+(List &other)
    {
        List result;
        node *temp1 = head; // That means pointing to this ka head
        node *temp2 = other.head;

        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->exponent > temp2->exponent) // Agar power temp1 wale list ka large hoga
            {
                result.push(temp1->coefficient, temp1->exponent);
                temp1 = temp1->next;
            }
            else if (temp1->exponent < temp2->exponent) // Agar power temp2 wale list ka large hoga
            {
                result.push(temp2->coefficient, temp2->exponent);
                temp2 = temp2->next;
            }
            else
            { // Agar dono ka exponent equal ho
                int sum = temp1->coefficient + temp2->coefficient;
                result.push(sum, temp1->exponent); // We can also push temp2->exponent as both are same
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }

        // Agar abb kuch value bach gye in any list

        while (temp1 != NULL)
        {
            result.push(temp1->coefficient, temp1->exponent);
            temp1 = temp1->next;
        }

        while (temp2 != NULL)
        {
            result.push(temp2->coefficient, temp2->exponent);
            temp2 = temp2->next;
        }

        return result;
    }
};

int main()
{
    List l1;

    for (int i = 0; i < 5; i++)
    {
        int power;
        cout << "Enter power";
        cin >> power;
        int coeff;
        cout << "Enter Coefficient";
        cin >> coeff;
        l1.push_comp(l1, coeff, power);
    }
    l1.show();
    /*
    List l1, l2;
    l1.push(2, 3);          // 2x^3
    l1.push(1, 2);          // x^2
    l1.push(5, 1);          // x
    l1.push(5, 0);          // 5;
    cout << "Equation-1: "; // 2x^3+x^2x+5
    l1.show();

    l2.push(4, 3);          // 4x^3
    l2.push(5, 1);          // x
    l2.push(8, 0);          // 8;
    cout << "Equation-1: "; // 4x^3+x+8
    l2.show();

    List l3 = l1 + l2;
    cout << "Sum of two equation: ";
    l3.show();
*/
    return 0;
}