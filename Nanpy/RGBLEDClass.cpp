#include "cfg_all.h"

#if USE_RGBLED

#include <Arduino.h>
#include <RGBLED.h>
#include "RGBLEDClass.h"
#include <stdlib.h>

const char* nanpy::RGBLEDClass::get_firmware_id()
{
    return "RGBLED";
}

void nanpy::RGBLEDClass::elaborate( MethodDescriptor* m ) {
    ObjectsManager<RGBLED>::elaborate(m);

    if (strcmp(m->getName(),"new") == 0) {
        RGBLED* led;
        led = new RGBLED(m->getInt(0), m->getInt(1), m->getInt(2));
        v.insert(led);
        m->returns(v.getLastIndex());
    }

    if (strcmp(m->getName(), "addLED") == 0) {
        v[m->getObjectId()]->addLED(m->getInt(0), m->getInt(1), m->getInt(2));
        m->returns(0);
    }

    if (strcmp(m->getName(), "update") == 0) {
        v[m->getObjectId()]->update();
        m->returns(0);
    }

    if (strcmp(m->getName(), "setColor") == 0) {
        v[m->getObjectId()]->setColor(m->getInt(0), m->getInt(1), m->getInt(2));
        m->returns(0);
    }

    if (strcmp(m->getName(), "fadeToColor") == 0) {
        v[m->getObjectId()]->fadeToColor(m->getInt(0), m->getInt(1), m->getInt(2), m->getLong(3));
        m->returns(0);
    }

    if (strcmp(m->getName(), "pulse") == 0) {
        v[m->getObjectId()]->pulse(m->getInt(0), m->getInt(1), m->getInt(2), m->getLong(3));
        m->returns(0);
    }

    if (strcmp(m->getName(), "blink") == 0) {
        v[m->getObjectId()]->blink(m->getInt(0), m->getInt(1), m->getInt(2), m->getLong(3));
        m->returns(0);
    }

    if (strcmp(m->getName(), "rainbow") == 0) {
        v[m->getObjectId()]->rainbow(m->getLong(0));
        m->returns(0);
    }

    if (strcmp(m->getName(), "off") == 0) {
        v[m->getObjectId()]->off();
        m->returns(0);
    }

    if (strcmp(m->getName(), "getCurrentRed") == 0) {
        m->returns(v[m->getObjectId()]->getCurrentRed());
    }

    if (strcmp(m->getName(), "getCurrentGreen") == 0) {
        m->returns(v[m->getObjectId()]->getCurrentGreen());
    }

    if (strcmp(m->getName(), "getCurrentBlue") == 0) {
        m->returns(v[m->getObjectId()]->getCurrentBlue());
    }
};

#endif