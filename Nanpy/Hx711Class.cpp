#include "cfg_all.h"

#if USE_Hx711

#include <Arduino.h>
#include <hx711.h>
#include "Hx711Class.h"
#include <stdlib.h>

const char* nanpy::Hx711Class::get_firmware_id()
{
    return "Hx711";
}

void nanpy::Hx711Class::elaborate( MethodDescriptor* m ) {
    ObjectsManager<Hx711>::elaborate(m);

    if (strcmp(m->getName(),"new") == 0) {
        Hx711* scale;
        scale = new Hx711(m->getInt(0), m->getInt(1));
        v.insert(scale);
        m->returns(v.getLastIndex());
    }

    if (strcmp(m->getName(), "setOffset") == 0) {
        v[m->getObjectId()]->setOffset(m->getLong(0));
        m->returns(0);
    }

    if (strcmp(m->getName(), "setScale") == 0) {
        v[m->getObjectId()]->setScale(m->getFloat(0));
        m->returns(0);
    }

    if (strcmp(m->getName(), "getGram") == 0) {
        m->returns(v[m->getObjectId()]->getGram());
    }

    if (strcmp(m->getName(), "averageValue") == 0) {
        m->returns(v[m->getObjectId()]->averageValue());
    }
};

#endif