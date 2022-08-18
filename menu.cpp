#include <iostream>
#include <vector>
#include <string>
using namespace std;

size_t getinputint() {
    bool keepGoing = true;
    size_t x{};

    cout << "Please enter a number: " << endl;
    while(keepGoing == true)
    {
        cin >> x;
        if( !cin)
            cout << "Oops, not a number!\n";
        else
            return x;
        cin.clear(); //clears error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n');//clears buffer
    }
    return 0;
    }

int main() {

    vector vec{10,20};
    char selection{};
    size_t toadd{};

    cout << "Welcome to the application!" << endl;
    do{
        cout << "\n---------------------" << endl;
        cout << "P - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "Q - Quit" << endl;
        cout << "\nEnter your choice: ";
        cin >> selection;
        cout << endl;

        switch (selection) {
            case 'P':
            case 'p':
                if (!vec.empty()){
                    for (auto elem: vec)
                        cout << elem << " ";
                }
                else 
                    cout << "[] - the list is empty";
                break;
            case 'A':
            case 'a':
                toadd = getinputint();
                vec.push_back(toadd);
                cout << toadd << " added to vector!" << endl;
                break;
            case 'M':
            case 'm':
                cout << "Calculates mean and displays" << endl;
                break;
            case 'S':
            case 's':
                cout << "Displays smallest int" << endl;
                break;
            case 'L':
            case 'l':
                cout << "Displays largest int" << endl;
                break;
            case 'Q':
            case 'q':
                cout << "Goodbye" << endl;
                break;
            default:
                cout << "Unknown selection, please try again" << endl;
                break;
        }


    }   while (selection != 'q' && selection != 'Q');
    cout << endl;

    return 0;
}