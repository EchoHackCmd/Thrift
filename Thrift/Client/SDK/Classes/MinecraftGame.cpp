#include "MinecraftGame.h"

auto MinecraftGame::canUseKeys(void) -> bool {

	return *(bool*)((unsigned __int64)(this) + 0xD8);

};

auto MinecraftGame::mcFont(void) -> Font* {

	return *(Font**)((unsigned __int64)(this) + 0xE58);

};