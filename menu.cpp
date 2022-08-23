#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

void display_menu();
void get_selection(char& selection);
void case_p (const vector <int>& vec) ;
void case_a (vector <int>& vec);
void case_f (const vector <int>& vec);
void case_m (const vector <int>& vec, double& vecmean);
void case_s (const vector <int>& vec, double& vecmin);
void case_l (const vector <int>& vec, double& vecmax);
void case_d (vector <int>& vec);

void get_mean_double(const vector <int>, double& vecmean, double vecsum, double vecsize);

double get_sum_double(const vector <int> vec);
double get_size_double(const vector <int> vec);
int get_min_int(const vector <int>);
int get_max_int(const vector <int>);
int count_vec_int(const vector <int> vec, int);

int get_input_int();
bool are_you_sure();

int main() {

    vector <int> vec{};
    char selection{};

    double vecmean{};
    double vecmin{};
    double vecmax{};

    cout << "Welcome to The Application!" << endl;
    do {
        display_menu();
        get_selection(selection);
        selection = toupper(selection);
        switch (selection) {
            case 'P':
                case_p(vec);
                break;
            case 'A':
                case_a(vec);
                break;
            case 'F':
                case_f (vec);
                break;
            case 'M':
                case_m (vec, vecmean);
                break;
            case 'S':
                case_s (vec, vecmin);
                break;
            case 'L':
                case_l (vec, vecmax);
                break;
            case 'D':
                case_d (vec);            
                break;
            case 'Q':
                cout << "Goodbye" << endl;
                break;
            default:
                cout << "Unknown selection, please try again" << endl;
                break;
        }
    }   while (selection != 'Q');
    cout << endl;

    return 0;
}

void display_menu() {
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
}

void get_selection (char& selection) {
    cin >> selection;
    cout << endl;
    toupper(selection);
}

void case_p (const vector <int>& vec) {
    if (!vec.empty())
        for (auto elem: vec)
            cout << elem << " ";
    else 
        cout << "[] - the vector is empty";
}

void case_a (vector <int>& vec) {
    int inputint{};
    inputint = get_input_int();
    vec.push_back(inputint);
    cout << inputint << " added to vector!" << endl;
}

void case_f (const vector <int>& vec) {
    int count{};
    if (!vec.empty()) {
        int inputint = get_input_int();
        if (find(vec.begin(), vec.end(), inputint) != vec.end())
            count = count_vec_int(vec, inputint);
        cout << "Number: " << inputint << "\nEntries: " << count;
    }
    else
        cout << "Vector is empty" << endl;
}

void case_m (const vector <int>& vec, double& vecmean) {
    double vecsize{};
    double vecsum{};
    vecsize = get_size_double(vec);
    vecsum = get_sum_double(vec);
    if (!vec.empty()) {
        get_mean_double(vec, vecmean, vecsum, vecsize);
        cout << "Mean: " << vecmean << endl;
    }
    else
        cout << "Unable to calculate the mean - no data"<< endl;
}

void case_s (const vector <int>& vec, double& vecmin) {
    if (!vec.empty()) {
        vecmin = get_min_int(vec);
     cout << "Smallest element in the vector is: " << vecmin << endl;
    }
    else
        cout << "Unable to determine the smallest number - list is empty" <<  endl;
}

void case_l (const vector <int>& vec, double& vecmax) {
    if (!vec.empty()) {
        vecmax = get_max_int(vec);
        cout << "Largest element in the vector is: " << vecmax << endl;
    }
    else
        cout << "Unable to determine the largest number - list is empty" << endl;
}
void case_d (vector <int>& vec) {
    if (are_you_sure())
        vec.clear();
        cout << "\nAll values deleted" << endl;
}

int get_input_int() {
    bool keep_going = true;
    int x{};

    cout << "Please enter a number: " << endl;
    while(keep_going) {
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

void get_mean_double(const vector <int> vec, double& vecmean, double vecsum, double vecsize) {
    vecmean = double(vecsum / vecsize);
}

double get_size_double(const vector <int> vec) {
    double vecsize{};
    vecsize = static_cast <double> (vec.size());
    return vecsize;
}

double get_sum_double(const vector <int> vec) {
    double vecsum{};
    for (auto num : vec)
        vecsum += double(num);
    return vecsum;
}

int get_min_int(const vector <int> vec) {
    int vecmin = *min_element(vec.begin(),vec.end());
    return vecmin;
}

int get_max_int(const vector <int> vec) {
    int vecmax = *max_element(vec.begin(),vec.end());
    return vecmax;
}

int count_vec_int(const vector <int> vec, int inputint) {
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