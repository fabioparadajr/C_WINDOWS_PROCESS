#include <windows.h>
#include <stdio.h>
#include <tchar.h>

void _tmain( int argc, TCHAR *argv[] )
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    
    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );

    // Create a process(my other program). 
    if( !CreateProcess( TEXT("opexnandexec.exe"),   // No module name (use command line)
        NULL,        // Command line
        NULL,           // Process handle not inheritable
        NULL,           // Thread handle not inheritable
        FALSE,          // Set handle inheritance to FALSE
        0,              // No creation flags
        NULL,           // Use parent's environment block
        NULL,           // Use parent's starting directory 
        &si,            // Pointer to STARTUPINFO structure
        &pi )           // Pointer to PROCESS_INFORMATION structure
    ) 
    
    // If is FALSE, than i send this messagebox
    {
 int FailedBox = MessageBox(
        NULL,
        "Create process failed",
        "So...",
        MB_ICONWARNING | MB_DEFBUTTON2
    );
  
  // Here i'm just messing around with return of the function
 // In this case, will return "IDOK", means that you click "OK"
  if (FailedBox == IDOK){
  int msgbox = MessageBox(
        NULL,
        "WHY DID YOU CLICK OK?",
        "So...",
        MB_ICONASTERISK | MB_DEFBUTTON2
    );
    return msgbox;
    };

    }
   
    
   int SucessBox = MessageBox(
        NULL,
        "Process Created",
        "Good News!!",
        MB_OK
    );
        return SucessBox;
 


    // Wait until child process exits.
    WaitForSingleObject( pi.hProcess, INFINITE );

    // Close process and thread handles. 
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );
}