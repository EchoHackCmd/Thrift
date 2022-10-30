#include "TabGui.h"
#include "../../../../Manager.h"
#include "../../../../../Client.h"

auto TabGui::onRender(MinecraftUIRenderContext* ctx) -> void {

	auto logoTextColor = Color(52.f, 152.f, 235.f, this->alpha);
	auto logoBgColor = Color(69.f, 119.f, 204.f, (this->alpha > 0.2 > this->alpha ? this->alpha - .2 : this->alpha));

	auto textColor = Color(5.f, 97.f, 163.f, this->alpha);
	auto bgColor = Color(21.f, 21.f, 21.f, (this->alpha > 0.2 > this->alpha ? this->alpha - .2 : this->alpha));
	
	auto mgr = this->category->mgr;
	auto client = mgr->client;

	auto logoText = client->name;
	auto fontSize = 1.f;

	auto xStretch = ctx->getTextLen(nullptr, logoText, fontSize);

	for (auto category : mgr->categories) {

		auto name = category->name;
		auto currLen = ctx->getTextLen(nullptr, name, fontSize);

		if (currLen > xStretch)
			xStretch = currLen;

	};

	auto startPos = Vec2<float>(4.f, 4.f);
	auto logoRect = Rect(startPos.x - 2.f, startPos.y - 2.f, (startPos.x + 2.f) + xStretch, startPos.y + (fontSize * 10));

	ctx->drawText(nullptr, startPos, logoText, logoTextColor, fontSize);
	ctx->fillRectangle(logoRect, logoBgColor);
	ctx->flushText(0.f);


	auto I = 0;
	for (auto category : mgr->categories) {

		ctx->drawText(nullptr, Vec2<float>(startPos.x, startPos.y + (I * 10) + 10.f), category->name, textColor, fontSize);
		I++;

	};

	auto bgRect = Rect(logoRect.x, logoRect.w, logoRect.z, logoRect.w + (mgr->categories.size() * 10));
	
	ctx->fillRectangle(bgRect, bgColor);
	ctx->flushText(0.f);

};

auto TabGui::onKey(uint64_t key, bool isDown, bool* cancelSend) -> void {

	if (!isDown)
		return;

	if (key != VK_LEFT && key != VK_RIGHT && key != VK_UP && key != VK_DOWN)
		return;

	*cancelSend = true;

	auto mgr = this->category->mgr;
	auto category = mgr->categories.at(this->indexCat);
	auto mod = (category->modules.size() > 0 ? category->modules.at(this->indexMod) : nullptr);

	switch (key) {

		case VK_RIGHT:
			
			if (!this->selectedCat && !this->selectedMod)
				this->selectedCat = true;
			else
				if (!this->selectedMod)
					this->selectedMod = true;
				else {
					if (mod != nullptr)
						mod->isEnabled = !mod->isEnabled;
				};

		break;

		case VK_LEFT:

			if (this->selectedMod)
				this->selectedMod = false;

			else
				if (this->selectedCat)
					this->selectedCat = false;

		break;

	};

};