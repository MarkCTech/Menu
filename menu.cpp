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
    for (auto num : vec)
        vecsum += float(num);
    return vecsum;
}

float vec_mean_float(vector <int> vec) {
    float vecsize{static_cast <float> (vec.size())};
    float vecsum{vec_sum_float(vec)};
    float mean = float(vecsum / vecsize);
    return mean;
}

int vec_min_int(vector <int> vec) {
    int vecmin = *min_element(vec.begin(),vec.end());
    return vecmin;
}

int vec_max_int(vector <int> vec) {
    int vecmax = *max_element(vec.begin(),vec.end());
    return vecmax;
}

int count_vec_int(vector <int> vec, int inputint) {
    int count{0};
    for (int num : vec)
        if (num == inputint)
            count++;
    return count;
}

bool are_you_sure() {
    char selection{};
    while (true) {
        cout << "Are you sure? Y/N:  ";
        cin >> selection;
        switch (selection){
            case 'Y':
            case 'y':
                return true;
            case 'N':
            case 'n':
                return false;
            default:
                cout << "Unknown selection, try again" << endl;
        }
    }
}

int main() {

    vector <int> vec{};
    char selection{};
    size_t inputint{};
    float vecmean{};
    int vecmin{};
    int vecmax{};
    int foundvec{};
    int count{};

    cout << "Welcome to The Application!" << endl;
    do {
        cout << "\n---------------------" << endl;
        cout << "P - Print Numbers" << endl;
        cout << "A - Add a Number" << endl;
        cout << "F - Find and Display a Number" << endl;
        cout << "M - Display Mean of the Numbers" << endl;
        cout << "S - Display the Smallest Number" << endl;
        cout << "L - Display the Largest Number" << endl;
        cout << "D - Delete All Values" << endl;
        cout << "Q - Quit" << endl;
        cout << "\nEnter Your Choice: ";
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
                inputint = get_input_int();
                vec.push_back(inputint);
                cout << inputint << " added to vector!" << endl;
                break;
            case 'F':
            case 'f':
                if (!vec.empty())
                    inputint = get_input_int();
                    if (find(vec.begin(), vec.end(), inputint) != vec.end())
                        count = count_vec_int(vec, inputint);
                    cout << "Number: " << inputint << "\nEntries: " << count;
                break;

            case 'M':
            case 'm':
                if (!vec.empty()) {
                    vecmean = vec_mean_float(vec);
                    cout << "Mean: " << vecmean << endl;
                }
                else
                    cout << "Unable to calculate the mean - no data"<< endl;
                break;
            case 'S':
            case 's':
                if (!vec.empty()) {
                    vecmin = vec_min_int(vec);
                    cout << "Smallest element in the vector is: " << vecmin << endl;
                }
                else
                    cout << "Unable to determine the smallest number - list is empty" <<  endl;
                break;
            case 'L':
            case 'l':
                if (!vec.empty()) {
                    vecmax = vec_max_int(vec);
                    cout << "Largest element in the vector is: " << vecmax << endl;
                }
                else
                    cout << "Unable to determine the largest number - list is empty" << endl;
                break;
            case 'D':
            case 'c':
                if (are_you_sure())
                    vec.clear();
                    cout << "\nAll values deleted" << endl;                
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