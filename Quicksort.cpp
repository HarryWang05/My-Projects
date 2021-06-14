//Author: Harry Wang
//Date: June 14, 2021
//Description: Same as Quicksort.py, but in c++

#include <iostream>
#include <vector>

using namespace std;

vector<int> quicksort(vector<int> data) {
    int pivot;
    int l = data.size();
    if(l <= 1) {
        return data;
    } else {
        pivot = data.back();
        data.pop_back();
    }
    vector<int> greater_vector;
    vector<int> lower_vector;
    for(int item : data) {
        if(item > pivot) {
            greater_vector.push_back(item);
        } else {
            lower_vector.push_back(item);
        }
    }
    vector<int> first_output = quicksort(lower_vector);
    vector<int> second_output = quicksort(greater_vector);
    vector<int> final_output;
    final_output.insert(final_output.begin(), first_output.begin(), first_output.end());
    final_output.push_back(pivot);
    final_output.insert(final_output.end(), second_output.begin(), second_output.end());
    return final_output;
}

int main () {
    int l;
    string s;
    vector<int> inputvector;
    cout << "Input list with integers, all elements seperated by a space" << endl;
    getline(cin,s);
    string delimiter = " ";
    int pos = 0;
    string token;
    //while loop is for spliting input by its spaces and turning it into a vector
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        inputvector.push_back(stoi(token));
        s.erase(0, pos + delimiter.length());
    }
    inputvector.push_back(stoi(s));
    vector<int> outputvector = quicksort(inputvector);
    for(int item : outputvector) {
        cout << item << " ";
    }
    return 0;
}