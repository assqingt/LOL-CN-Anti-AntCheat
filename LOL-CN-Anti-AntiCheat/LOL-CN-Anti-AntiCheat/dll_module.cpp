#include "framework.h"
#include <dll_module.h>
#include <LOLClient.h>

using encoder = encstr::cbc_t<encstr::ciphers::xor_cipher_t>;
LOLClient g_lol_client;

dll_module::dll_module()
= default;


dll_module::~dll_module()
= default;

void dll_module::attach()
{
	const auto v_str_cmdline = std::wstring(GetCommandLineW());
	if (v_str_cmdline.find(g_lol_client.GetGameMainName()) == std::wstring::npos)
	{
		detach();
	}
}

void dll_module::detach()
{
}
