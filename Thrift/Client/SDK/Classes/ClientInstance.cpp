#include "ClientInstance.h"

auto ClientInstance::getMcGame(void) -> MinecraftGame* {

	return *(MinecraftGame**)((unsigned __int64)(this) + 0xA8);

};