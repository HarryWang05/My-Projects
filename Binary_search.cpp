//Author: Harry Wang
//Date: June 14, 2021
//Description: Same as Binary_search.py, but in c++

#include <iostream>
#include <vector>

using namespace std;

int binary_search(int search, vector<int> data) {
    int midpoint, midpoint_value;
    int begin_index = 0;
    int end_index = data.size()-1;
    while(begin_index <= end_index) {
        midpoint = (int) (end_index-begin_index)/2;
        midpoint += begin_index;
        midpoint_value = data.at(midpoint);
        if(midpoint_value == search) {
            return midpoint;
        } else if(midpoint_value < search) {
            //Beginning index is to the right of midpoint
            begin_index = midpoint+1;
        } else {
            //Ending index is to the left of midpoint
            end_index = midpoint-1;
        }
    }
    //Return -1 if search is not in list
    return -1;
}

int main () {
    int l, output;
    string s, token;
    vector<int> inputvector;
    cout << "Input sorted list with integers, from lowest to greatest, with the last element being the element to search for (the last element is not part of the list)" << endl;
    getline(cin,s);
    string delimiter = " ";
    int pos = 0;
    //while loop is for spliting input by its spaces and turning it into a vector
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        inputvector.push_back(stoi(token));
        s.erase(0, pos + delimiter.length());
    }
    output = binary_search(stoi(s),inputvector);
    cout << output;
    return 0;
}