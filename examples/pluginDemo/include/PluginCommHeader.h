#ifndef HONEYBADGERGUI_PLUGINCOMMHEADER_H
#define HONEYBADGERGUI_PLUGINCOMMHEADER_H

#define MAX_HBMenu_NAME_LEN 64   // 菜单名称最大长度

// 菜单定义   交互方式为 GUI从插件获取右键结构体，结构体包含id,执行具体任务时传id给插件，由插件自行分发处理
struct HBMenuChain {
    char szName[MAX_HBMenu_NAME_LEN]{0};
    int id{0};

    HBMenuChain *prev{nullptr};
    HBMenuChain *next{nullptr};
};




#endif //HONEYBADGERGUI_PLUGINCOMMHEADER_H
