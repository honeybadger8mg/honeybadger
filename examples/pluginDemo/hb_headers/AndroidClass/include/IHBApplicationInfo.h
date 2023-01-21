//
// Created by ice on 2022/12/17.
//

#ifndef HONEYBADGERGUI_IHBAPPLICATIONINFO_H
#define HONEYBADGERGUI_IHBAPPLICATIONINFO_H

#include <string>
#include "SimulateAndroidVersion.h"
#include "MAC_Info.h"
#include "ISimulateClass.h"

class android_content_res_AssetManager;

class IHBApplicationInfo {
public:
    virtual string GetPrivatePcDir() = 0;

    virtual IHBApplicationInfo *SetAndroidVersion(SimulateAndroidVersion savValue) = 0;
    virtual IHBApplicationInfo *SetPid(uint32_t iPid) = 0;
    virtual IHBApplicationInfo *SetPPid(uint32_t iPPid) = 0;
    virtual IHBApplicationInfo *SetUid(uint32_t iUid) = 0; // 因为GID和uid相同  所以不添加SetGid
    virtual IHBApplicationInfo *SetSignatureHashCode(uint32_t iCode) = 0;
    virtual IHBApplicationInfo *SetPackageName(string strPkgName) = 0;
    virtual IHBApplicationInfo *SetLableName(string strLableName) = 0;
    virtual IHBApplicationInfo *SetSignatureBuf(string strSignBuf) = 0;
    virtual IHBApplicationInfo *SetApkFilePath(string strApkFileName) = 0;
    virtual IHBApplicationInfo *SetBootTime(uint32_t iSec, uint32_t iNsec) = 0; // 系统启动时间
    virtual IHBApplicationInfo *SetAssetManager(android_content_res_AssetManager *pManager) = 0; // 设置asssetmanager
    virtual IHBApplicationInfo *SetFirstInstallTime(uint64_t lfirstInstallTime) = 0;



    virtual string GetCmdLinePath_And_Pid() = 0;  // ex: /proc/%d/cmdline
    virtual string GetCmdLinePath_PC() = 0;

    virtual string GetNetArpPath_And_Pid() = 0;  // ex: /proc/%d/net/arp
    virtual string GetNetArpPath_PC() = 0;

    virtual string GetMapsPath_And_Pid() = 0;  // ex: /proc/%d/maps
    virtual string GetMapsPath_PC(HB::EntryInterface *pEntry) = 0;
    virtual void  InnerUpdateMapsFileContent(HB::EntryInterface *pEntry, string strPath) = 0;


    virtual string GetStatusPath_And_Pid() = 0;  // ex: /proc/%d/status
    virtual string GetStatusPath_And_SelfPid() = 0;  // ex: "/proc/self/task/106/status"
    virtual string GetStatusPath_PC() = 0;

    virtual string GetWlan0AddressPath_And() = 0;
    virtual string GetWlan0AddressPath_PC() = 0;

    virtual string GetKernelRandomUuidPath_And() = 0;
    virtual string GetKernelRandomUuidPath_PC() = 0;

    virtual string GetCpuInfoPath_And() = 0;
    virtual string GetCpuInfoPath_PC() = 0;

    virtual string GetAppRootDir_And() = 0; // /data/data/xx.xx.xx/ 这个路径
    virtual string GetAppRootDir_PC() = 0;

    virtual string GetFilesDir_And() = 0;
    virtual string GetFilesDir_PC() = 0;

    virtual string GetCacheDir_And() = 0;
    virtual string GetCacheDir_PC() = 0;

    virtual string GetLibsDir_And() = 0;
    virtual string GetLibsDir_PC() = 0;

    virtual void SetMacInfo(MAC_Info mcInfo) = 0;
    virtual string GetMacAddr_Fmt() = 0; // 11:22:33:44:55:66
    virtual string GetMacAddr_Array() = 0; // x11x22x33x44x55x66

    virtual string GetSourceDir_And() = 0; // 虚拟的apk路径
    virtual string GetSourceDir_PC() = 0; // 真正的apk路径

    virtual string GetDevAlarmPath_And() = 0; // "/dev/alarm"
    virtual string GetDevAlarmPath_PC() = 0;

    virtual string GetProcDir_And() = 0; // /proc
    virtual string GetProcDir_PC() = 0; // /proc

    virtual string GetSdcardDir_And() = 0; // "/sdcard"
    virtual string GetSdcardDir_PC() = 0; // /sdcard

    virtual string GetMntTencentMicroMsgBrowserDir_And() = 0; //
    virtual string GetMntTencentMicroMsgBrowserDir_PC() = 0; //

    virtual string GetStorageTencentMicroMsgBrowserDir_And() = 0; //
    virtual string GetStorageTencentMicroMsgBrowserDir_PC() = 0; //

    virtual string GetTencentMicroMsgBrowserVersionIdPath_And() = 0; // /sdcard/tencent/MicroMsg/browser/version_id.dat
    virtual string GetTencentMicroMsgBrowserVersionIdPath_PC() = 0;

    virtual string GetMetaDataDir_And() = 0; // /data/user/0/com.example.verifyasm/app_metadata
    virtual string GetMetaDataDir_PC() = 0;

    virtual string GetAssetDir_And() = 0; //  对应apk的 asset 文件夹
    virtual string GetAssetDir_PC() = 0; //

    virtual string GetProcNetRoutePath_And() = 0; //  "/proc/net/route"
    virtual string GetProcNetRoutePath_PC() = 0; //

    virtual string GetProcSelfFdDir_And() = 0; // /proc/self/
    virtual string GetProcPidFdDir_And() = 0; // /proc/xxxx/
    virtual string GetProcFdDir_PC() = 0;

    virtual string GetProcSelfFdApkLinkPath_And() = 0;  // /proc/self/fd/291
    virtual string GetProcPidFdApkLinkPath_And() = 0;
    virtual string GetProcSelfFdApkLinkPath_PC() = 0;

    virtual string GetProcSelfMountInfoPath_And() = 0;  // /proc/self/fd/291
    virtual string GetProcPidMountInfoPath_And() = 0;
    virtual string GetProcMountInfoPath_PC() = 0;


private:
    virtual  void InnerUpdateStatusContent(string strPath, int iPid,int iPPid, int iUid) = 0;


public:
    virtual uint32_t GetPID() = 0;
    virtual uint32_t GetPPID() = 0;
    virtual uint32_t GetUid() = 0;
    virtual uint32_t GetGid() = 0; // 因为与UID相同 所以内部直接调用UID
    virtual void GetBootTime(uint32_t &iSec, uint32_t &iNsec) = 0;
    virtual string GetUUID() = 0;
    virtual uint32_t GetSignatureHashCode() = 0;
    virtual string GetSignatureBuf() = 0;
    virtual string GetPackageName() = 0;
    virtual string GetLableName() = 0;
    virtual string GetApkName() = 0;
    virtual SimulateAndroidVersion GetAndroidVersion() = 0;
    virtual int GetAndroidVersionSDK() = 0; // 获取系统对应的sdk值
    virtual android_content_res_AssetManager *GetAssetManager() = 0;
    virtual uint64_t GetFirstInstallTime() = 0;

};

#endif //HONEYBADGERGUI_IHBAPPLICATIONINFO_H
