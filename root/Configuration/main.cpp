#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <time.h>

using namespace std;

void Stealth()
{
 HWND Stealth;
 AllocConsole();
 Stealth = FindWindowA("ConsoleWindowClass", NULL);
 ShowWindow(Stealth,0);
}

int main() {
	Stealth();
	ofstream HALpointer;
	HALpointer.open("HALpointer.bat");
	HALpointer << "@echo off\nstart C:\\Program Files\\HAL.exe\nexit";
	HALpointer.close();
	return(0);
}
