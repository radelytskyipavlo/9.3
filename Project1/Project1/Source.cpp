#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Note {
    string firstName;
    string lastName;
    string phoneNumber;
    int birthDate[3]; 
};

void inputNotes(Note* notes, const int N) {
    for (int i = 0; i < N; i++) {
        cout << "Enter data for person #" << i + 1 << ":" << endl;
        cout << "First name: ";
        getline(cin >> ws, notes[i].firstName);
        cout << "Last name: ";
        getline(cin >> ws, notes[i].lastName);
        cout << "Phone number: ";
        getline(cin >> ws, notes[i].phoneNumber);
        cout << "Birth date (day month year): ";
        cin >> notes[i].birthDate[0] >> notes[i].birthDate[1] >> notes[i].birthDate[2];
    }
}

void sortByPhoneNumber(Note* notes, const int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (notes[j].phoneNumber > notes[j + 1].phoneNumber) {
                Note temp = notes[j];
                notes[j] = notes[j + 1];
                notes[j + 1] = temp;
            }
        }
    }
}

void printNoteInfo(const Note* notes, const int N, const string& lastName) {
    bool found = false;
    for (int i = 0; i < N; i++) {
        if (notes[i].lastName == lastName) {
            found = true;
            cout << "Information about person \"" << lastName << ", " << notes[i].firstName << "\":" << endl;
            cout << "Phone number: " << notes[i].phoneNumber << endl;
            cout << "Birth date: " << notes[i].birthDate[0] << "/" << notes[i].birthDate[1] << "/" << notes[i].birthDate[2] << endl;
        }
    }
    if (!found) {
        cout << "Person with last name \"" << lastName << "\" not found." << endl;
    }
}

int main() {
    int N;
    cout << "Enter the number of people: ";
    cin >> N;

    Note* notes = new Note[N];

    cin.ignore();

    inputNotes(notes, N);

    sortByPhoneNumber(notes, N);

    cout << "List of people sorted by phone number:" << endl;
    for (int i = 0; i < N; i++) {
        cout << i + 1 << ". " << notes[i].lastName << ", " << notes[i].firstName
            << " - Phone: " << notes[i].phoneNumber << endl;
    }

    string lastName;
    cout << "Enter the last name to get information: ";
    getline(cin >> ws, lastName);

    printNoteInfo(notes, N, lastName);

    delete[] notes;

    return 0;
}
