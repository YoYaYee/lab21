#include<iostream>
using namespace std;

int main(int argc, char* argv[]){
    float avg;
    float a[argc] = {};
    for(int i; i < argc; i++){
        a[i] = atof(argv[i]);
    }
    for(int j; j < argc; j++){
        avg += a[j];
    }
    if(argc <= 1)
    cout << "Please input numbers to find average." << endl;
    else {
    cout << "---------------------------------" << endl;
    cout << "Average of " << argc-1 << " numbers = " << avg/(argc-1) << endl;
    cout << "---------------------------------" << endl;
    }

}
