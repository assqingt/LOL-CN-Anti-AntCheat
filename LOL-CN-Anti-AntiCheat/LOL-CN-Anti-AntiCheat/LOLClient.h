#pragma once
#include "framework.h"
class LOLClient
{
public:
	LOLClient();
	~LOLClient();

	//基本信息
	uintptr_t GetGameMainPid() const;
	fs::path GetGameMainFullPath();
	//名字
	[[nodiscard]] auto GetGameLobbyName() const -> std::wstring;
	[[nodiscard]] auto GetGameMainName() const -> std::wstring;
	[[nodiscard]] auto GetLOLBaseName() const -> std::wstring;
	[[nodiscard]] auto GetTerSafeName() const -> std::wstring;
	[[nodiscard]] auto GetTenRpcsName() const -> std::wstring;
	[[nodiscard]] auto GetTenSlxName() const -> std::wstring;
	[[nodiscard]] auto GetTCJName() const -> std::wstring;
	[[nodiscard]] auto GetGameRpcsName() const -> std::wstring;
	[[nodiscard]] auto GetPolicyProbeName() const -> std::wstring;

	//地址
	//LOLClient
	static auto GetGameLobbyBase() -> uintptr_t;
	[[nodiscard]] auto GetGameMainBase() const -> uintptr_t;

	//TP
	[[nodiscard]] auto GetLOLBase() const -> uintptr_t;
	[[nodiscard]] auto GetTerSafeBase() const -> uintptr_t;
	[[nodiscard]] auto GetTenRpcsBase() const -> uintptr_t;
	[[nodiscard]] auto GetTenSlxBase() const -> uintptr_t;
	[[nodiscard]] auto GetTCJBase() const -> uintptr_t;
	[[nodiscard]] auto GetGameRpcsBase() const -> uintptr_t;

	//HWID
	[[nodiscard]] auto GetPolicyProbeBase() const -> uintptr_t;
public:

private:
	void SetGameFullPath();
private:
	//Name
	const std::wstring _game_lobby_name_;
	const std::wstring _game_main_name_;
	const std::wstring _lol_base_name_;
	const std::wstring _ter_safe_name_;
	const std::wstring _ten_rpcs_name_;
	const std::wstring _ten_slx_name_;
	const std::wstring _tcj_name_;
	const std::wstring _game_rpcs_name_;
	const std::wstring _policy_probe_name_;

	//HMODULE
	uintptr_t _game_lobby_handle_;
	uintptr_t _game_main_handle_;
	uintptr_t _lol_base_handle_{};
	uintptr_t _ter_safe_handle_;
	uintptr_t _ten_rpcs_handle_;
	uintptr_t _ten_slx_handle_;
	uintptr_t _tcj_handle_;
	uintptr_t _game_rpcs_handle_;
	uintptr_t _policy_probe_handle_;

	//Basic Info
	fs::path _game_main_full_path_;
	uintptr_t _game_main_pid_;




};
extern LOLClient g_lol_client;

LOLClient& get_lol_client();

