#pragma once
#include "framework.h"
#include <LOLClient.h>

class OffestManager
{
public:
	OffestManager();
	~OffestManager();


public:
	bool IsGameMainModified();

private:
	void SetUserGameVersion();
	auto GetCurrentGameVersion() const->std::wstring;
	auto GetUserGameVersion() const->std::wstring;

private:
	std::wstring _current_game_version_;
	std::wstring _user_game_version_;

};

