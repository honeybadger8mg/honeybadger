//
// Created by ice on 2022/12/5.
//

#include <cstring>
#include <iostream>
#include "PluginExport.h"
#include "CBizWorker.h"
#include "CPublicUtil.h"
#include "IceRandom.h"
#include "BizJavaCls/com_honeybadger_nativelib_NativeLib1.h"
#include "android_app_Application.h"
#include "CommToolsHeader.h"
#include "EntryInterface.h"
#include "ArmReg.h"
#include "IClassManager.h"

HBMenuChain *g_pMenu = nullptr;
IRestrictedListener *g_pListener = nullptr;

CBizWorker g_worker;

HBMenuChain *CreateMenu(const char *szName, int id, HBMenuChain *prev) {
    HBMenuChain *pOut = new HBMenuChain;
    memcpy(&pOut->szName, szName, strlen(szName));
    pOut->id = id;
    pOut->prev = prev;
    return pOut;
}

HBMenuChain *GetMenu() {
    if (g_pMenu == nullptr) {
        g_pMenu = CreateMenu("调用DoTest1", 1, nullptr);
        HBMenuChain *pSecond = CreateMenu("调用DoTest2", 2, g_pMenu);
        g_pMenu->next = pSecond;

        HBMenuChain *pThird = CreateMenu("其他函数", 3, pSecond);
        pSecond->next = pThird;
    }
    return g_pMenu;
}

void SetRestrictedListener(IRestrictedListener *pCb) {
    g_pListener = pCb;
    pCb->SetBizInterface(&g_worker);
}

void DoPrepare() {
    if (g_pListener == nullptr) {
        CTLOG("没有设置 IRestrictedListener");
        return;
    }

    g_pListener->SetAndroidId(IceRandom::NextString16(16));
    g_pListener->SetPackageName("com.tencent.mm");
    g_pListener->SetLableName("WhatsApp");
    g_pListener->SetFinger("xiaomi/onc/onc:9/PKQ1.181021.001/V10.3.2.0.PFLCNXM:user/release-keys");
//            g_pListener->SetApkPath("weixin8016android2040.apk"); 可设可不设   主程序会自动设置
    g_pListener->SetSignatureHashCode(0x1122334);
    g_pListener->SetSignatureBuf(CPublicUtil::Hex2Str(
            "308203563082023EA00302010202044EFEC96A300D06092A864886F70D0101050500306D310B300906035504061302434E3110300E060355040813074265696A696E673110300E060355040713074265696A696E6731123010060355040A13094279746544616E636531123010060355040B13094279746544616E636531123010060355040313094D6963726F2043616F301E170D3131313233313038333535345A170D3339303531383038333535345A306D310B300906035504061302434E3110300E060355040813074265696A696E673110300E060355040713074265696A696E6731123010060355040A13094279746544616E636531123010060355040B13094279746544616E636531123010060355040313094D6963726F2043616F30820122300D06092A864886F70D01010105000382010F003082010A0282010100A46D108BE827BFF2C1AC7AD986C463B8CDA9F0E7DDC21295AF55BD16F7BFABB36FA33B72A8E76F5A59B48B29CB6E34C38D065589636DD120F39346C37B3753830422CC0C84243FDF0E28D3E5970DCD641C70C9E2E3EC66AC14AFD351ABB59D6885370E16B64BBFB28FBB234DFFE25F5CFB6680C84121770CF3A177BC8A28B78B7C86D30A61EB67B9FBFD92E0C8FC5EB8346A238DDFE08522F091C622789932D9DEBE6910B4B903D02E5F6DED69F5C13A5D1742DAC21050DFBB5F4EA615028D7A8642E4A93E075CF8F0E33A4A654AF11F4F9A4905D917F0BBB84E63A1A2E90B8997F936E5BF5A75EA6D19D1D93D2677886E59E95C0BB33505363C05E10A389D0B0203010001300D06092A864886F70D010105050003820101008704E53758907DB6785BEC65C5F51AF050873C4B0A5E08F90191B901C59969CE537942DBC9307F8FCC23B1C281A66FE46136890564F89FB16839AC69F836A9EA074EB03DA8578330AB50B185BD6916F195A67036060A0BBF2AED06990E72BC4DEDE895AE5E695371AA4AD26EFCD44B65891BDA9CE02D9E71548592C2951E2CB62ED4408EEC7E828CE573FFBA0458341AEF25957B2A76403DA091322EB845B6A9903FE6AED1434012D483F1C668E2468CE129815E18283BAA5E1C4209691B36FFA86506FF6A4B83F24FAA744383B75968046C69703D2C5DF38BAD6920D9122CB1F7C78E8BFE283870359C053115E2BA0A7A03C9656A2F5A2D81F6A6FAD5DB2CD7"));
}

void DispatchAction(int iActId) {
    switch (iActId) {
        case 1: {
            // 调用 DoTest1
            CTLOG("准备执行 DoTest1...");
            java_lang_String *pJsArg = new java_lang_String(g_pListener->GetEntry());
            pJsArg->SetContent("hello world");

            com_honeybadger_nativelib_NativeLib1 *pThis = new com_honeybadger_nativelib_NativeLib1(g_pListener->GetEntry());
            vector<uint32_t> vecPara = {g_pListener->GetJniEnvAddr(), pThis->GetInstanceID(), pJsArg->GetInstanceID()};
            map<uint32_t, uint64_t> mapResult;
            g_pListener->ExecJniInThread(true, "Java_com_honeybadger_nativelib_NativeLib1_DoTest1", 3, vecPara,
                                         &mapResult);

            uint32_t iOut = mapResult[ARM_REG_R0];
            java_lang_String *pJsOut = (java_lang_String *) g_pListener->GetEntry()->GetVaClassInst()->SearchClass_Inst(iOut);
            string strOut = "执行 DoTest1 结束,结果:" + pJsOut->GetContent();
            CTLOG(strOut.c_str());
            break;
        }
        case 2: {
            CTLOG("准备执行 DoTest2...");
            uint32_t iArg = 100;

            com_honeybadger_nativelib_NativeLib1 *pThis = new com_honeybadger_nativelib_NativeLib1(g_pListener->GetEntry());
            vector<uint32_t> vecPara = {g_pListener->GetJniEnvAddr(), pThis->GetInstanceID(), iArg};
            map<uint32_t, uint64_t> mapResult;
            g_pListener->ExecJniInThread(true, "Java_com_honeybadger_nativelib_NativeLib1_DoTest2", 3, vecPara,
                                         &mapResult);

            uint32_t iOut = mapResult[ARM_REG_R0];
            string strOut = "执行 DoTest2 结束,结果:" + CPublicUtil::Int2String(iOut);
            CTLOG(strOut.c_str());
            break;
        }
        case 3:{
            CTLOG("这里是继续添加其他函数的处理过程");
            break;
        }
        default: {
            std::cout << "没有实现的函数" << std::flush;
            break;
        }
    }
}
