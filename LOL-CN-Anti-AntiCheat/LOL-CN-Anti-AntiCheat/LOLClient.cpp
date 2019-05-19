#include <LOLClient.h>
#include <utility/singleton.h>
#include <bee/utility/file_helper.h>
#include "bee/utility/path_helper.h"

using encoder = encstr::cbc_t<encstr::ciphers::xor_cipher_t>;

LOLClient::LOLClient()
	: _game_lobby_name_(ENCRYPT_STRING_AUTO_W(encoder, L"LeagueClient.exe"))
	, _game_main_name_(ENCRYPT_STRING_AUTO_W(encoder, L"League of Legends.exe"))
	, _ter_safe_name_(ENCRYPT_STRING_AUTO_W(encoder, L"TerSafe.dll"))
	, _ten_rpcs_name_(ENCRYPT_STRING_AUTO_W(encoder, L"TenRpcs.dll"))
	, _ten_slx_name_(ENCRYPT_STRING_AUTO_W(encoder, L"TenSLX.dll"))
	, _tcj_name_(ENCRYPT_STRING_AUTO_W(encoder, L"TCJ.dll"))
	, _game_rpcs_name_(ENCRYPT_STRING_AUTO_W(encoder, L"GameRpcs.dll"))
	, _policy_probe_name_(ENCRYPT_STRING_AUTO_W(encoder, L"PolicyProbe.dll"))

	, _game_lobby_handle_(static_cast<uintptr_t>(0))
	, _game_main_handle_(reinterpret_cast<uintptr_t>(GetModuleHandleW(_game_main_name_.c_str())))
	, _lol_base_handle_(reinterpret_cast<uintptr_t>(GetModuleHandleW(_lol_base_name_.c_str())))
	, _ter_safe_handle_(reinterpret_cast<uintptr_t>(GetModuleHandleW(_ter_safe_name_.c_str())))
	, _ten_rpcs_handle_(reinterpret_cast<uintptr_t>(GetModuleHandleW(_ten_rpcs_name_.c_str())))
	, _ten_slx_handle_(reinterpret_cast<uintptr_t>(GetModuleHandleW(_ten_slx_name_.c_str())))
	, _tcj_handle_(reinterpret_cast<uintptr_t>(GetModuleHandleW(_tcj_name_.c_str())))
	, _game_rpcs_handle_(reinterpret_cast<uintptr_t>(GetModuleHandleW(_game_rpcs_name_.c_str())))
	, _policy_probe_handle_(reinterpret_cast<uintptr_t>(GetModuleHandleW(_policy_probe_name_.c_str())))

	//Basic Info
	, _game_main_pid_(static_cast<uintptr_t>(GetCurrentProcessId()))
	//需要延时获取的初始化为空
	, _game_main_full_path_(L"")
{
	SetGameFullPath();
}


LOLClient::~LOLClient()
= default;

auto LOLClient::GetGameMainPid() const -> uintptr_t
{
	return _game_main_pid_;
}

auto LOLClient::GetGameMainFullPath() -> fs::path
{

	return std::move(_game_main_full_path_);
}

auto LOLClient::GetGameLobbyName() const -> std::wstring
{
	return _game_lobby_name_;
}

auto LOLClient::GetGameMainName() const -> std::wstring
{
	return _game_main_name_;
}

auto LOLClient::GetLOLBaseName() const -> std::wstring
{
	return _lol_base_name_;
}

auto LOLClient::GetTerSafeName() const -> std::wstring
{
	return _ter_safe_name_;
}

auto LOLClient::GetTenRpcsName() const -> std::wstring
{
	return _ten_rpcs_name_;
}

auto LOLClient::GetTenSlxName() const -> std::wstring
{
	return _ten_slx_name_;
}

auto LOLClient::GetTCJName() const -> std::wstring
{
	return _tcj_name_;
}

auto LOLClient::GetGameRpcsName() const -> std::wstring
{
	return _game_rpcs_name_;
}

auto LOLClient::GetPolicyProbeName() const -> std::wstring
{
	return _policy_probe_name_;
}

//LeagueClient.exe 这个是exe是外部的，lol主程序内获取不到，需要由外部传入
auto LOLClient::GetGameLobbyBase() -> uintptr_t
{
	//return _game_lobby_handle_;
	return 0;
}
//League of Legends.exe
auto LOLClient::GetGameMainBase() const -> uintptr_t
{
	return _game_main_handle_;
}

//LOLBase.dll
auto LOLClient::GetLOLBase() const -> uintptr_t
{
	return _lol_base_handle_;
}

//TerSafe.dll
auto LOLClient::GetTerSafeBase() const -> uintptr_t
{
	return _ter_safe_handle_;
}
//TenRpcs.dll
auto LOLClient::GetTenRpcsBase() const -> uintptr_t
{
	return _ten_rpcs_handle_;
}
//TenSLX.dll
auto LOLClient::GetTenSlxBase() const -> uintptr_t
{
	return _ten_slx_handle_;
}
//TCJ.dll
auto LOLClient::GetTCJBase() const -> uintptr_t
{
	return _tcj_handle_;
}

//GameRpcs.dll
auto LOLClient::GetGameRpcsBase() const -> uintptr_t
{
	return _game_rpcs_handle_;
}

//PolicyProbe.dll
auto LOLClient::GetPolicyProbeBase() const -> uintptr_t
{
	return _policy_probe_handle_;
}

void LOLClient::SetGameFullPath()
{
	//保护属性写入
	auto v_tmp_full_path = bee::path_helper::exe_path();	
	_game_main_full_path_ = v_tmp_full_path.value();
}

LOLClient& get_lol_client()
{
	return base::singleton_nonthreadsafe<LOLClient>::instance();
}
