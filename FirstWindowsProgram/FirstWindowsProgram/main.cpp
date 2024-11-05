#ifndef UNICODE
#define UNICODE
#endif // !UNICODE

#include <windows.h>

LRESULT CALLBACK WindwProc(HWND hwnd, UINT uMSG, WPARAM wParam, LPARAM lParam);


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE pInstance, PWSTR pCmdLine, int nCmdShow) {
	
	//Set the class name
	const wchar_t CLASS_NAME[] = L"Class Name";

	//0 or NULL initialize the window class
	WNDCLASS wc = {};

	//Set the window procedure function 
	wc.lpfnWndProc = WindwProc;

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

	//make the window visibale. ie; show the window
	ShowWindow(hwnd, nCmdShow);


	//Events have to be responded to by GUI
	//These events that are either from users or the OS are stored
	//in a message queue.

	//Create the variable of type MSG to hold info of the event
	MSG msg = {};

	//GetMessage takes the first message from the head of the queue and stores it 
	//in the msg variable and
	//as long as there are messages in the queue this loop will run. The loop exists only to pull
	//the messages from the queue and dispatch them
	while (GetMessage(&msg, NULL, 0, 0) > 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

//Write the Window Procedure - a large switch case for the message code uMSG.
//This is called switch_on. So it switches on the message code.
LRESULT CALLBACK WindwProc(HWND hwnd, UINT uMSG, WPARAM wParam, LPARAM lParam) {
	switch (uMSG)
	{
	case WM_DESTROY: {
		PostQuitMessage(0);
		return 0;
	}
	case WM_PAINT: {
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);

		//All painting occurs here, between BeginPaint and EndPaint

		//
		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

		//A bool type
		EndPaint(hwnd, &ps);
	}
				 return 0;
	
	}
	return DefWindowProc(hwnd, uMSG, wParam, lParam);
}