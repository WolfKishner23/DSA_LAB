#include <iostream>
#include <fstream>
#include <string>
#include <cctype> // for isalpha
using namespace std;

struct Student {
    int roll;
    string name, div, addr;
};

// ---------- VALIDATION FUNCTIONS ----------
bool is_valid_roll(int roll) {
    return roll > 0;
}

bool is_valid_name(string name) {
    if (name.empty()) return false;
    for (char c : name) {
        if (!isalpha(c)) return false;
    }
    return true;
}

bool is_valid_div(string div) {
    // Division should be a single uppercase letter (A, B, C, etc.)
    return div.size() == 1 && isalpha(div[0]) && isupper(div[0]);
}

bool is_valid_addr(string addr) {
    return !addr.empty();
}

// ---------- DATABASE CLASS ----------
class Database {
public:
    // Initialize multiple records
    void initialize() {
        ofstream fout("database.txt", ios::app);
        int n;
        cout << "How many students? ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            Student s;
            cout << "\nEnter Roll No: ";
            cin >> s.roll;
            if (!is_valid_roll(s.roll)) {
                cout << "Invalid Roll Number! Must be positive.\n";
                i--;
                continue;
            }

            cout << "Enter Name: ";
            cin >> s.name;
            if (!is_valid_name(s.name)) {
                cout << "Invalid Name! Only alphabets allowed.\n";
                i--;
                continue;
            }

            cout << "Enter Division (A/B/C...): ";
            cin >> s.div;
            if (!is_valid_div(s.div)) {
                cout << "Invalid Division! Enter one capital letter.\n";
                i--;
                continue;
            }

            cout << "Enter Address: ";
            cin >> s.addr;
            if (!is_valid_addr(s.addr)) {
                cout << "Invalid Address!\n";
                i--;
                continue;
            }

            fout << s.roll << "," << s.name << "," << s.div << "," << s.addr << "\n";
            cout << "Record added!\n";
        }
        fout.close();
    }

    // Display all records
    void display() {
        ifstream fin("database.txt");
        string line;
        cout << "\n--- All Records ---\n";
        while (getline(fin, line)) {
            cout << line << "\n";
        }
        fin.close();
    }

    // Add one record
    void add() {
        ofstream fout("database.txt", ios::app);
        Student s;

        cout << "\nEnter Roll No: ";
        cin >> s.roll;
        if (!is_valid_roll(s.roll)) {
            cout << "Invalid Roll Number!\n";
            return;
        }

        cout << "Enter Name: ";
        cin >> s.name;
        if (!is_valid_name(s.name)) {
            cout << "Invalid Name!\n";
            return;
        }

        cout << "Enter Division: ";
        cin >> s.div;
        if (!is_valid_div(s.div)) {
            cout << "Invalid Division!\n";
            return;
        }

        cout << "Enter Address: ";
        cin >> s.addr;
        if (!is_valid_addr(s.addr)) {
            cout << "Invalid Address!\n";
            return;
        }

        fout << s.roll << "," << s.name << "," << s.div << "," << s.addr << "\n";
        cout << "Record added!\n";
        fout.close();
    }

    // Search record by roll
    void search(int key) {
        ifstream fin("database.txt");
        string line;
        bool found = false;

        while (getline(fin, line)) {
            int pos = line.find(',');
            int roll = stoi(line.substr(0, pos));
            if (roll == key) {
                cout << "\nRecord found:\n" << line << "\n";
                found = true;
            }
        }

        if (!found) cout << "Record not found!\n";
        fin.close();
    }

    // Modify a record
    void modify(int key) {
        ifstream fin("database.txt");
        ofstream temp("temp.txt");
        string line;
        bool found = false;

        while (getline(fin, line)) {
            int pos = line.find(',');
            int roll = stoi(line.substr(0, pos));

            if (roll == key) {
                Student s;
                cout << "\nEnter New Name: ";
                cin >> s.name;
                if (!is_valid_name(s.name)) {
                    cout << "Invalid Name!\n";
                    temp << line << "\n";
                    continue;
                }

                cout << "Enter New Division: ";
                cin >> s.div;
                if (!is_valid_div(s.div)) {
                    cout << "Invalid Division!\n";
                    temp << line << "\n";
                    continue;
                }

                cout << "Enter New Address: ";
                cin >> s.addr;
                if (!is_valid_addr(s.addr)) {
                    cout << "Invalid Address!\n";
                    temp << line << "\n";
                    continue;
                }

                temp << roll << "," << s.name << "," << s.div << "," << s.addr << "\n";
                found = true;
                cout << "Record modified!\n";
            } else {
                temp << line << "\n";
            }
        }

        fin.close();
        temp.close();
        remove("database.txt");
        rename("temp.txt", "database.txt");

        if (!found) cout << "Record not found!\n";
    }

    // Delete a record
    void del(int key) {
        ifstream fin("database.txt");
        ofstream temp("temp.txt");
        string line;
        bool found = false;

        while (getline(fin, line)) {
            int pos = line.find(',');
            int roll = stoi(line.substr(0, pos));
            if (roll == key) {
                cout << "Record deleted!\n";
                found = true;
            } else {
                temp << line << "\n";
            }
        }

        fin.close();
        temp.close();
        remove("database.txt");
        rename("temp.txt", "database.txt");

        if (!found) cout << "Record not found!\n";
    }
};

// ---------- MAIN MENU ----------
int main() {
    Database db;
    int ch, roll;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Initialize\n2. Display\n3. Add\n4. Search\n5. Modify\n6. Delete\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1: db.initialize(); break;
            case 2: db.display(); break;
            case 3: db.add(); break;
            case 4: cout << "Enter Roll: "; cin >> roll; db.search(roll); break;
            case 5: cout << "Enter Roll: "; cin >> roll; db.modify(roll); break;
            case 6: cout << "Enter Roll: "; cin >> roll; db.del(roll); break;
            case 7: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (ch != 7);

    return 0;
}