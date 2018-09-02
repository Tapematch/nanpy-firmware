#include "cfg_all.h"

#if USE_Encoder

#include <Arduino.h>
#include <Encoder.h> //!!!Your real Centipede Library!!!!
#include "EncoderClass.h"
#include <stdlib.h>

const char* nanpy::EncoderClass::get_firmware_id()
{
    return "Encoder";
}

void nanpy::EncoderClass::elaborate( MethodDescriptor* m ) {
    ObjectsManager<Encoder>::elaborate(m);

    if (strcmp(m->getName(),"new") == 0) {
        Encoder* enc;
        enc = new Encoder(m->getInt(0), m->getInt(1));
        v.insert(enc);
        m->returns(v.getLastIndex());
    }

    if (strcmp(m->getName(), "read") == 0) {
        m->returns(v[m->getObjectId()]->read());
    }
};

#endif