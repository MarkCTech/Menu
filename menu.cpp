#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

size_t get_input_int() {
    bool keep_going = true;
    size_t x{};

    cout << "Please enter a number: " << endl;
    while(keep_going == true)
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

float vec_sum_float(vector <int>& vec) {
    float vecsum {0};
    for (int num : vec)
        vecsum += float(num);
    return vecsum;
}

float vec_mean_float(vector <int> vec) {

    float vecsize{static_cast <float> (vec.size())};
    float vecsum{vec_sum_float(vec)};
    float mean = float(vecsum / vecsize);
    return mean;
}

int main() {

    vector <int> vec{};
    char selection{};
    size_t vecadd{};
    float vecmean{};

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
                vecadd = get_input_int();
                vec.push_back(vecadd);
                cout << vecadd << " added to vector!" << endl;
                break;
            case 'M':
            case 'm':
                vecmean = vec_mean_float(vec);
                cout << "Mean: " << vecmean << endl;
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