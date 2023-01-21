//
// Created by ice on 2022/12/5.
//

#ifndef HONEYBADGERGUI_PLUGINEXPORT_H
#define HONEYBADGERGUI_PLUGINEXPORT_H

#include "PluginCommHeader.h"
#include "IRestrictedListener.h"

extern "C" { //导出
    HBMenuChain *GetMenu();
    // 设置接口  所有的主动调用均由此实现
    void SetRestrictedListener(IRestrictedListener *pCb);
    // 准备  设置andridid等
    void DoPrepare();


    // 函数调用  根据id分发
    void DispatchAction(int iActId);


}


#endif //HONEYBADGERGUI_PLUGINEXPORT_H
