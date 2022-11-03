#pragma once

#include "../../Module.h"

class AirJump : public Module {
public:
	AirJump(Category* c) : Module(c, "AirJump") {
		
		//
	
	};
public:
	auto onTick(void) -> void override;
};