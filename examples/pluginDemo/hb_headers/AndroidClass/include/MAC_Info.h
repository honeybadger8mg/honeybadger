//
// Created by ice on 2022/12/17.
//

#ifndef HONEYBADGERGUI_MAC_INFO_H
#define HONEYBADGERGUI_MAC_INFO_H

class MAC_Info {
public:
    MAC_Info() {

    }
    MAC_Info(uint8_t v1,uint8_t v2,uint8_t v3,uint8_t v4,uint8_t v5,uint8_t v6) {
        V1 = v1;
        V2 = v2;
        V3 = v3;
        V4 = v4;
        V5 = v5;
        V6 = v6;
    };
public:
    uint8_t V1;
    uint8_t V2;
    uint8_t V3;
    uint8_t V4;
    uint8_t V5;
    uint8_t V6;

public:
};

#endif //HONEYBADGERGUI_MAC_INFO_H
