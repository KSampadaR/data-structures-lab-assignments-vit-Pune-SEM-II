#include <iostream>
using namespace std;

struct node {
    int prn;
    string name;
    string role;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;
struct node *head2 = NULL;

void create(int prn, string name, string role) {
    struct node *temp;
    temp = new node;
    temp->prn = prn;
    temp->name = name;
    temp->role = role;
    temp->next = NULL;
    head = temp;
    tail = temp;
}

void addMember(int prn, string name, string role) {
    if (head == NULL) {
        create(prn, name, role);
    } else {
        struct node *temp;
        temp = new node;
        temp->prn = prn;
        temp->name = name;
        temp->role = role;
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }
}

void deleteMember(int prn) {
    // Delete member by PRN
    if (head == NULL) {
        cout << "List is empty!" << endl;
    } else {
        struct node *q, *temp;
        q = head;
        temp = head;
        while (temp != NULL && temp->prn != prn) {
            q = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Member not found!" << endl;
        } else {
            if (temp == head) {
                head = head->next;
            } else if (temp == tail) {
                q->next = NULL;
                tail = q;
            } else {
                q->next = temp->next;
            }
            delete temp;
            cout << "Member deleted successfully!" << endl;
        }
    }
}

int totalMembersList1() {
    int count = 0;
    struct node *temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to count the total number of nodes in list 2
int totalMembersList2() {
    int count = 0;
    struct node *temp = head2;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void displayMembers() {
    struct node *temp;
    if (head == NULL) {
        cout << "List is empty!" << endl;
    } else {
        temp = head;
        while (temp->next != NULL) {
            cout << "PRN: " << temp->prn << ", Name: " << temp->name << ", Role: " << temp->role << endl;
            temp = temp->next;
        }
        cout << "PRN: " << temp->prn << ", Name: " << temp->name << ", Role: " << temp->role << endl;
    }
}

void addMember2(int prn, string name, string role) {
    if (head2 == NULL) {
        create(prn, name, role);
        head2 = head;
    } else {
        struct node *temp;
        temp = new node;
        temp->prn = prn;
        temp->name = name;
        temp->role = role;
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }
}

void displayMembers2() {
    struct node *temp;
    if (head2 == NULL) {
        cout << "Second list is empty!" << endl;
    } else {
        temp = head2;
        while (temp->next != NULL) {
            cout << "PRN: " << temp->prn << ", Name: " << temp->name << ", Role: " << temp->role << endl;
            temp = temp->next;
        }
        cout << "PRN: " << temp->prn << ", Name: " << temp->name << ", Role: " << temp->role << endl;
    }
}

void concatenateLists() {
    tail->next = head2;
    tail = head2;
}

int main() {
    head = NULL;
    tail = NULL;
    head2 = NULL;

    int choice, prn;
    string name, role;

    while (true) {
        cout << "\n---- Pinnacle Club Menu ----" << endl;
        cout << "1. Add Member" << endl;
        cout << "2. Delete Member" << endl;
        cout << "3. Display Members" << endl;
        cout << "4. Add Member to Second List" << endl;
        cout << "5. Display Second List Members" << endl;
        cout << "6. Concatenate Lists" << endl;
        cout << "8.Count total member";
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter PRN: ";
                cin >> prn;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Role (president/secretary/member): ";
                cin >> role;
                addMember(prn, name, role);
                break;
            case 2:
                cout << "Enter PRN to delete: ";
                cin >> prn;
                deleteMember(prn);
                break;
            case 3:
                cout << "---- Club Members ----" << endl;
                displayMembers();
                break;
            case 4:
                cout << "Enter PRN for second list: ";
                cin >> prn;
                cout << "Enter Name for second list: ";
                cin >> name;
                cout << "Enter Role for second list (president/secretary/member): ";
                cin >> role;
                addMember2(prn, name, role);
                break;
            case 5:
                cout << "---- Second List Members ----" << endl;
                displayMembers2();
                break;
            case 6:
                concatenateLists();
                cout << "Lists concatenated successfully!" << endl;
                break;
            case 7:
                exit(0);
                break;
            case 8:
                // Display total number of nodes in each list
                cout << "Total Members in List 1: " << totalMembersList1() << endl;
                cout << "Total Members in List 2: " << totalMembersList2() << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
                break;
        }
    }

    return 0;
}
