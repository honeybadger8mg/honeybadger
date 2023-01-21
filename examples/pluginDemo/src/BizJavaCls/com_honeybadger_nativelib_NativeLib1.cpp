//
// Created by ice on 8/19/20.
//

#include "com_honeybadger_nativelib_NativeLib1.h"
#include "CPublicUtil.h"
#include "IClassManager.h"
#include "java_lang_String.h"
#include "IceAssert.h"
#include "ARM.h"
#include "IceMath.h"
#include "CommToolsHeader.h"
#include "EntryInterface.h"

com_honeybadger_nativelib_NativeLib1::com_honeybadger_nativelib_NativeLib1(HB::EntryInterface *pDebugger) {
    m_pEntry = pDebugger;
    m_strClsssSig = "com/honeybadger/nativelib/NativeLib1";

    m_iClassId = m_pEntry->InvokeGetNewClassId(m_strClsssSig);
    m_iInstaceID = m_pEntry->InvokeGetNewInstantID();

    InsertMethodId("DoTest1(Ljava/lang/String;)Ljava/lang/String;");
    InsertMethodId("DoTest2(I)I");
    for (unordered_map<string, UINT>::iterator itLoop = m_mapMethodSig_Id.begin();
         itLoop != m_mapMethodSig_Id.end(); ++itLoop) {
        m_mapMethodID_Sig.insert(make_pair(itLoop->second, itLoop->first));
    }

    InsertFieldId("");
    m_pEntry->InvokeInserNewInstance(this);
}

UINT com_honeybadger_nativelib_NativeLib1::GetClassID() {
    return m_iClassId;
}

string com_honeybadger_nativelib_NativeLib1::GetClassSig() {
    return m_strClsssSig;
}

UINT com_honeybadger_nativelib_NativeLib1::GetMethodID(string strMethodSig) {
    if (m_mapMethodSig_Id.find(strMethodSig) != m_mapMethodSig_Id.end()) {
        return m_mapMethodSig_Id[strMethodSig];
    }
    return ISimulateClass::GetMethodID(strMethodSig);
}

void com_honeybadger_nativelib_NativeLib1::InsertMethodId(string strMethodSig) {
    if (strMethodSig.empty()) {
        return ;
    }
    if (m_mapMethodSig_Id.find(strMethodSig) == m_mapMethodSig_Id.end()) {
        m_mapMethodSig_Id.insert(
                make_pair(strMethodSig, m_pEntry->InvokeGetNewMethodId(m_strClsssSig + ";->" + strMethodSig)));
    }
}

UINT com_honeybadger_nativelib_NativeLib1::CallStaticObjectMethodV(void *pHbThis, UINT iMtdID) {
    if (m_mapMethodID_Sig.find(iMtdID) != m_mapMethodID_Sig.end()) {
        string strMtdSig = m_mapMethodID_Sig[iMtdID];
        DebuggerInterface *pDebugger = (DebuggerInterface*)pHbThis;
        if (strMtdSig == "DoTest1(Ljava/lang/String;)Ljava/lang/String;") {
            java_lang_String *pjbPara = new java_lang_String(m_pEntry);
            pjbPara->SetContent("testdata");
            return pjbPara->GetInstanceID();
        } else {
            assert(false);
        }
    } else {
        assert(false);
    }
    return 0;
}

void com_honeybadger_nativelib_NativeLib1::SetInstanceID(UINT iID) {
    m_iInstaceID = iID;
    return;
}

UINT com_honeybadger_nativelib_NativeLib1::GetInstanceID() {
    return m_iInstaceID;
}

string com_honeybadger_nativelib_NativeLib1::SearchMethodName(int iMtdID) {
    return m_mapMethodID_Sig[iMtdID];
}

bool com_honeybadger_nativelib_NativeLib1::IsArray() {
    return false;
}

int com_honeybadger_nativelib_NativeLib1::GetArrayCount() {
    return 0;
}

UINT com_honeybadger_nativelib_NativeLib1::GetObjectArrayElement(int iIndex) {
    return 0;
}

UINT com_honeybadger_nativelib_NativeLib1::GetFieldID(string strFieldSig) {
    if (m_mapFieldSig_Id.find(strFieldSig) != m_mapFieldSig_Id.end()) {
        return m_mapFieldSig_Id[strFieldSig];
    }
    return 0;
}

void com_honeybadger_nativelib_NativeLib1::InsertFieldId(string strFieldSig) {
    if (strFieldSig.empty()) {
        return ;
    }
    if (m_mapFieldSig_Id.find(strFieldSig) == m_mapFieldSig_Id.end()) {
        m_mapFieldSig_Id.insert(
                make_pair(strFieldSig, m_pEntry->InvokeGetNewFieldId(m_strClsssSig + ";->" + strFieldSig)));
    }
}

UINT com_honeybadger_nativelib_NativeLib1::GetFieldValue(int iFieldID) {
    string strFieldName = m_pEntry->InvokeGetFieldSig(iFieldID);

    if (strFieldName == "") {
        return 0;
    } else {
        assert(false);
        return 0;
    }
}

UINT com_honeybadger_nativelib_NativeLib1::ExecNewObject(void *pDebugger, UINT iMtdID) {
    assert(false);
    return 0;
}

UINT com_honeybadger_nativelib_NativeLib1::OnInvoke(void *pHbThis, void *pInvokeMethodInst) {
    assert(false);
    return 0;
}

UINT com_honeybadger_nativelib_NativeLib1::OnGet(void *pHbThis, void *pFieldInstPara) {
    assert(false);
    return 0;
}

void com_honeybadger_nativelib_NativeLib1::FreeSelf() {
    delete this;
}

HB::EntryInterface *com_honeybadger_nativelib_NativeLib1::GetEntry() {
    return m_pEntry;
}

UINT com_honeybadger_nativelib_NativeLib1::CallObjectMethod(void *pHbThis, UINT iMtdID) {
    if (m_mapMethodID_Sig.find(iMtdID) != m_mapMethodID_Sig.end()) {
        string strMtdSig = m_mapMethodID_Sig[iMtdID];
        DebuggerInterface *pDebugger = (DebuggerInterface*)pHbThis;
        if (strMtdSig == "OnTestCallObjectMethod(II)Ljava/lang/String;") {
            CTLOG("补充实现 OnTestCallObjectMethod");
//            int iPara1 = pDebugger->ReadRegValueDirect(ARM_REG_R3).value32;
//            int iPara2 = pDebugger->ReadSPParaValue(4);
//            LOGI("参数1: %d  参数2: %d", iPara1, iPara2);

            java_lang_String *pjbPara = new java_lang_String(m_pEntry);
            pjbPara->SetContent("testdata");
            return pjbPara->GetInstanceID();
        } else {
            assert(false);
        }
    } else {
        assert(false);
    }
    return ISimulateClass::CallObjectMethod(pHbThis, iMtdID);
}
uint64_t com_honeybadger_nativelib_NativeLib1::GetLongField(int iFieldID) {
    assert(false);
    return 0;
}

uint64_t com_honeybadger_nativelib_NativeLib1::CallStaticLongMethodV(void *pDebugger, UINT iMtdID) {
    assert(false);
    return 0;
}
UINT com_honeybadger_nativelib_NativeLib1::CallObjectMethodV(void *pHbThis, UINT iMtdID) {
    if (m_mapMethodID_Sig.find(iMtdID) != m_mapMethodID_Sig.end()) {
        string strMtdSig = m_mapMethodID_Sig[iMtdID];
        DebuggerInterface *pDebugger = (DebuggerInterface*)pHbThis;
        if (strMtdSig == "TestLongArg(J)V") {
            CTLOG("补充实现 TestLongArg");
//            DebuggerInterface *pDebugger = (DebuggerInterface*)pHbThis;
//            UINT iArgLowValue = pDebugger->ReadJniFuncPara(1);
//            UINT iArgHighValue = pDebugger->ReadJniFuncPara(2);

//            LOGI("执行 TestLongArg(J)V 参数:%v 没有实际动作", IceMath::Combine(iArgLowValue, iArgHighValue));
            return 0;
        }
        if (strMtdSig == "xxxxxxx") {
//            UINT iVaAddr = pDebugger->ReadRegValueDirect(ARM_REG_R3);
//            vector<UINT> vecArgs = LibArt::VaListAddr2Args(iVaAddr, "Ljava/lang/String;", 1, 4);
//            assert(vecArgs.size() == 1);
//            UINT iParaAddr1 = vecArgs[0];
//            UINT iInstID = ARM::LDR(pDebugger->ConvertVirtualAddress2Buf(iParaAddr1));
//            java_lang_String*pJs = (java_lang_String*)m_pEntry->InvokeSearchClass_Inst(iInstID);
//            string strServiceName = pJs->GetContent();
//            LOGI("执行 getSystemService: %s", strServiceName.c_str());
//            if (strServiceName == "phone") {
//                android_telephony_TelephonyManager *pOut = new android_telephony_TelephonyManager(m_pEntry);
//                return pOut->GetInstanceID();
//            } else if (strServiceName == "connectivity") {
//                android_net_ConnectivityManager *pOut = new android_net_ConnectivityManager(m_pEntry);
//                return pOut->GetInstanceID();
//            }
//            IceAssert(false, "%s", strServiceName.c_str());
            return 0;
        }

        else {
            IceAssert(false, "尚未支持的函数:%v", strMtdSig.c_str());
        }
    } else {
        assert(false);
    }
    return 0;
}

_ULONG com_honeybadger_nativelib_NativeLib1::CallLongMethodV(void *pDebugger, UINT iMtdID) {
    assert(false);
    return 0;
}

UINT com_honeybadger_nativelib_NativeLib1::CallSetObjectField(void *pDebugger, UINT iFiledID, ISimulateClass *pValue) {
    assert(false);
    return 0;
}

UINT com_honeybadger_nativelib_NativeLib1::CallSetIntField(void *pDebugger, UINT iFiledID, UINT iValue) {
    assert(false);
    return 0;
}

float com_honeybadger_nativelib_NativeLib1::GetFloatField(int iFieldID) {
    assert(false);
    return 0;
}

UINT com_honeybadger_nativelib_NativeLib1::GetSuperClass() {
    assert(false);
    return 0;
}

UINT com_honeybadger_nativelib_NativeLib1::GetObjectRefType() {
    assert(false);
    return 0;
}
