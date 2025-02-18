#include<iostream>
using namespace std;

int main(int argc, char* argv[]){
    float sum;
    for(int i; i < argc; i++){
        sum += atof(argv[i]);
    }
    if(argc <= 1)
    cout << "Please input numbers to find average." << endl;
    else {
    cout << "---------------------------------" << endl;
    cout << "Average of " << argc-1 << " numbers = " << sum/(argc-1) << endl;
    cout << "---------------------------------" << endl;
    }

}
