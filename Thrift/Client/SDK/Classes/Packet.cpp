#include "Packet.h"

template<typename P>
auto Packet::setVTable(uintptr_t sig) -> void {
    
    if (sig == NULL)
        return;

    memset(this, 0, sizeof(P));
    int offset = *(int*)(sig + 3);
    this->VTable = (uintptr_t**)(sig + offset + 7);

};

TextPacket::TextPacket(void) {

    static auto sig = (uintptr_t)NULL;

    if (!sig)
        sig = Utils::findSig("48 8D 05 ? ? ? ? 48 89 45 ? C6 45 ? ? 48 89 7D ? 48 89 7D");

    this->setVTable<TextPacket>(sig);

};