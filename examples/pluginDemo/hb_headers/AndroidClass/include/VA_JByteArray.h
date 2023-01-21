//
// Created by ice on 2020/5/1.
//

#ifndef HONEYBADGER_VA_JBYTEARRAY_H
#define HONEYBADGER_VA_JBYTEARRAY_H

#include "ISimulateClass.h"



class VA_JByteArray : public ISimulateClass {
public:
    VA_JByteArray(HB::EntryInterface *pDebugger);

    uint32_t GetClassID() override;

    string GetClassSig() override;

    uint32_t GetMethodID(string strMethodSig) override;

    uint32_t CallStaticObjectMethodV(void *pDebugger, uint32_t iMtdID) override;

    void SetInstanceID(uint32_t iID) override;

    uint32_t GetInstanceID() override;

    string SearchMethodName(int iMtdID) override;

    bool IsArray() override;

    int GetArrayCount() override;

    uint32_t GetObjectArrayElement(int iIndex) override;
    uint32_t ExecNewObject(void *pDebugger, uint32_t iMtdID) override ;
    uint32_t OnInvoke(void *pHbThis, void *pInvokeMethodInst) override ;

public:
    static VA_JByteArray* CreateNew(HB::EntryInterface *pEntry,string strContent);
    VA_JByteArray* SetContent(string strContent);

    string GetContent();

    uint32_t GetFieldID(string strFieldSig) override;

    uint32_t GetFieldValue(int iFieldID) override;

    // 设置长度
    void CreateEmptyData(int iLen);

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
    void InsertMethodId(string strMethodSig) override;

    void InsertFieldId(string strFieldSig) override;

private:
    uint32_t m_iClassId;
    string m_strClsssSig;
    uint32_t m_iInstaceID;
    string m_strContent; // 内容
    unordered_map<string, uint32_t> m_mapMethodSig_Id; // sig->id
    unordered_map<uint32_t , string> m_mapMethodID_Sig; // id->sig
    // 成员变量
    unordered_map<string, uint32_t> m_mapFieldSig_Id; // sig->id


    HB::EntryInterface *m_pEntry;
};


#endif //HONEYBADGER_VA_JBYTEARRAY_H
