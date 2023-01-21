//
// Created by ice on 2022/1/5.
//

#ifndef HONEYBADGER_ENTRYINTERFACE_H
#define HONEYBADGER_ENTRYINTERFACE_H

#include <string>
#include <map>
#include <vector>
#include "IHBApplicationInfo.h"
#include "IConfigManager.h"


using namespace std;

class ISimulateClass;
class SoLoader;
class LibAndroidRuntimeLoader;
class DynamicLibsBlock;
class HbEntry;
class IceMemory;
class ConfigManager;
class HBApplicationInfo;
class VA_Class;
class IClassManager;
class IceThreadPool;

namespace HB {
    class EntryInterface {
    public: // 伪装的数据
        virtual ~EntryInterface(){};
        virtual uint32_t GetJvmAddr() = 0;
        virtual uint32_t GetJniEnvAddr() = 0;
        virtual IceThreadPool *GetThreadPool() = 0;
        virtual SoLoader *GetRunTimeLoader() = 0;
        virtual DynamicLibsBlock *GetDynamicLibsBlock() = 0;
        virtual IClassManager *GetVaClassInst() = 0;

        virtual void PrintAllLibBaseAddr() = 0;
        virtual uint32_t Invoke_findSym(char* name, IceMemory* pMemory, bool bPrintLog = true) = 0;
        virtual void Invoke_InsertNativeFuncs(char *szClsName, char *szFuncName, char *szRetSig, uint32_t iFuncAddr) = 0;
        virtual SoLoader *SearchLoaderByAddr(uint32_t iAddr) = 0;
        virtual IConfigManager *GetConfigManager() = 0;
        virtual IHBApplicationInfo *GetHBApplicationInfo() = 0;

    public:
        virtual uint32_t InvokeGetNewClassId(string strClsSig) = 0;
        virtual uint32_t InvokeGetNewMethodId(string strClsSig) = 0;
        virtual uint32_t InvokeGetNewFieldId(string strClsSig) = 0;
        virtual string InvokeGetFieldSig(int iFieldID) = 0;
        virtual string InvokeGetMethodSig(int iMtdID) = 0;

        virtual uint32_t InvokeGetNewInstantID() = 0;
        virtual void InvokeInserNewInstance(ISimulateClass *pNew) = 0;

        virtual ISimulateClass *InvokeSearchClass_Inst(uint32_t iFieldName) = 0;
        virtual string InvokeGetAndroidId() = 0;
        virtual string InvokeGetAppLable(string strPkgName) = 0;
        virtual string InvokeGetAccountPtivateDir() = 0;
        virtual string InvokeGetBssid() = 0;
        virtual string InvokeGetSsid() = 0;
        virtual string InvokeGetSn() = 0;
        virtual string InvokeGetImei() = 0;
        virtual string InvokeGetImsi() = 0;
        virtual uint32_t InvokeGetSdkValue() = 0;
        virtual uint32_t InvokeForName(string strClsName) = 0;
        virtual string InvokeGetJavaVmVersion() = 0;

        virtual string GetEntryMark() = 0;

        virtual void OnResourcesGetAssets(uint32_t iAssetManID) = 0; // 调用 NdkAssetManagerForJavaObject

        virtual void ExecNativeCodeInThread(bool bWaitRunFinish, string strTagName, uint32_t iFuncAddr, HbEntry *pEntry, vector<uint32_t > vecPara, map<uint32_t , uint64_t> *pResultOut, bool bPrintInsn = false) = 0;

        virtual IceMemory *GetMemoryBlock() = 0;
        virtual IceMemory *GetStackBlock() = 0; // 获取堆栈的快

    public:
        // 添加断点
        virtual void AddBreakPoint(uint64_t iBpAddr, std::string strCommit) = 0;
        // 是否是单步模式  只标识步过  步入暂时按步过处理
        virtual bool IsStepOverMode() = 0;
        virtual void SetStepOverMode(bool bSet) = 0; // 设置是否是步过模式
    };
}

#endif //HONEYBADGER_ENTRYINTERFACE_H
