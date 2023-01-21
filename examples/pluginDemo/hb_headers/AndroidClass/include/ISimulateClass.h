//
// Created by ice on 2020/4/28.
//

#ifndef HONEYBADGER_ISIMULATECLASS_H
#define HONEYBADGER_ISIMULATECLASS_H

#include <string>
#include <unordered_map>

using namespace std;

namespace HB {
    class EntryInterface;
}

class ISimulateClass {
public:
    virtual HB::EntryInterface *GetEntry() = 0; //
    virtual ~ISimulateClass(); // 这个是用于delete时方便

    virtual uint32_t GetClassID() = 0;

    virtual string GetClassSig() = 0;

    virtual uint32_t GetMethodID(string strMethodSig);// = 0; // 返回0则代表还么有设置
    virtual uint32_t CallStaticObjectMethodV(void *pDebugger, uint32_t iMtdID) = 0; // 调用静态函数
    virtual uint64_t CallStaticLongMethodV(void *pDebugger, uint32_t iMtdID) = 0; // 调用静态函数
    virtual uint32_t CallObjectMethod(void *pDebugger, uint32_t iMtdID);// = 0; // 调用成员函数
    virtual uint32_t CallObjectMethodV(void *pDebugger, uint32_t iMtdID) = 0; // 调用成员函数 CallIntMethodV 可共用
    virtual uint64_t CallLongMethodV(void *pDebugger, uint32_t iMtdID) = 0;
    virtual uint32_t CallSetObjectField(void *pDebugger, uint32_t iFiledID, ISimulateClass *pValue) = 0;
    virtual uint32_t CallSetIntField(void *pDebugger, uint32_t iFiledID, uint32_t iValue) = 0;
    virtual void SetInstanceID(uint32_t iID) = 0;

    virtual uint32_t GetInstanceID() = 0;

    virtual string SearchMethodName(int iMtdID);// = 0;

    virtual uint32_t GetFieldID(string strFieldSig) = 0; // 成员变量查询 如果不存在则返回0
    virtual uint32_t GetFieldValue(int iFieldID) = 0; // 读取成员变量  GetObjectField 等一系列函数都走这个函数
    virtual uint64_t GetLongField(int iFieldID) = 0;
    virtual float GetFloatField(int iFieldID) = 0;
    virtual uint32_t ExecNewObject(void *pDebugger, uint32_t iMtdID) = 0; // 对应 jni 的 NewObjectV

    virtual uint32_t OnInvoke(void *pHbThis, void *pInvokeMethodInst) = 0; // 反射的invoke函数
    virtual uint32_t OnGet(void *pHbThis, void *pFieldInstPara) = 0; // 反射的获取成员的值

    virtual uint32_t GetSuperClass() = 0; // 对应jni的 GetSuperclass  返回的是对应类型的classid
    // 对应jni的 GetObjectRefType  返回的是对应类型的
    // JNIInvalidRefType = 0,//无效引用
    // JNILocalRefType = 1,//局部引用
    // JNIGlobalRefType = 2,//全局引用
    // JNIWeakGlobalRefType = 3//弱全局引用
    virtual uint32_t GetObjectRefType() = 0;

    virtual void FreeSelf() = 0; // 自释放自身

public: // 属性的函数
    virtual bool IsArray() = 0;

    virtual int GetArrayCount() = 0; // 数组才有效  非数组返回0
    // 返回的是数组中下标为index的对象的instID  这个函数不支持基本类型(比如int[] 这种的读取元素)
    // 如果不是数组  则返回0
    virtual uint32_t GetObjectArrayElement(int iIndex) = 0;

private:
    virtual void InsertMethodId(string strMethodSig) = 0;

    virtual void InsertFieldId(string strFieldSig) = 0;
};


#endif //HONEYBADGER_ISIMULATECLASS_H
