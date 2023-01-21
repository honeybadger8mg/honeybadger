//
// Created by ice on 2020/5/27.
//

#ifndef HONEYBADGER_HBMETHODIDBLOCKS_H
#define HONEYBADGER_HBMETHODIDBLOCKS_H

#include <string>
#include <map>
#include "PreDefine.h"


using namespace std;

struct MethodIdInfo {
    uint32_t m_iUkn0;
    uint32_t m_iUkn1;
    uint32_t m_iUkn2;
    uint32_t m_iUkn3;
    uint32_t m_iUkn4;
    uint32_t m_iUkn5;
    uint32_t m_iUkn6; // art_quick_to_interpreter_bridge
};

// 存储反射的方法信息
class HBMethodIdBlocks {
public:
    HBMethodIdBlocks();
    void Init();
    // 获取一个新的
    uint32_t GetNewMethodId(string strFullMethodSig);
    uint32_t GetNewFieldId(string strFullFieldSig);
    // 根据fieldid获取成员签名
    string GetFieldSig(uint32_t iFieldId);
    string GetMethodSig(uint32_t iMtdId);
    //
    uint32_t GetNewClassId(string strFullClassSig);
    //
    uint32_t GetNewInstantID();


public:

private:
    uint32_t m_iUsedFieldId;
    /*
     * 这个是指针
     * https://cs.android.com/android/platform/superproject/+/master:art/runtime/jni/jni_internal.h;l=125;drc=master     125行
     * https://cs.android.com/android/platform/superproject/+/master:art/runtime/art_method.h;drc=master;l=72
     * */
    uint32_t m_iUsedMethodId;
    uint32_t m_iUsedClassId;
    map<string, uint32_t> m_mapGlobalMethodIdTable;
    map<string, uint32_t> m_mapGlobalFieldIdTable;
    map<string, uint32_t> m_mapGlobalClassIdTable;
    uint32_t m_iInstanceID; // 实例的值

};


#endif //HONEYBADGER_HBMETHODIDBLOCKS_H
