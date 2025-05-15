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

class DoubleLinkedList
{
    private :
     Node *START;

     public :
        DoubleLinkedList()
        {
            START = NULL;
        }

    void addNode()
    {
        int nim;
        cout << "\nEnter the roll member of student :";
        cin >> nim;

        //step 1 : Allocate memory for new node
        Node *newNode =new Node();

        // step 2 : Assign value to the data fields
        newNode->noMhs = nim;

        // step 3 : insert at beginning if list is empty or nim is smallest
        if (START == NULL || nim <= START->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "\nDuplicate number not allowed" << endl;
                return;
            }
            // step 4 : newNode.next = START
            newNode->next = START;

            // step 5 : START.prev = newNode (if START exists)
            if (START != NULL)
                START->prev - newNode;

            // step 6 : newNode.prev = NULL
            newNode->prev = NULL;

            //step 7 : START =newNode
            START = newNode;
            return;
            }

            //insert in between node
            // step 8 : locate position for insertion
            Node *current = START;
            while (current->next != NULL && current->next->noMhs < nim)
            {
                current = current-> next;
            }

            if (current->next != NULL && nim == current->next->noMhs)
            {
                cout << "\nDuplicate roll numbers not allowed" << endl;
                return;
            }
            //step 9: insert between current and current->next
            newNode->next = current->next;  //step 9a : newNode.next = current.next
            newNode->prev = current;        //step 9b : newNode.prev = current

            // insert last node
            if (current->next !=NULL)
                current->next->prev = newNode;  // step 9c : current.next.prev
                current->next = newNode;        // step 9d : current.next = newNode
    }

    void hapus()
    {
        if (START == NULL)
        {
            cout << "\nList is" << endl;
            return;
        }

        cout << "\nMasukkan NIM yang akan didelete";
        int rollNo;
        cin >> rollNo;

        Node *current = START;

        //step 1 : transverse the list to find the node
        while (current != NULL && current->noMhs !=rollNo)
        {
            current = current->next;
            return;
        }
    }
    
};
