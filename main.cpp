#include "Piece.h"

#define GD_COLS 16
#define GD_ROWS 24

LRESULT CALLBACK	WndProc	(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

void			EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC);
void			DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC);

int WINAPI WinMain (HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int iCmdShow){
	WNDCLASS			wc;
	HWND				hWnd;
	HDC 				hDC;
	HGLRC				hRC;
	MSG				msg;
	BOOL				bQuit	= false;
	
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon (NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor (NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH) GetStockObject (BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = "GLWindowClass";
	RegisterClass (&wc);
	
	hWnd = CreateWindowEx (WS_EX_TOPMOST, "GLWindowClass", "Modulation",  WS_POPUP | WS_VISIBLE, 0, 0, GetSystemMetrics(1)*(GD_COLS/(float)GD_ROWS), GetSystemMetrics(1), NULL, NULL, hInstance, NULL);
	
	EnableOpenGL (hWnd, &hDC, &hRC);
	
	while (!bQuit){
		if (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE)){
			if (msg.message == WM_QUIT)
				bQuit = true;
			else if (msg.message == WM_KEYUP)
				switch (msg.wParam){
					case VK_ESCAPE:
						bQuit = true;
						break;
				}
			else{
				TranslateMessage(&msg);
				DispatchMessage (&msg);
			}
		}else{
			glClearColor	(0.0f, 0.0f, 0.0f, 0.0f);
			glClear		(GL_COLOR_BUFFER_BIT);
			glPushMatrix	();
			glPopMatrix	();
			SwapBuffers	(hDC);
		}
	}
	DisableOpenGL (hWnd, hDC, hRC);
	DestroyWindow (hWnd);
	return msg.wParam;
}

LRESULT CALLBACK WndProc (HWND hWnd, UINT message,WPARAM wParam, LPARAM lParam){
	switch (message){
		case WM_CREATE:
			return 0;
		case WM_CLOSE:
			PostQuitMessage (0);
			return 0;
		case WM_DESTROY:
			return 0;
		default:
			return DefWindowProc (hWnd, message, wParam, lParam);
	}
}

void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC){
	PIXELFORMATDESCRIPTOR	pfd;
	int			iFormat;
	
	*hDC = GetDC (hWnd);
	
	ZeroMemory (&pfd, sizeof (pfd));
	
	pfd.nSize	= sizeof (pfd);
	pfd.nVersion	= 1;
	pfd.dwFlags	= PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL;
	pfd.iPixelType	= PFD_TYPE_RGBA;
	pfd.cColorBits	= 24;
	pfd.cDepthBits	= 16;
	pfd.iLayerType	= PFD_MAIN_PLANE;
	
	iFormat = ChoosePixelFormat (*hDC, &pfd);
	SetPixelFormat (*hDC, iFormat, &pfd);
	
	*hRC = wglCreateContext (*hDC);
	wglMakeCurrent (*hDC, *hRC);
	
	return;
}

void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC){
	wglMakeCurrent (NULL, NULL);
	wglDeleteContext (hRC);
	ReleaseDC (hWnd, hDC);
	return;
}
