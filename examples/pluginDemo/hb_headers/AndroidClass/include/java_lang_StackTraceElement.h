//
// Created by ice on 2020/4/30.
//

#ifndef HONEYBADGER_JAVA_LANG_STACKTRACEELEMENT_H
#define HONEYBADGER_JAVA_LANG_STACKTRACEELEMENT_H

#include "ISimulateClass.h"
#include <map>

using namespace std;



class java_lang_StackTraceElement  : public ISimulateClass {
public:
    java_lang_StackTraceElement(string strClassName, HB::EntryInterface *pDebugger);
    uint32_t GetClassID() override;

    string GetClassSig() override;

    uint32_t GetMethodID(string strMethodSig) override;

    uint32_t CallStaticObjectMethodV(void* pDebugger, uint32_t iMtdID) override;

    void SetInstanceID(uint32_t iID) override;

    uint32_t GetInstanceID() override;

    string SearchMethodName(int iMtdID) override;

    bool IsArray() override;

    int GetArrayCount() override;

    uint32_t GetObjectArrayElement(int iIndex) override;

    uint32_t GetFieldID(string strFieldSig) override;

    uint32_t GetFieldValue(int iFieldID) override;
    uint32_t ExecNewObject(void *pDebugger, uint32_t iMtdID) override ;
    uint32_t OnInvoke(void *pHbThis, void *pInvokeMethodInst) override ;

    uint32_t OnGet(void *pHbThis, void *pFieldInstPara) override;

    void FreeSelf() override;


    HB::EntryInterface *GetEntry() override;

    uint32_t CallObjectMethod(void *pDebugger, uint32_t iMtdID) override;

    uint64_t GetLongField(int iFieldID) override;

    uint64_t CallStaticLongMethodV(void *pDebugger, uint32_t iMtdID) override;

    uint32_t CallObjectMethodV(void *pDebugger, uint32_t iMtdID) override;

    uint64_t CallLongMethodV(void *pDebugger, uint32_t iMtdID) override;



    uint32_t GetObjectRefType() override;



    uint32_t GetSuperClass() override;



    float GetFloatField(int iFieldID) override;



    uint32_t CallSetIntField(void *pDebugger, uint32_t iFiledID, uint32_t iValue) override;



    uint32_t CallSetObjectField(void *pDebugger, uint32_t iFiledID, ISimulateClass *pValue) override;


private:
    java_lang_StackTraceElement();
    void InsertMethodId(string strMethodSig) override;

    void InsertFieldId(string strFieldSig) override;

private:
    uint32_t m_iClassId;
    string m_strClsssSig;
    uint32_t m_iInstaceID;

    string m_strClassName; // ?????? ex: com.aweme.myapplication.MainActivity
    map<string, uint32_t> m_mapMethodSig_Id; // sig->id
    unordered_map<uint32_t , string> m_mapMethodID_Sig; // id->sig
    // ????????????
    unordered_map<string, uint32_t> m_mapFieldSig_Id; // sig->id


    HB::EntryInterface *m_pEntry;
};


#endif //HONEYBADGER_JAVA_LANG_STACKTRACEELEMENT_H
