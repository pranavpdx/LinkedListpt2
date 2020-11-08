// LinkedListpt1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// The program uses linked lists to add, print, and delete froma student database
//Author: Pranav Sharma
//Date: 11/7/20

#include <iostream>
#include "Node.h"
#include <iomanip>
#pragma warning(disable : 4996)
using namespace std;
// Function Protoypes
void printList(Node* next);
void printInfo(Node* next);
void askInfo(Student* &student);
void add(Node* head, Node* current, Node* last);
void deleteNode(Node* &head, int id, Node* &last);
// head pointer of the list
Node* head = NULL;
int main()
{   
    // initializes the static variables
    bool playing = true;
    char* input = new char();
    // runs program while user indicates they still want to play
    while (playing) {
        // asks user what they want to do
        cout << "What would you like to do? (ADD, PRINT, DELETE, or QUIT)" << endl;
        cin.getline(input, 80, '\n');
        // if user wants to add
        if (strcmp(input, "ADD") == 0) {
            // creates a new student pointer to add as the value of the linked list
            Student* student = new Student();
            askInfo(student);
            // creates new node of the linked list
            Node* node = new Node(student);
            node->setNext(NULL);
            // last pointer is needed to sort the newly added node 
            Node* last = NULL;
            // if head is already pointing to a node...
            if (head != NULL) {
                // if newly added node has an ID lower than the head, it becomes the next head
                if (head->getStudent()->getID() > student->getID()) {
                    node->setNext(head);
                    head = node;
                }
                // else its put in the add function where it is sorted in the list
                else {
                    add(head, node, last);
                    delete last;
                }
            }
            // if head points to nothing, the list is beggining and the node becomes the head
            else {
                head = node;
            }
        }
        // if user wants to print, the linked list is recursively printed
        else if (strcmp(input, "PRINT") == 0) {
            printList(head);
        }
        // if the user wants to delete a node..
        else if (strcmp(input, "DELETE") == 0) {
            // asks for the ID the the user wants to delete
            int id = 0;
            cout << "Which id would you like to delete?\n";
            cin >> id;
            cin.get();
            // if user wants to delete the head of the list, the next node becomes the head and the head is deleted
            if (head->getStudent()->getID() == id) {
                Node* temp = head;
                head = head->getNext();
                delete temp; 
                
            }
            else {
                // if not, recurvisely goes over the linked list and deletes the node
                Node* last = NULL;
                Node* temp = head;
                deleteNode(temp, id, last);
                delete last;
            }
        }
        // if user wants ot quit, loops ends :(
        else if (strcmp(input, "QUIT") == 0) {
            cout << "Thank you for playing";
            playing = false;
        }
        // tells user that they didnt enter a proper command
        else {
            cout << "Oopsie! You didn't enter a proper input :(\n";
        }
    }
}
// function to delete a node
void deleteNode(Node* &head, int id, Node* &last) {
    Node* ptr = head;
    if (head != NULL) {
        // if the ptr has the id needed to be deleted, 
        if (ptr->getStudent()->getID() == id) {
            // if the last node is to be deleted, then the second to last node points to NULL
            if (ptr->getNext() == NULL) {
                if (last != NULL) {
                    last->setNext(NULL);
                }
                delete ptr;
            }
            else if (last != NULL) {
                // skips over node in linked list
                last->setNext(ptr->getNext());
                // deletes extra node
                delete ptr;
            }
            
        }
        // if id is not matched, then next next node in list is entered into the function, ptr becomes the last node
        else {
            Node* p = ptr->getNext();
            deleteNode(p, id, ptr);
        }
    }
}
// adds node in order from least ID to greatest in the list
void add(Node* head, Node* current, Node* last) {
    bool found = false;
    Node* ptr = head;
    // only runs if a head exists, (it should for the function to run)
    if (head != NULL) {
        // if ID is lower than or equal the node its being compared against, then it inserts itself before the node in the linked list
        if (current->getStudent()->getID() <= head->getStudent()->getID()) {
            found = true;
            current->setNext(head);
            if (last != NULL) {
                last->setNext(current);
            }
        }
        // if its greater than, itm oves to the next node and repeats the process
        else {
            if (ptr->getNext() != NULL && found == false) {
                last = ptr;
                add(ptr->getNext(), current, last);
            }
            // if no nodes are less than the added node, then its tagged on at the end
            else if (ptr->getNext() == NULL) {
                ptr->setNext(current);
            }
        }
    }

    
}
// prints all the student's names in the list
void printList(Node* next) {
    // before the head is printed, print "List: "
    if (next == head) {
        cout << "List: \n";
    }
    // while next is not pointing to null, it runs through the linked list and prints the names
    if (next != NULL) {
        printInfo(next);
        printList(next->getNext()); 
    }
}
// prints out the information of the node value
void printInfo(Node* next) {
    cout << "Name: " << next->getStudent()->getFirst() << " " << next->getStudent()->getLast() << ", ID: " << next->getStudent()->getID() << ", GPA: " 
        << fixed << setprecision(2) << next->getStudent()->getGPA() << endl;
}
// asks user for information to fill in a student object
void askInfo(Student* &student) {
    char* input = new char[20];
    cout << "Enter the student's first name: \n";
    cin >> input;
    student->setFirst(input);
    cout << "Enter the student's last name: \n";
    cin >> input;
    student->setLast(input);
    cout << "Enter the student's ID: \n";
    cin >> student->id;
    cout << "Enter the student's GPA: \n";
    cin >> student->gpa;
    cin.get();
}


