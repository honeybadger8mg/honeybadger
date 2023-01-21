//
// Created by ice on 2023/1/21.
//

#ifndef HONEYBADGERGUI_ICLASSMANAGER_H
#define HONEYBADGERGUI_ICLASSMANAGER_H

#include <string>

class ISimulateClass;

class IClassManager {
public:
    virtual ~IClassManager(){};

    virtual uint32_t ForName(std::string strClsName) = 0; // jniEnv.findclass()
    virtual std::string SearchClass_Sig(uint32_t iClsId) = 0; // 获取对应的类的签名
    virtual ISimulateClass* SearchClass_Inst(uint32_t iClsId) = 0; // 获取对应的类的实例
    virtual bool IsExistInstance(uint32_t iInstID) = 0;

};


#endif //HONEYBADGERGUI_ICLASSMANAGER_H
