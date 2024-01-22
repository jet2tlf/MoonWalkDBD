#include <iostream>
#include <windows.h>

int main()
{
	int delay = 130;
	const int KEY_CODE_A = 0x41;  // ASCII for 'A'
	const int KEY_CODE_D = 0x44;  // ASCII for 'D'
	const int KEY_CHECK = 0x05;
	std::cout << "Moon Walk Code" << std::endl;
	std::cout << "Activation/Deactivation: mouse 4 (VK_XBUTTON1)" << std::endl;
	std::cout << "If you get turned becuse of ping you can increase/decrease keypress delay: END/INSERT " << std::endl;
	std::cout << "To set default deplay: mouse 3 (VK_MBUTTON)" << std::endl;

	while (true)
	{
		if (GetAsyncKeyState(KEY_CHECK))
		{
			keybd_event(KEY_CODE_A, 0, 0x0001, 0);
			Sleep(delay);
			keybd_event(KEY_CODE_A, 0, 0x0002, 0);
			Sleep(1);
			keybd_event(KEY_CODE_D, 0, 0x0001, 0);
			Sleep(delay);
			keybd_event(KEY_CODE_D, 0, 0x0002, 0);
		}

		if (GetAsyncKeyState(VK_END) & 1)
		{
			delay += 5;
			std::cout << "current delay is: " << delay << std::endl;
		}

		if (GetAsyncKeyState(VK_INSERT) & 1)
		{
			delay -= 5;
			std::cout << "current delay is: " << delay << std::endl;
		}
		if (GetAsyncKeyState(0x04) & 1)
		{
			delay = 130;
			std::cout << "delay set to deafult" << std::endl;
		}
	}
	return 0;
}
