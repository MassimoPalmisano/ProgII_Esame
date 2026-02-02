#include <iostream>
#include <string>
using namespace std;

void reversei(int *r, const int *values, unsigned size);
/// @brief 
/// @param r 
/// @param s 
void reverses(string &r, const string &s);


int main(){

    string s, r;

    cout << "inserire la parola da invertire" << endl;
    cin >> s;

    reverses(r, s);

    cout << "la parola invertita è: " << r << endl;
      

    return 0;
}

void reversei(int *r, const int *values, unsigned size){

    unsigned i, j = size - 1;

    for(i = 0; i< size; i++){
        r[j] = values[i];
        j--;
    }
}
void reverses(string &r, const string &s){

    r = "";  // svuoto la stringa di output

    for (int i = s.length() - 1; i >= 0; i--) {
        r += s[i];
    }
}