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

       
    }

};