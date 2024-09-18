// STT: 22520165
// Full Name: Nguyễn Chu Nguyên Chương
// In-Class Exercise - Part 1
// Notes or Remarks: ......
#include <iostream>
#include <stack> // For checking palindrome
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;

    LinkedList() { head = nullptr; }

    // Function prototypes for linked list operations
    void insert(int data);
    void findMiddle();
    void detectCycle();
    void reverseList();
    void eliminateDuplicates();
    bool isPalindrome();
    void searchValue(int value);
    static LinkedList *mergeTwoSortedLists(LinkedList *l1, LinkedList *l2);
    static Node *findIntersection(Node *head1, Node *head2);

    // Function to print the linked list
    void printList();
};

// Insert node at the end of the list
void LinkedList::insert(int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to find the middle of the list
void LinkedList::findMiddle()
{
    Node *slow = head;
    Node *fast = head;
    if (head != nullptr)
    {
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle element: " << slow->data << endl;
    }
}

// Function to detect a cycle in the list
void LinkedList::detectCycle()
{
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            cout << "Cycle detected!" << endl;
            return;
        }
    }
    cout << "No cycle found." << endl;
}

// Function to combine two sorted linked lists
LinkedList *LinkedList::mergeTwoSortedLists(LinkedList *l1, LinkedList *l2)
{
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;
    Node *head1 = l1->head;
    Node *head2 = l2->head;

    LinkedList *result = new LinkedList();
    Node *temp = new Node(0); // Dummy node
    Node *tail = temp;

    while (head1 != nullptr && head2 != nullptr)
    {
        if (head1->data <= head2->data)
        {
            tail->next = head1;
            head1 = head1->next;
        }
        else
        {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    if (head1 != nullptr)
    {
        tail->next = head1;
    }
    if (head2 != nullptr)
    {
        tail->next = head2;
    }

    result->head = temp->next;
    // Free the dummy node
    delete temp;
    return result;
}

// Function to find the intersection of two linked lists
Node *LinkedList::findIntersection(Node *head1, Node *head2)
{
    Node *ptr1 = head1;
    Node *ptr2 = head2;

    while (ptr1 != ptr2)
    {
        ptr1 = ptr1 == nullptr ? head2 : ptr1->next;
        ptr2 = ptr2 == nullptr ? head1 : ptr2->next;
    }

    return ptr1; // Returns either the intersection node or nullptr if there's no intersection
}

// Function to reverse the linked list
void LinkedList::reverseList()
{
    Node *prev = nullptr;
    Node *curr = head;
    Node *next = nullptr;
    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    cout << "List reversed!" << endl;
}

// Function to eliminate duplicates from a sorted linked list
void LinkedList::eliminateDuplicates()
{
    Node *current = head;
    while (current != nullptr && current->next != nullptr)
    {
        if (current->data == current->next->data)
        {
            Node *temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        else
        {
            current = current->next;
        }
    }
    // Printing the list after duplicates are removed
    cout << "List after removing duplicates: ";
    current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Function to check if the list is a palindrome
bool LinkedList::isPalindrome()
{
    if (head == nullptr || head->next == nullptr)
    {
        return true;
    }

    stack<int> s;
    Node *temp = head;

    // Push all elements to stack
    while (temp != nullptr)
    {
        s.push(temp->data);
        temp = temp->next;
    }

    // Check if elements match while popping from stack
    temp = head;
    while (temp != nullptr)
    {
        int top = s.top();
        s.pop();
        if (temp->data != top)
        {
            return false;
        }
        temp = temp->next;
    }

    return true;
}

// Function to search for a value in the list
void LinkedList::searchValue(int value)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == value)
        {
            cout << "Value " << value << " found in the list." << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Value " << value << " not found in the list." << endl;
}

// Function to print the linked list
void LinkedList::printList()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Switch case menu
int main()
{
    cout << "STT: 22520165\n";
    cout << "Full Name : Nguyen Chu Nguyen Chuong\n";
    cout << "In-Class Exercise - Part 1\n";
    cout << "Notes or Remarks: ......\n";
    cout << "\n";
    LinkedList list;
    LinkedList list2; // For merging purpose
    int choice = 0, value;
    // Insert the linked list
    cout << "Insert values into the list (Enter -1 to stop): ";
    while (true)
    {
        cin >> value;
        if (value == -1)
            break;
        list.insert(value);
    }
    LinkedList *mergedList = nullptr; // Moved declaration outside the switch
    Node *intersection = nullptr;     // Moved declaration outside the switch

    while (choice != 11)
    {
        cout << "\nMenu:\n";
        cout << "1. Insert Element\n";
        cout << "2. Find Middle Node\n";
        cout << "3. Detect Cycle\n";
        cout << "4. Combine Two Sorted Linked Lists\n";
        cout << "5. Find Intersection of Two Linked Lists\n";
        cout << "6. Reverse List\n";
        cout << "7. Eliminate Duplicates\n";
        cout << "8. Check if List is Palindrome\n";
        cout << "9. Search Value\n";
        cout << "10. Print List\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            list.insert(value);
            break;
        case 2:
            list.findMiddle();
            break;
        case 3:
            list.detectCycle();
            break;
        case 4:
            cout << "Insert values into second sorted list (Enter -1 to stop): ";
            while (true)
            {
                cin >> value;
                if (value == -1)
                    break;
                list2.insert(value);
            }
            mergedList = LinkedList::mergeTwoSortedLists(&list, &list2);
            cout << "Merged List: ";
            mergedList->printList();
            delete mergedList;
            break;
        case 5:
            intersection = LinkedList::findIntersection(list.head, list2.head);
            if (intersection != nullptr)
            {
                cout << "Intersection at node with value: " << intersection->data << endl;
            }
            else
            {
                cout << "No intersection found." << endl;
            }
            break;
        case 6:
            list.reverseList();
            break;
        case 7:
            list.eliminateDuplicates();
            break;
        case 8:
            cout << (list.isPalindrome() ? "The list is a palindrome.\n" : "The list is not a palindrome.\n");
            break;
        case 9:
            cout << "Enter value to search: ";
            cin >> value;
            list.searchValue(value);
            break;
        case 10:
            list.printList();
            break;
        case 11:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}