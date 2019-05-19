#pragma once
class dll_module
{
public:
	dll_module();
	~dll_module();
	void attach();
	void detach();
};
extern dll_module g_dMod;

