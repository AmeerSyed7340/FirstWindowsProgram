#ifndef UNICODE
#define UNICODE
#endif // !UNICODE

#include <windows.h>

LRESULT CALLBACK WinProc(HWND hwnd, UINT uMSG, WPARAM wParam, LPARAM lParam);


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE pInstance, PWSTR pCmdLine, int nCmdShow) {
	
	//Set the class name
	const wchar_t CLASS_NAME[] = L"Class Name";

	//0 or NULL initialize the window class
	WNDCLASS wc = {};

	//Set the window procedure function 
	wc.lpfnWndProc = WinProc;

	//set the handle instace
	wc.hInstance = hInstance;

	//Set the class name
	wc.lpszClassName = CLASS_NAME;

	//Register the window class 
	RegisterClass(&wc);

	//Create the window now
	HWND hwnd = CreateWindowEx(0, CLASS_NAME, L"Window Name", WS_BORDER, 0, 0, 200, 200, NULL, NULL, hInstance, NULL);

	//check if this window handle is created
	if (hwnd == NULL) {
		return 0;
	}


}

LRESULT CALLBACK WinProc(HWND hwnd, UINT uMSG, WPARAM wParam, LPARAM lParam) {
	
}