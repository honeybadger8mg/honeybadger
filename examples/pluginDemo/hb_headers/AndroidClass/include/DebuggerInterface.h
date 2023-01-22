//
// Created by ice on 2022/1/5.
//

#ifndef HONEYBADGER_DEBUGGERINTERFACE_H
#define HONEYBADGER_DEBUGGERINTERFACE_H

#include <string>
#include <IceRegister.h>

using namespace std;

class HBPropInfoManager;

namespace HB {
    class EntryInterface;
}

class DebuggerInterface {
public:
    virtual uint32_t ReadJniFuncPara(int iParaIndex) = 0;
    virtual RegValue ReadRegValueDirect(int acName) = 0;
    virtual RegValue ReadRegValueDirect(void *opArg) = 0;
    virtual uint8_t *ConvertVirtualAddress2Buf(uint32_t iVtAddr) = 0;
    virtual uint8_t *ConvertVirtualAddress2Buf(RegValue regValue) = 0;

    virtual HBPropInfoManager *GetPropInfoManager() = 0;

    virtual HB::EntryInterface* GetEntryInterface() = 0;
};

#endif //HONEYBADGER_DEBUGGERINTERFACE_H
