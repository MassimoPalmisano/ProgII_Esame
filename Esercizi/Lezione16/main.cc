#include <iostream>
#include <fstream>

using namespace std;

int main(){

    //funzione di lettura del file
    ifstream fin("numeri.bin", ios::binary);
    
    int x;
    
    fin.read((char*)&x, sizeof(x));
    
    cout << x << endl;


    //funzione di scrittura sul file
    /*ofstream fout("nomefile.bin", ios::binary);
    
    int y = int;
    
    fout.write((char*)&x, sizeof(x));*/



    return 0;
}