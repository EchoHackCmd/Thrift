#include "TestModule.h"
#include "../../../../Manager.h"
#include "../../../../../Client.h"

auto TestModule::onTick(void) -> void {

	//

};

auto TestModule::onEnable(void) -> void {

	Utils::debugOutput(this->name + " | " + (this->isEnabled ? "Enabled" : "Disabled"));

};

auto TestModule::onDisable(void) -> void {

	Utils::debugOutput(this->name + " | " + (this->isEnabled ? "Enabled" : "Disabled"));

};


auto TestModule::onRender(MinecraftUIRenderContext* ctx) -> void {

    auto text = std::string("Hello, World!");
    auto fontSize = 1.2f;

    auto textLen = ctx->getTextLen(nullptr, text, fontSize);

    auto textPos = Vec2<float>(12.f, 12.f);
    auto rectPos = Rect(textPos.x - 2.f, textPos.y - 2.f, (textPos.x + 2.f) + textLen, (textPos.y + 10.f) + 2.f);

    ctx->drawText(nullptr, textPos, text, Color(54.f, 117.f, 199.f, 1.f), fontSize);
    ctx->fillRectangle(rectPos, Color(21.f, 21.f, 21.f, 1.f));
    ctx->flushText(0.f);

};