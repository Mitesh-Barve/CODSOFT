#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct todolist
{
    int id;
    string task;

};

int id = 0;  // Initialize id to 0
void banner();
void addTask();
void showTask();
int searchTask();
void deleteTask();

int main() {
    system("cls");
    system("Color E0");
    while (true)
    {
        banner();
        cout << "\n\t1. Add Task";
        cout << "\n\t2. Show Task"; // Corrected the function name
        cout << "\n\t3. Search Task";
        cout << "\n\t4. Delete Task";
        cout << "\n\t5. Update Task"; // You need to implement the updateTask function

        int choice;
        cout << "\n\t Enter choice:"; // Added a semicolon
        cin >> choice;

        switch (choice)
        {
        case 1:
            addTask();
            break;

        case 2:
            showTask();
            break;
        case 3:
            searchTask();
            break;
        case 4:
            deleteTask();
            break;
        case 5:
            // Implement updateTask function
            break;

        default:
            break;
        }

    }

    return 0;

}
void banner() {
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t                       WELCOME TO Your ToDo List                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;

}

void addTask()
{
    system("cls");
    banner();
    todolist todo;
    cout << "Enter new Task" << endl;
    cin.ignore();  // Added this line to ignore the newline character in the buffer
    getline(cin, todo.task);
    char save;
    cout << "Save? (y/n):";
    cin >> save;
    if (save == 'y') {
        id++;
        ofstream fout;  // Corrected the ofstream declaration
        fout.open("todo.txt", ios::app);
        fout << "\n" << id;
        fout << "\n" << todo.task;
        fout.close();

        char more;
        cout << "Add more task?(y/n)";
        cin >> more;

        if (more == 'y') {
            addTask();
        }
        else {
            system("cls");
            cout << "Added successfully!" << endl;
            return;  // Corrected the return statement
        }

    }
    system("cls");

}
void showTask() { // Corrected the function name
    system("cls");
    banner();
    todolist todo;
    ifstream fin;
    fin.open("todo.txt");
    cout << "Task :" << endl;

    while (!fin.eof())
    {
        fin >> todo.id;
        fin.ignore();
        getline(fin, todo.task);
        if (todo.task != " ") {
            cout << "\t" << todo.id << ":" << todo.task << endl;

        }
        else {
            cout << "\tEmpty" << endl;
        }
    }

    fin.close();
    char exit;
    cout << "Exit? (y/n)";
    cin >> exit;
    if (exit != 'y') {
        showTask();
    }
    system("cls");

}

int searchTask() {
    system("cls"); // Added a semicolon
    banner();
    int id;
    cout << "Enter task id"; // Added a space after "Enter task id"
    cin >> id;
    todolist todo;
    ifstream fin("todo.txt"); // Added parentheses to the ifstream declaration
    while (!fin.eof())
    {
        fin >> todo.id;
        fin.ignore();
        getline(fin, todo.task);
        if (todo.id == id) {
            system("cls"); // Added a semicolon
            cout << "\t" << todo.id << ":" << todo.task << endl;
            return id; // Changed return statement to return id

        }


    }
    system("cls");
    cout << "Not found!" << endl;
    return 0;

}

void deleteTask() {
    system("cls");
    int id = searchTask();
    if (id != 0) {
        char del;
        cout << "\n\tDelete? (y/n):";
        cin >> del;
        if (del == 'y')
        {
            todolist todo;
            ofstream tempfile;
            tempfile.open("temp.txt");
            ifstream fin;
            fin.open("todo.txt");
            int index = 1;
            while (!fin.eof()) {
                fin >> todo.id;
                fin.ignore();
                getline(fin, todo.task);
                if (todo.id != id) // Changed the condition from !=
                {
                    tempfile << "\n" << index;
                    tempfile << "\n" << todo.task; // Changed from index
                    index++;
                }
            }

            fin.close();
            tempfile.close();
            remove("todo.txt");
            rename("temp.txt", "todo.txt");
            system("cls");
            cout << "\n\tDeleted successfully" << endl;
        }

        else {
            system("cls");
            cout << "Not deleted!" << endl;


        }
    }
}
