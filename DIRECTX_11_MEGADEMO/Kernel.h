//#ifndef COMMON_H_
#include "common.h"
//#endif
#include "Renderer.h"
#include "Input.h"
class Kernel
{
public:
	Kernel(HINSTANCE hInst, int nCmdShow, int w = 640, int h = 480);
	//LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	Renderer *renderer;
	void Run();
	~Kernel();
	HWND hWnd;
private:
	HINSTANCE hInstance;
	Input input;
	static long int _stdcall WinMessage(HWND _window, unsigned int _message, WPARAM _wParam, LPARAM _lParam);
	long int Message(HWND _window, unsigned int _message, WPARAM _wParam, LPARAM _lParam);
};
