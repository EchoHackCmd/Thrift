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

	this->category->mgr->isRunning = false;

};


auto TestModule::onRender(MinecraftUIRenderContext* ctx) -> void {

	auto mgr = this->category->mgr;

	auto alpha = 1.f;
	auto textColor = Color(52.f, 152.f, 235.f, alpha);
	auto bgColor = Color(21.f, 21.f, 21.f, (alpha > 0.2 ? alpha - 0.2 : alpha));
	auto lBgColor = Color(69.f, 119.f, 204.f, (alpha > 0.2 ? alpha - 0.2 : alpha));
	
	auto logoText = std::string(mgr->client->name);
	auto startPos = Vec2<float>(2.f, 2.f);
	auto fontSize = .8f;

	auto xStretch = ctx->getTextLen(nullptr, logoText, fontSize);

	/* Calculate Category String Lengths */
	
	for (auto category : mgr->categories) {

		auto name = category->name;
		auto len = ctx->getTextLen(nullptr, name, fontSize);

		if (len > xStretch) xStretch = len;

	};

	/* Render Logo */

	auto rectA = Rect(startPos.x - 1.f, startPos.y - 1.f, startPos.x + (xStretch + 1.f), startPos.y + (fontSize * 10));
	
	ctx->drawText(nullptr, startPos, logoText, textColor, fontSize);
	ctx->fillRectangle(Rect(rectA.x, rectA.y, rectA.z, rectA.w + (mgr->categories.size() * 10)), bgColor);
	ctx->fillRectangle(rectA, lBgColor);

	/* Render Category Strings */

	auto I = 1;
	for (auto category : mgr->categories) {

		ctx->drawText(nullptr, Vec2<float>(rectA.x + 1.f, (rectA.y + 1.f) + (I * 10)), category->name, textColor, fontSize);
		I++;

	};

	ctx->flushText(0.f);

};