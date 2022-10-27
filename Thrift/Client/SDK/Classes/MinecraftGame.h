#pragma once

class Font;

class MinecraftGame {
public:
	auto canUseKeys(void)->bool;
	auto mcFont(void)->Font*;
};