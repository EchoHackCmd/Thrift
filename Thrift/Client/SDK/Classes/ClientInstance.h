#pragma once

#include "../../Utils/Utils.h"

#include "LoopbackPacketSender.h"
#include "MinecraftGame.h"

class ClientInstance {
public:
	BUILD_ACCESS(class LoopbackPacketSender*, LoopbackPacketSender, 0xE0);
	BUILD_ACCESS(class MinecraftGame*, MinecraftGame, 0xA8);
};