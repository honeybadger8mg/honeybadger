//
// Created by ice on 2020/4/30.
//

#ifndef HONEYBADGER_ANDROID_APP_APPLICATION_H
#define HONEYBADGER_ANDROID_APP_APPLICATION_H

#include "ISimulateClass.h"
#include "android_content_pm_ApplicationInfo.h"
#include "java_lang_String.h"
#include "android_content_ContentResolver.h"
#include "java_io_File.h"



class android_app_Application : public ISimulateClass {
public:
    // 获取实例   并一并处理关联的信息，比如包名之类
    static android_app_Application *CreateNew(HB::EntryInterface *pDebugger, string strDstPkgName);

public:
    android_app_Application(HB::EntryInterface *pDebugger);

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

    uint32_t ExecNewObject(void *pDebugger, uint32_t iMtdID) override;

    uint32_t OnInvoke(void *pHbThis, void *pInvokeMethodInst) override;

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
    unordered_map<string, uint32_t> m_mapMethodSig_Id; // sig->id
    unordered_map<uint32_t , string> m_mapMethodID_Sig; // id->sig
    // 成员变量
    unordered_map<string, uint32_t> m_mapFieldSig_Id; // sig->id

    HB::EntryInterface *m_pEntry;


private:
    android_content_pm_ApplicationInfo *m_ApplicationInfo;
    java_lang_String *m_pJsPkgName;
    android_content_ContentResolver *m_ContentResolver;
    java_io_File *m_FilesDir;
};


#endif //HONEYBADGER_ANDROID_APP_APPLICATION_H
