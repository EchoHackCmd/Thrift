#pragma once

#include "../../Utils/Utils.h"

class Font;

class MinecraftGame {
public:
	BUILD_ACCESS(bool, canUseKeys, 0xB0);
	BUILD_ACCESS(Font*, mcfont, 0xE48);
};