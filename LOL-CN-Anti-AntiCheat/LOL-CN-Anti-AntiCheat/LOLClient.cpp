#include "LOLClient.h"

using encoder = encstr::cbc_t<encstr::ciphers::xor_cipher_t>;

LOLClient::LOLClient()	
	: _game_lobby_name(ENCRYPT_STRING_AUTO_W(encoder, L"LeagueClient.exe"))
	, _game_main_name(ENCRYPT_STRING_AUTO_W(encoder, L"League of Legends.exe"))
	, _ter_safe_name(ENCRYPT_STRING_AUTO_W(encoder, L"TerSafe.dll"))
	, _ten_rpcs_name(ENCRYPT_STRING_AUTO_W(encoder, L"TenRpcs.dll"))
	, _ten_slx_name(ENCRYPT_STRING_AUTO_W(encoder, L"TenSLX.dll"))
	, _tcj_name(ENCRYPT_STRING_AUTO_W(encoder, L"TCJ.dll"))
	, _game_rpcs_name(ENCRYPT_STRING_AUTO_W(encoder, L"GameRpcs.dll"))
	, _policy_probe_name(ENCRYPT_STRING_AUTO_W(encoder, L"PolicyProbe.dll"))
	,_game_lobby_handle_(static_cast<uintptr_t>(0))
	,_game_main_handle_(reinterpret_cast<uintptr_t>(GetModuleHandleW(_game_main_name.c_str())))
	,_lol_base_handle_(reinterpret_cast<uintptr_t>(GetModuleHandleW(_lol_base_name.c_str())))
	,_ter_safe_handle_(reinterpret_cast<uintptr_t>(GetModuleHandleW(_ter_safe_name.c_str())))
	,_ten_rpcs_handle_(reinterpret_cast<uintptr_t>(GetModuleHandleW(_ten_rpcs_name.c_str())))
	, _ten_slx_handle_(reinterpret_cast<uintptr_t>(GetModuleHandleW(_ten_slx_name.c_str())))
	,_tcj_handle_(reinterpret_cast<uintptr_t>(GetModuleHandleW(_tcj_name.c_str())))
	,_game_rpcs_handle_(reinterpret_cast<uintptr_t>(GetModuleHandleW(_game_rpcs_name.c_str())))
	,_policy_probe_handle_(reinterpret_cast<uintptr_t>(GetModuleHandleW(_policy_probe_name.c_str())))
{}


LOLClient::~LOLClient()
= default;

std::wstring LOLClient::GetGameLobbyName() const
{
	return _game_lobby_name;
}

std::wstring LOLClient::GetGameMainName() const
{
	return _game_main_name;
}

std::wstring LOLClient::GetLOLBaseName() const
{
	return _lol_base_name;
}

std::wstring LOLClient::GetTerSafeName() const
{
	return _ter_safe_name;
}

std::wstring LOLClient::GetTenRpcsName() const
{
	return _ten_rpcs_name;
}

std::wstring LOLClient::GetTenSlxName() const
{
	return _ten_slx_name;
}

std::wstring LOLClient::GetTCJName() const
{
	return _tcj_name;
}

std::wstring LOLClient::GetGameRpcsName() const
{
	return _game_rpcs_name;
}

std::wstring LOLClient::GetPolicyProbeName() const
{
	return _policy_probe_name;
}

//LeagueClient.exe 这个是exe是外部的，lol主程序内获取不到，需要由外部传入
uintptr_t LOLClient::GetGameLobbyBase()
{
	//return _game_lobby_handle_;
	return 0;
}
//League of Legends.exe
uintptr_t LOLClient::GetGameMainBase() const
{
	return _game_main_handle_;
}

//LOLBase.dll
uintptr_t LOLClient::GetLOLBase() const
{
	return _lol_base_handle_;
}

//TerSafe.dll
uintptr_t LOLClient::GetTerSafeBase() const
{
	return _ter_safe_handle_;
}
//TenRpcs.dll
uintptr_t LOLClient::GetTenRpcsBase() const
{
	return _ten_rpcs_handle_;
}
//TenSLX.dll
uintptr_t LOLClient::GetTenSlxBase() const
{
	return _ten_slx_handle_;
}
//TCJ.dll
uintptr_t LOLClient::GetTCJBase() const
{
	return _tcj_handle_;
}

//GameRpcs.dll
uintptr_t LOLClient::GetGameRpcsBase() const
{
	return _game_rpcs_handle_;
}

//PolicyProbe.dll
uintptr_t LOLClient::GetPolicyProbeBase() const
{
	return _policy_probe_handle_;
}
