#include <iostream>
#include <string>
using namespace std;

class Node
{
public :
    int noMhs;
    Node *next;
    Node *prev;
};
 
class DoubleLinkedlist
{
private:
    Node *start;

    public :
    DoubleLinkedlist()
    {
        start = NULL;
    }

    void addNote()
    {
        int nim;
        cout << "\nEnter the roll number of the student : ";
        cin >> nim;
        //step 1 : allocate memory for new node
        Node *newNode = new Node();

        //step 2 : assign value to the data fields
        newNode->noMhs = nim;

        //step 3 : insert at beginning if list is empty of nim is smallest
        if (start == NULL || nim<= start->noMhs)
        {
            if (start != NULL && nim == start->noMhs)
            {
                cout << "\nDuplicate number not allowed" <<endl;
                return;
            }
            // step 4 : newNode.next = start
            newNode->next = start;

            // step 5 : start.prev = newNode (if start exists)
            if(start != NULL)
            start->prev = newNode;

            //step 6 : newNode.prev = NULL
            newNode->prev = NULL;
            
        }
    }

};