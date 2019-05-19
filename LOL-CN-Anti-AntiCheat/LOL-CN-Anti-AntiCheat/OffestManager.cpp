#include <OffestManager.h>
#include <bee/utility/module_version_win.h>


using encoder = encstr::cbc_t<encstr::ciphers::xor_cipher_t>;


OffestManager::OffestManager()
	:_current_game_version_(ENCRYPT_STRING_AUTO_W(encoder, L"9.10.273.9316"))
	, _user_game_version_(L"")
{}


OffestManager::~OffestManager()
= default;

bool OffestManager::IsGameMainModified()
{
	return GetCurrentGameVersion() == GetUserGameVersion();
}

auto OffestManager::GetCurrentGameVersion() const -> std::wstring
{
	return _current_game_version_;
}

auto OffestManager::GetUserGameVersion() const -> std::wstring
{
	
	return _user_game_version_;
}

void OffestManager::SetUserGameVersion()
{
	auto& v_lol_client = get_lol_client();
	const auto v_tmp_version = bee::module_version(v_lol_client.GetGameMainFullPath().wstring().c_str());
	const auto v_n_major_version = HIWORD(v_tmp_version.fixed_file_info()->dwFileVersionMS);
	const auto v_n_minor_version = LOWORD(v_tmp_version.fixed_file_info()->dwFileVersionMS);
	const auto v_n_build_version = HIWORD(v_tmp_version.fixed_file_info()->dwFileVersionLS);
	const auto v_n_revi_version = LOWORD(v_tmp_version.fixed_file_info()->dwFileVersionLS);
	
	_user_game_version_ =
		std::to_wstring(v_n_major_version) + \
		L"." + \
		std::to_wstring(v_n_minor_version) + \
		L"." + \
		std::to_wstring(v_n_build_version) + \
		L"." + \
		std::to_wstring(v_n_revi_version);

}
