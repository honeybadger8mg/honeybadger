#ifndef HONEYBADGERGUI_PLUGINDEFINES_H
#define HONEYBADGERGUI_PLUGINDEFINES_H

#include "PluginCommHeader.h"
#include "IRestrictedListener.h"

typedef HBMenuChain* (*FUNC_GetPLUGIN_Menu)();
typedef void * (*FUNC_SetRestrictedListener)(IRestrictedListener *);
typedef void *(*FUNC_DoPrepare)();
typedef void *(*FUNC_DispatchAction)(int);

#endif //HONEYBADGERGUI_PLUGINDEFINES_H
