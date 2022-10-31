#include "ClientInstance.h"

auto ClientInstance::getLoopbackSender(void) -> LoopbackPacketSender* {

	return *(LoopbackPacketSender**)((unsigned __int64)(this) + 0xE0);

};

auto ClientInstance::getMcGame(void) -> MinecraftGame* {

	return *(MinecraftGame**)((unsigned __int64)(this) + 0xA8);

};