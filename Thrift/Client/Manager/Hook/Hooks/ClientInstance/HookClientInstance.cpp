#include "HookClientInstance.h"

#include "../../../Category/Module/Module.h"
#include "../../../Manager.h"

typedef void (__thiscall* RenderContext)(void*, MinecraftUIRenderContext*);
RenderContext _RenderContext;

Manager* rndrMgr = nullptr;

auto RenderContextCallback(void* a1, MinecraftUIRenderContext* ctx) -> void {

	if (rndrMgr != nullptr) {

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

	return StatusData(MethodStatus::Success, "[ClientInstance Hook] Successfully hooked Client Instance!");

};