#include <iostream>
#include <windows.h>
#include "Memory.hpp"

DWORD_PTR const addr = 0x0D922E2C;

int main()
{
	mem::Memory memObj;

	if (memObj.setHandleByPid(18992)) {
		std::cout << "value: " << memObj.read<int>(addr) << std::endl;
	} else {
		std::cerr << "error setting handle" << std::endl;
	}
    return 0;
}
