//
// Created by ice on 2022/12/16.
//

#ifndef HONEYBADGERGUI_IRESTRICTEDLISTENER_H
#define HONEYBADGERGUI_IRESTRICTEDLISTENER_H

#include <string>
#include <vector>
#include <map>

namespace HB {
    class BizInterface;
    class EntryInterface;
}

class IRestrictedListener {
public:
    virtual uint32_t GetJniEnvAddr() = 0;
    virtual HB::EntryInterface *GetEntry() = 0;

    virtual void SetAndroidId(std::string strAndroidId) = 0;
    virtual void SetFinger(std::string strFinger) = 0;


    virtual void SetPackageName(std::string strPkgName) = 0;
    virtual void SetLableName(std::string strLableName) = 0;
    virtual void SetSignatureHashCode(uint32_t iCode)  = 0;
    virtual void SetSignatureBuf(std::string strSignBuf) = 0;
    virtual void SetApkPath(std::string strApkFilePath) = 0;



    // 设置业务回调
    virtual void SetBizInterface(HB::BizInterface *pBiz) = 0;
    // 设置主动态库路径
    virtual void SetMainSoPath(std::string strMainSoPath) = 0;



public: // 在全部的要设置的环境变量/上下文设置完成后的函数
    // 运行 等价于Android的函数 System.load
    virtual void Run(bool bBpInitFunc, bool bBpInitArray, bool bBpJniOnload) = 0;
    // 调用指定函数 函数签名如下样子: Java_com_example_verifyasm_MainActivity_TestAssetManager
    virtual void ExecJniInThread(bool bWaitRunFinish, std::string strMethodSig, int iParaCount, std::vector<uint32_t> vecPara, std::map<uint32_t , uint64_t> *pResultOut) = 0;
};

#endif //HONEYBADGERGUI_IRESTRICTEDLISTENER_H
