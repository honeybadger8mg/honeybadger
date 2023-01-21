//
// Created by ice on 2020/5/29.
//

#ifndef HONEYBADGER_android_graphics_BitmapFactory_Options_H
#define HONEYBADGER_android_graphics_BitmapFactory_Options_H


#include "ISimulateClass.h"



class android_graphics_BitmapFactory_Options : public ISimulateClass {
public:
    android_graphics_BitmapFactory_Options(HB::EntryInterface *pDebugger);
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


private:
    void InsertMethodId(string strMethodSig) override;

    void InsertFieldId(string strFieldSig) override;

public:
    uint32_t inPreferredConfig{0};// 实例的id
    uint32_t inSampleSize{0};
    uint32_t inJustDecodeBounds{0};
    uint32_t outWidth{0};
    uint32_t outHeight{0};
    string outMimeType;
    uint32_t outConfig{0}; // 实例的id
    uint32_t outColorSpace{0}; // 实例的id
    uint32_t inPreferredColorSpace{0};
    uint32_t inMutable{0};
    uint32_t inPremultiplied{0};
    uint32_t inBitmap{0};
    uint32_t inScaled{0};
    uint32_t inDensity{0};
    uint32_t inTargetDensity{0};
    uint32_t inScreenDensity{0};

private:
    uint32_t m_iClassId;
    string m_strClsssSig;
    uint32_t m_iInstaceID;
    unordered_map<string, uint32_t> m_mapMethodSig_Id; // sig->id
    unordered_map<uint32_t , string> m_mapMethodID_Sig; // id->sig
    // 成员变量
    unordered_map<string, uint32_t> m_mapFieldSig_Id; // sig->id

    HB::EntryInterface *m_pEntry;
};


#endif //HONEYBADGER_android_graphics_BitmapFactory_Options_H
