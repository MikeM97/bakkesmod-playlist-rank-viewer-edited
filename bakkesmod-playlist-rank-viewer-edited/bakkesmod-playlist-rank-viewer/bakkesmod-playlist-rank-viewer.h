#pragma once
#pragma comment( lib, "pluginsdk.lib" )
#include "bakkesmod/plugin/bakkesmodplugin.h"
#include <string>
#include <array>

using namespace std;

enum PLAYLIST {
	UNRANKED = 1,
	ONES = 10,
	TWOS = 11,
	THREES = 13,
	RUMBLE = 28,
	HOOPS = 27
};
map<PLAYLIST, string> playlistNames = {
	{UNRANKED, "Unranked"},
	{ONES,     "Solo       "},
	{TWOS,     "Doubles  "},
	{THREES,   "Standard"},
	{RUMBLE,   "Rumble   "},
	{HOOPS,    "Hoops    "}
};
array<PLAYLIST, 6> playlistsToCheck = { UNRANKED, ONES, TWOS, THREES, RUMBLE, HOOPS };

class PlaylistRankViewer : public BakkesMod::Plugin::BakkesModPlugin {
public:
	virtual void onLoad();
	virtual void onUnload();

	bool isEnabled();
	void setEnabled(bool enabled);

	void log(string str);
	void render(CanvasWrapper canvas);
	void updatePlayerMmr(SteamID id);
	void writeStats(CanvasWrapper& canvas, long long uniqueId, string playerName);
	void resetMmrCache();
	void timeoutCallback(GameWrapper* gw);

	map<long long, map<PLAYLIST, string>> playerMmrs = {};
	int currentPlayer = 0;
	shared_ptr<bool> enabled = make_shared<bool>(true);
};