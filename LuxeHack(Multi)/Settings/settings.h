#pragma once
#include <unordered_map>
#include "../Json/json.h"

namespace Settings
{
	namespace Weapone
	{
		extern bool norecoil;
		extern bool nospread;
		extern bool noshoters;
		extern bool nosway;
	}

	namespace Player
	{
		extern bool longslide;
		extern bool rotateshl;
		extern bool afk;
		extern bool autoshoot;
	}

	namespace Aimbot
	{
		extern bool enabled;
		extern bool turets;
		extern bool capslock;
		extern int bones;
	}

	namespace ESP
	{
		extern bool EspSilhouettes;
		extern bool EspMines;
	}
}



