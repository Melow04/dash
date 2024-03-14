#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct Patient {
    long long iD;
    string firstName;
    string lastName;
    int age;
    string blood;
    char gender;
    Patient* next;

    Patient() {
        this->iD = 0;
        this->age = 0;
        this->gender = 0;
        this->next = NULL;
    }
};

struct LinkedQueue {
    string departmentName;
    Patient* head, * last;
    LinkedQueue() {
        head = NULL;
        last = NULL;
    }
    Patient Input();
    void InsertAtEnd();
    void InsertAtBeg();
    void GetPatientOut();
    void ListOfPatients();

};

int ReadNumber() {
    int num;
    cin >> num;
    cin.ignore(); 
    return num;
}


void DepartmentMenu(LinkedQueue* q);

int main() {
    int choice = 0;
    LinkedQueue departments[4];
    while (choice != 5)
    {
        departments[0].departmentName = "GENERAL CLINIC\n";
        departments[1].departmentName = "HEART CLINIC\n";
        departments[2].departmentName = "LUNG CLINIC\n";
        departments[3].departmentName = "PLASTIC SURGERY\n";
        system("cls");
        cout << "\n |-- HOSPITAL MANAGEMENT SYSTEM --|\n";
        cout << " \t   Main Menu\n\n";
        for (int i = 0; i < 4; i++) {
            cout << " " << (i + 1) << ": " << departments[i].departmentName;
        }
        cout << " 5: Exit";
        cout << "\n\n Please enter your choice : ";
        choice = ReadNumber();
        if (choice >= 1 && choice <= 4) {
            DepartmentMenu(&departments[choice - 1]);
        }
    }
    if (choice == 5)
        cout << "\n\t\tThank you! \n";
    return 0;
}


Patient LinkedQueue::Input() {
    Patient* p = new Patient();
    cout << "\n Please enter data for patient\n";
    cout << "\n First name : ";
    getline(cin, p->firstName);
    cout << " Last name : ";
    getline(cin, p->lastName);
    cout << " Blood Group : ";
    while (true) {
        cin >> p->blood;
        if (p->blood == "A+" || p->blood == "a+" || p->blood == "A-" || p->blood == "a-" ||
            p->blood == "B+" || p->blood == "b+" || p->blood == "B-" || p->blood == "b-" ||
            p->blood == "O+" || p->blood == "o+" || p->blood == "O-" || p->blood == "o-" ||
            p->blood == "AB+" || p->blood == "ab+" || p->blood == "AB-" || p->blood == "ab-") {
            break;
        }
        else {
            cout << "\n Invalid Blood Group. Try again." << endl;
            cout << " Blood Group : ";
        }
    }

    cout << " Gender(m/f) : ";
    cin >> p->gender;
    cout << " Age : ";
    cin >> p->age;
    cout << " Mobile number : ";
    cin >> p->iD;
    cin.ignore(); // Clear the input buffer
    p->next = NULL;
    return *p;
}

void Output(Patient* p) {
    cout << "\n ----------------------------------";
    cout << "\n Patient data:\n";
    cout << "\n First Name : " << p->firstName;
    cout << "\n Last Name : " << p->lastName;
    cout << "\n Gender : " << p->gender;
    cout << "\n Age : " << p->age;
    cout << "\n Blood Group : " << p->blood;
    cout << "\n Mobile Number : " << p->iD;
    cout << "\n ----------------------------------";
}

void LinkedQueue::InsertAtBeg() {
    Patient* p = new Patient();
    *p = Input();
    if (p->iD == 0)
        return;
    if (head == NULL) {
        head = p;
        last = p;
        p->next = NULL;
    }
    else {
        p->next = head;
        head = p;
    }
    system("cls");
    cout << "\n\tPatient added:";
    Output(p);
}

void LinkedQueue::InsertAtEnd() {
    Patient* p = new Patient();
    *p = Input();
    if (p->iD == 0)
        return;
    if (head == NULL) {
        head = p;
        last = p;
        p->next = NULL;
    }
    else {
        p->next = NULL;
        last->next = p;
        last = p;
    }
    system("cls");
    cout << "\n ----------PATIENT ADDED-----------";
    Output(p);
}

void LinkedQueue::GetPatientOut() {
    system("cls");
    if (head == NULL) {
        cout << "\n No Patient to operate";
    }
    else {
        Patient* p = head;
        head = head->next;
        cout << "\n Patient to operate:";
        Output(p);
    }
}

void LinkedQueue::ListOfPatients() {
    if (head == NULL) {
        cout << "\n No patient";
    }
    system("cls");
    cout << "\n |-- HOSPITAL MANAGEMENT SYSTEM --|";
    Patient* p = head;
    while (p != NULL) {
        cout << "\n Patient data:\n";
        cout << "\n First Name : " << p->firstName;
        cout << "\n Last Name : " << p->lastName;
        cout << "\n Gender : " << p->gender;
        cout << "\n Age : " << p->age;
        cout << "\n Blood Group : " << p->blood;
        cout << "\n Mobile Number : " << p->iD;
        cout << "\n\n \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
        p = p->next;
    }
    cout << "\n";
}

void DepartmentMenu(LinkedQueue* q) {
    int choice = 0;
    while (choice != 5)
    {
        system("cls");

        cout << "\n |-- HOSPITAL MANAGEMENT SYSTEM --|";

        cout << "\n [1] Add normal patient\n";
        cout << " [2] Add critically ill patient\n";
        cout << " [3] Take patient to Doctor\n";
        cout << " [4] Display list\n";
        cout << " [5] Change department or exit\n";
        cout << "\n Please enter your choice : ";
        choice = ReadNumber();
        switch (choice)
        {
        case 1: q->InsertAtEnd();
            cout << "\n Press any key";
            cin.ignore(); 
            cin.get(); 
            break;
        case 2: q->InsertAtBeg();
            cout << "\n Press any key";
            cin.ignore(); 
            cin.get(); 
            break;
        case 3: q->GetPatientOut();
            cout << "\n Press any key";
            cin.ignore(); 
            cin.get(); 
            break;
        case 4: system("cls");
            q->ListOfPatients();
            cout << "\n Press any key";
            cin.ignore(); 
            cin.get(); 
            break;
        }
    }
}
