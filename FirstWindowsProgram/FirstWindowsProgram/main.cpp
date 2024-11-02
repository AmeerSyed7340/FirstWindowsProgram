#ifndef UNICODE
#define UNICODE
#endif // !UNICODE

#include <windows.h>

//forward decalaration for the long point window procedure function
LRESULT CALLBACK WiNDPROC(HWND hwnd, UINT uint, WPARAM wparam, LPARAM lparam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE pInstance, PWSTR pCmdLine , int nCmdShow) {

	//Register the window class
	const wchar_t CLASS_NAME[] = L"This window name is prepended with an L";

	//create a window class object
	WNDCLASS wc = {};

	//long pointer window procesdure function (fn). bc this takes a function
	wc.lpfnWndProc = WiNDPROC;

	//handle isntance
	wc.hInstance = hInstance;

	//long pointer to string zeroed out-adds a null character at the end of the string
	wc.lpszClassName = CLASS_NAME;

	//Lets add a handle background color
	wc.hbrBackground; //Give it a little bit of personality

	RegisterClass(&wc);

	return 0;
}//wWinMain

LRESULT CALLBACK WiNDPROC(HWND hwnd, UINT uint, WPARAM wparam, LPARAM lparam) {

}
