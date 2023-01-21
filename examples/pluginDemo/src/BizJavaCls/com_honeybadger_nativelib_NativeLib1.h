//
// Created by ice on 8/19/20.
//

#ifndef HONEYBADGER_COM_EXAMPLE_VERIFYASM_MAINACTIVITY_H
#define HONEYBADGER_COM_EXAMPLE_VERIFYASM_MAINACTIVITY_H

#include "ISimulateClass.h"

class com_honeybadger_nativelib_NativeLib1 : public ISimulateClass {
public:
    com_honeybadger_nativelib_NativeLib1(HB::EntryInterface *pDebugger);
    UINT GetClassID() override;

    string GetClassSig() override;

    UINT GetMethodID(string strMethodSig) override;

    UINT CallStaticObjectMethodV(void *pDebugger, UINT iMtdID) override;

    void SetInstanceID(UINT iID) override;

    UINT GetInstanceID() override;

    string SearchMethodName(int iMtdID) override;

    bool IsArray() override;

    int GetArrayCount() override;

    UINT GetObjectArrayElement(int iIndex) override;

    UINT GetFieldID(string strFieldSig) override;

    UINT GetFieldValue(int iFieldID) override;
    UINT ExecNewObject(void *pDebugger, UINT iMtdID) override ;
    UINT OnInvoke(void *pHbThis, void *pInvokeMethodInst) override ;

    UINT OnGet(void *pHbThis, void *pFieldInstPara) override;

    void FreeSelf() override;


    HB::EntryInterface *GetEntry() override;

    UINT CallObjectMethod(void *pDebugger, UINT iMtdID) override;

    uint64_t GetLongField(int iFieldID) override;

    uint64_t CallStaticLongMethodV(void *pDebugger, UINT iMtdID) override;

    UINT CallObjectMethodV(void *pDebugger, UINT iMtdID) override;

    _ULONG CallLongMethodV(void *pDebugger, UINT iMtdID) override;

    UINT CallSetObjectField(void *pDebugger, UINT iFiledID, ISimulateClass *pValue) override;

    UINT CallSetIntField(void *pDebugger, UINT iFiledID, UINT iValue) override;

    float GetFloatField(int iFieldID) override;

    UINT GetSuperClass() override;

    UINT GetObjectRefType() override;

private:
    void InsertMethodId(string strMethodSig) override;

    void InsertFieldId(string strFieldSig) override;



private:
    UINT m_iClassId;
    string m_strClsssSig;
    UINT m_iInstaceID;
    unordered_map<string, UINT> m_mapMethodSig_Id; // sig->id
    unordered_map<UINT , string> m_mapMethodID_Sig; // id->sig
    // 成员变量
    unordered_map<string, UINT> m_mapFieldSig_Id; // sig->id


    HB::EntryInterface *m_pEntry;
};



#endif //HONEYBADGER_COM_EXAMPLE_VERIFYASM_MAINACTIVITY_H
