// Chatty JAR Launcher
// Compile with "gcc start-chatty.c -o Chatty.exe -mwindows"
// NOTE: Replacing 'javaw' with 'java' will launch Chatty with
// a terminal window showing Chatty's console output..

#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Update the path below with the location of your JAR
    // NOTE: make sure you escape the backslashes and wrap the path in quotes
    char command[] = "javaw -jar \"C:\\Users\\p0wder\\Other\\Programs\\Folders\\Chatty\\bin\\Chatty.jar\"";

    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    // Initialize structures
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Start the child process hidden
    if (CreateProcess(
        NULL,           // No module name
        command,        // Command line
        NULL,           // Process handle not inheritable
        NULL,           // Thread handle not inheritable
        FALSE,          // Set handle inheritance to FALSE
        0,              // No creation flags
        NULL,           // Use parent's environment block
        NULL,           // Use parent's starting directory 
        &si,            // Pointer to STARTUPINFO structure
        &pi             // Pointer to PROCESS_INFORMATION structure
    )) {
        // Successfully launched, close handles to avoid memory leaks
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }

    return 0;
}
