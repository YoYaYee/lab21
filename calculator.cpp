#include <windows.h>
#include <stdio.h>

HWND Textbox,button,Textbox1,Textbox2;
char i[20],j[20],resultStr[50];;

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		case WM_CREATE: {
		Textbox = CreateWindow("static","Please input two numbers",WS_VISIBLE | WS_CHILD,20,20,200,20,hwnd,NULL,NULL,NULL);
		Textbox1 = CreateWindow("edit","",WS_VISIBLE | WS_CHILD,65,50,115,20,hwnd,NULL,NULL,NULL);
		Textbox2 = CreateWindow("edit","",WS_VISIBLE | WS_CHILD,65,80,115,20,hwnd,NULL,NULL,NULL);
		button	= CreateWindow("Button","+",WS_VISIBLE | WS_CHILD,65,120,25,25,hwnd,(HMENU) 1,NULL,NULL);
		button	= CreateWindow("Button","-",WS_VISIBLE | WS_CHILD,95,120,25,25,hwnd,(HMENU) 2,NULL,NULL);
		button	= CreateWindow("Button","*",WS_VISIBLE | WS_CHILD,125,120,25,25,hwnd,(HMENU) 3,NULL,NULL);
		button	= CreateWindow("Button","/",WS_VISIBLE | WS_CHILD,155,120,25,25,hwnd,(HMENU) 4,NULL,NULL);
		break;
		}
		case WM_COMMAND:{
			switch(LOWORD(wParam)){
				case 1:
				case 2:
				case 3:
				case 4:
				
				float first,second,result;
				GetWindowText(Textbox1, i, sizeof(i));
				GetWindowText(Textbox2, j, sizeof(j));
				first = atof(i);
				second = atof(j);
				if(LOWORD(wParam) == 1)
				result = first + second;
				if(LOWORD(wParam) == 2)
				result = first - second;
				if(LOWORD(wParam) == 3)
				result = first * second;
				if(LOWORD(wParam) == 4){
					if(second == 0){
						MessageBox(hwnd, "Can't Identify", "Result", MB_OK | MB_ICONERROR);
						break;
					}
				result = first / second;
				}
				sprintf(resultStr, "%f", result);
				::MessageBox(hwnd,resultStr,"Result",MB_OK);
				break;
			}
		break;	
		}
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc;
	HWND hwnd;
	MSG msg;

	memset(&wc,0,sizeof(wc));
	wc.cbSize	 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc;
	wc.hInstance	 = hInstance;
	wc.hCursor	 = LoadCursor(NULL, IDC_ARROW);
	
	wc.hbrBackground = CreateSolidBrush(RGB(128, 0, 128));
	wc.lpszClassName = "WindowClass";
	wc.hIcon	 = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm	 = LoadIcon(NULL, IDI_APPLICATION);

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		"WindowClass",
		"My Calculator",
		WS_VISIBLE|WS_SYSMENU,
		640,
		433,
		250,
		200,
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	while(GetMessage(&msg, NULL, 0, 0) > 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
