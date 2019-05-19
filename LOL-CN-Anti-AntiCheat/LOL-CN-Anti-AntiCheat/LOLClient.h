#pragma once
#include "framework.h"
class LOLClient
{
public:
	LOLClient();
	~LOLClient();
	//Ãû×Ö
	[[nodiscard]] auto GetGameLobbyName() const -> std::wstring;
	[[nodiscard]] auto GetGameMainName() const -> std::wstring;
	[[nodiscard]] auto GetLOLBaseName() const -> std::wstring;
	[[nodiscard]] auto GetTerSafeName() const -> std::wstring;
	[[nodiscard]] auto GetTenRpcsName() const -> std::wstring;
	[[nodiscard]] auto GetTenSlxName() const -> std::wstring;
	[[nodiscard]] auto GetTCJName() const -> std::wstring;
	[[nodiscard]] auto GetGameRpcsName() const -> std::wstring;
	[[nodiscard]] auto GetPolicyProbeName() const -> std::wstring;

	//µØÖ·
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
	//name
	const std::wstring _game_lobby_name;
	const std::wstring _game_main_name;
	const std::wstring _lol_base_name;
	const std::wstring _ter_safe_name;
	const std::wstring _ten_rpcs_name;
	const std::wstring _ten_slx_name;
	const std::wstring _tcj_name;
	const std::wstring _game_rpcs_name;
	const std::wstring _policy_probe_name;
	
private:

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





};

