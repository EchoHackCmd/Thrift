#pragma once

#include "../../Module.h"

class TestModule : public Module {
public:
	TestModule(Category* c) : Module(c, "Test Module") {

		this->isEnabled = true;

	};
public:
	auto onTick(void) -> void override;
	auto onEnable(void) -> void override;
	auto onDisable(void) -> void override;
public:
	auto onRender(MinecraftUIRenderContext*) -> void override;
};