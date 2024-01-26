#include <iostream>
#include <Windows.h>
#define INPUT_COUNT 2
using namespace std;

void menu() {
    cout << "Simple AutoClicker |24Money| \n";
    cout << "Press Left Mouse To Interact! \n";
}
void clicker() {
    while (true) {
        int pressed = false;
        while ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0) {
            pressed = true;
            while (pressed == true){
                INPUT Input[INPUT_COUNT] = { 0,0 };
                Input[0].type = INPUT_MOUSE;
                Input[0].mi.dwFlags = MOUSEEVENTF_LEFTUP;
                Input[1].type = INPUT_MOUSE;
                Input[1].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
                SendInput(INPUT_COUNT, Input, sizeof(INPUT));
                pressed = false;
                Sleep(90); // Adjust click speed as needed

            }

        }
    }
}

int main() {
    menu();
    clicker();
    return 0;
}