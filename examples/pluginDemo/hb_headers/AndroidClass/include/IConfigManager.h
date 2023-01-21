//
// Created by ice on 2022/12/17.
//

#ifndef HONEYBADGERGUI_ICONFIGMANAGER_H
#define HONEYBADGERGUI_ICONFIGMANAGER_H

class DebuggerInterface;

class IConfigManager {
public:
    virtual void SetEntryStartAddr(uint32_t iEntryStartAddr) = 0;
    virtual void InitShanow() = 0;
    virtual void SetBSSID(string strBssid) = 0;
    virtual string GetBssid() = 0;
    virtual void SetSSID(string strSsid) = 0;
    virtual string GetSsid() = 0;
    virtual void SetSn(string strSn) = 0;
    virtual string GetSn() = 0;
    virtual void SetImsi(string strDevId) = 0; // imsi
    virtual string GetImsi() = 0;
    virtual void SetImei(string strImei) = 0;
    virtual string GetImei() = 0;
    virtual string GetSysInfo() = 0;
    virtual void SetAndroidId(string strAndroidId) = 0;
    virtual string GetAndroidId() = 0;
    virtual void SetJavaVmVersion(string strVersion) = 0;
    virtual string GetJavaVmVersion() = 0;
    virtual void SetSdkValue(int iSdk) = 0; // ro.build.version.sdk
    virtual int GetSdkValue() = 0;
    virtual void SetFingerPrint(string strFinger) = 0;
    virtual string GetFingerPrint() = 0;
    virtual void SetReleaseValue(string strRelease) = 0;
    virtual string GetReleaseValue() = 0;
    virtual void SetSimOpratorNum(string strNum) = 0; // 46003
    virtual string GetSimOpratorNum() = 0;

    // 获取账号相关的文件存储路径
    virtual string GetAccountPtivateDir() = 0; //实际是按androidid来区分

public:

public: //
    virtual string SystemPropertyGet(string strKey, DebuggerInterface *pDebugger) = 0;
};


#endif //HONEYBADGERGUI_ICONFIGMANAGER_H
