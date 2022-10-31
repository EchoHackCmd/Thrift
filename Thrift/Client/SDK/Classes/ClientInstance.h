#pragma once

#include "LoopbackPacketSender.h"
#include "MinecraftGame.h"

class ClientInstance {
public:
	auto getLoopbackSender(void)->LoopbackPacketSender*;
	auto getMcGame(void)->MinecraftGame*;
};