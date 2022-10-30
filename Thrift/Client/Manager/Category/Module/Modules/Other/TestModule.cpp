#include "TestModule.h"
#include "../../../../Manager.h"
#include "../../../../../Client.h"

auto TestModule::onTick(void) -> void {

    /* Execute Every Thread Tick */

};

auto TestModule::onEnable(void) -> void {

	/* Execute Upon Enable */

    this->category->mgr->isRunning = false; /* Uninject DLL */

};

auto TestModule::onDisable(void) -> void {

    /* Execute Upon Disable */

};


auto TestModule::onRender(MinecraftUIRenderContext* ctx) -> void {

    /* Execute Every MinecraftUIRenderContext Tick */

};

auto TestModule::onKey(uint64_t key, bool isDown, bool* cancelSend) -> void {

    /* Execute Upon Keyboard Press */

};