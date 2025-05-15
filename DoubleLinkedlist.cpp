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
            
             //step 7 : start = newNode
            start = newNode;
            return;
        }

        // insert in between node
        // step 8 : located position for insertion
        Node *current = start;
        while (current->next != NULL && current->next->noMhs < nim)
        {
            current = current->next;
        }

        if (current->next != NULL && nim == current->next->noMhs)
        {
            cout << "\nDuplicate roll number not allowed" << endl;
            return;
        }

        //step 9 : insert between current and current->next
        newNode->next = current->next; // step 9a : newNode.next = current.next
        newNode->prev = current; // step 9b : newNode.prev = current

        //insert last node
        if (current->next !=NULL)
            current->next->prev = newNode; //step 9c : current.next.prev = newNode
        current->next = newNode; // step 9d : current.next = newNode
        
    }

    void Hapus()
    {
        if (start == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        cout <<" \nMasukan NIm yang akan didelete";
        int rollNo;
        cin >> rollNo;

        Node *current = start;

        //step 1 : traverse the list to find the node
        while (current != NULL && current->noMhs != rollNo)
        {
            current = current->next;
        }
        
        if (current == NULL)
        {
           cout << "Record not found" << endl;
           return;
        }

        //step 2 : if node is at the beginning
        if (current == start)
        {
            start = current->next; //step 2a : start = start.next
            if(start != NULL)
            {
                start->prev = NULL; //step 2b : start.prev = NULL
            }
        }
        else
        {
            //step 3 : Link previous node to next of current
            current->prev->next = current->next;

            //step 4 : if current is not the last node
            if (current->next != NULL)
            current->next->prev = current->prev;  
        }

        // step 5 : Delete the node
        delete current;
        cout << "Record with roll number " << rollNo << "deleted" << endl;
    }
    void traverse()
    {
        if (start == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        //step 1: Mark first node as currentNode
        Node *currentNode = start;

        // step 2 : repeat until currentNode == NULL
        cout << "\nRecord in ascending order of roll number are:\n";
        int i = 0;
        while (currentNode != NULL)
        {
            cout << i + 1 << ". " << currentNode->noMhs <<" " << endl;

            //step 3 : Move to next node
            currentNode = currentNode->next;
            i++;
        }
    }

    void revtraverse()
    {
        if (start == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        //step 1 : move to last node
        Node *currentNode = start;
        int i = 0;
        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
            i++;
        }

        //step 2 : Traverse backward
        cout << "\nRecord in descending order of roll number are:\n";
        while (currentNode != NULL)
        {
            cout << i + 1 << ". " << currentNode->noMhs << " " << endl;

            // step 3 : move to previous node
            currentNode = currentNode->prev;
            i--;
        }
    }

    void searchData()
    {
        if (start == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        int rollNo;
        cout << "\nEnter the roll number to search :";
        cin >> rollNo;

        Node *current = start;

        //step 1 : traverse to find matching roll number
        while (current != NULL && current->noMhs != rollNo)
        current = current->next;

        //step 2 : output result
        if (current == NULL)
        {
           cout << "Record not found\n";
        }
        else
        {
            cout << "Record found\n";
            cout << "Roll Number : " << current->noMhs << endl;
        }
        
    }
};

int main()
{
    DoubleLinkedlist list;
    char choice;

    do
    {
        cout << "\nMenu :\n";
        cout << "1. Add Record\n";
        cout << "2. Delete Record\n";
        cout << "3. View Asending\n";
        cout << "4. View Descinding\n";
        cout << "5. Search Record\n";
        cout << "6. Exit\n";
        cout << "Enter your choice";

        cin >> choice;

        switch (choice)
        {
            case '1':
                list.addNote();
                break;
            case '2':
                list.Hapus();
                break;
            case '3':
                list.traverse();
                break;
            case '4':
                list.revtraverse();
                break;
            case '5':
                list.searchData();
                break;
            case '6':
                return 0;
            default :
                cout << "Invalid option\n";
        }
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
        cout << endl;
        system("clear");
    }while (choice != '6');
}