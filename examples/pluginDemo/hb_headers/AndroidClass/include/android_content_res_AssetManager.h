//
// Created by ice on 2020/5/29.
//

#ifndef HONEYBADGER_ANDROID_CONTENT_RES_ASSETMANAGER_H
#define HONEYBADGER_ANDROID_CONTENT_RES_ASSETMANAGER_H


#include "ISimulateClass.h"



class android_content_res_AssetManager : public ISimulateClass {
public:
    android_content_res_AssetManager(HB::EntryInterface *pDebugger);
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



public:
    // 调用 android/content/res/AssetManager;->nativeSetApkAssets(J[Landroid/content/res/ApkAssets;Z)V
    void InvokeNativeSetApkAssets();
    // 调用 android/content/res/AssetManager;->nativeCreate()J
    uint64_t InvokeNativeCreate();

private:
    void InsertMethodId(string strMethodSig) override;

    void InsertFieldId(string strFieldSig) override;


private:
    uint32_t m_iClassId;
    string m_strClsssSig;
    uint32_t m_iInstaceID;
    unordered_map<string, uint32_t> m_mapMethodSig_Id; // sig->id
    unordered_map<uint32_t , string> m_mapMethodID_Sig; // id->sig
    // 成员变量
    unordered_map<string, uint32_t> m_mapFieldSig_Id; // sig->id

    HB::EntryInterface *m_pEntry;

public:
    uint64_t mObject{0}; // 对应的是成员变量 mObject:J
};


#endif //HONEYBADGER_ANDROID_CONTENT_RES_ASSETMANAGER_H
