#include "HookClientInstance.h"

#include "../../../Category/Module/Module.h"
#include "../../../Manager.h"

typedef void (__thiscall* RenderContext)(void*, MinecraftUIRenderContext*);
RenderContext _RenderContext;

Manager* rndrMgr = nullptr;

typedef __int64(__thiscall* RenderDrawText)(MinecraftUIRenderContext*, Font*, const float*, std::string*, const float*, float, unsigned int, const TextMeasureData*, const CaretMeasureData*);
RenderDrawText _RenderDrawText;

float rcolors[4];

auto RenderDrawTextCallback(MinecraftUIRenderContext* ctx, Font* font, const float* pos, std::string* text, const float* color, float alpha, unsigned int textAlignment, const TextMeasureData* textMeasureData, const CaretMeasureData* caretMeasureData) -> __int64 {

	if (rcolors[3] < 1) {

		rcolors[0] = 0.2f;
		rcolors[1] = 0.2f;
		rcolors[2] = 1.f;
		rcolors[3] = 1;

	};

	Utils::ApplyRainbow(rcolors, 0.0001f);
	color = rcolors;

	if (text->rfind("©Mojang AB") != std::string::npos)
		*text = std::string("Thrift Client");

	return _RenderDrawText(ctx, font, pos, text, color, alpha, textAlignment, textMeasureData, caretMeasureData);

};

auto RenderContextCallback(void* a1, MinecraftUIRenderContext* ctx) -> void {

	if (rndrMgr != nullptr) {

		if (_RenderDrawText == nullptr) {

			auto VTable = *(uintptr_t**)ctx;

			if (MH_CreateHook((void*)VTable[5], &RenderDrawTextCallback, reinterpret_cast<LPVOID*>(&_RenderDrawText)) != MH_OK) {
				
				Utils::debugOutput("[Render Draw Text] Failed to create hook!");
				_RenderDrawText = (RenderDrawText)Utils::getDll();

			}
			else {

				MH_EnableHook((void*)VTable[5]);
				Utils::debugOutput("[Render Draw Text] Successfully hooked!");

			};

		};

		for (auto category : rndrMgr->categories) {

			for (auto mod : category->modules) {

				if (mod->isEnabled)
					mod->onRender(ctx);

			};

		};

	};

	Minecraft::setClientInstance(ctx->clientInstance);

	_RenderContext(a1, ctx);

};

auto Hook_ClientInstance::init(void) -> StatusData {

	rndrMgr = this->mgr;
	auto sig = Utils::findSig("48 8B C4 48 89 58 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? 0F 29 70 ? 0F 29 78 ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 4C 8B ? 48 89 54 24 ? 4C");

	if (!sig)
		return StatusData(MethodStatus::Error, "[ClientInstance Hook] Failed to find Signature!");

	if(MH_CreateHook((void*)sig, &RenderContextCallback, reinterpret_cast<LPVOID*>(&_RenderContext)) != MH_OK)
		return StatusData(MethodStatus::Error, "[ClientInstance Hook] Failed to create hook!");

	if(MH_EnableHook((void*)sig) != MH_OK)
		return StatusData(MethodStatus::Error, "[ClientInstance Hook] Failed to enable hook!");
	
	
	return StatusData(MethodStatus::Success, "[ClientInstance Hook] Successfully hooked!");

};