#pragma once

namespace mem {

class Memory {

public:

	Memory()
		: _hProcess(nullptr)
	{
	}

	~Memory()
	{
	}

	void setHandle(HANDLE const hProcess)
	{
		this->_hProcess = hProcess;
	}

	bool setHandleByPid(DWORD const pid)
	{
		bool eval = false;

		this->_hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
		if (this->_hProcess) {
			eval = true;
		}
		return eval;
	}

	template <class T>
	T read(DWORD_PTR addr)
	{
    	T buffer;
    	ReadProcessMemory(
			this->_hProcess, (LPCVOID)addr, &buffer, sizeof(buffer), nullptr
		);
    	return buffer;
	}

	template <class T>
	T write(DWORD_PTR addr, T buffer)
	{
		bool eval = WriteProcessMemory(
			this->_hProcess, (LPVOID)addr, &buffer, sizeof(buffer), nullptr
		);

		return eval;
	}

private:
	HANDLE _hProcess;

};

}
