#pragma once

#include "../../Module.h"

class TabGui : public Module {
public:
	TabGui(Category* c) : Module(c, "TabGui") {

		this->isEnabled = true;
		this->key = VK_TAB;

	};
public:
	auto onRender(MinecraftUIRenderContext*) -> void override;
	auto onKey(uint64_t, bool, bool*) -> void override;
private:
	float alpha = 1.f;
private:
	int indexCat = 0, indexMod = 0;
	bool selectedCat = false, selectedMod = false;
};