#ifndef ENCODER_CLASS
#define ENCODER_CLASS

#include "BaseClass.h"
#include "MethodDescriptor.h"

class Encoder;

namespace nanpy {
    class EncoderClass: public ObjectsManager<Encoder> {
    public:
        void elaborate( nanpy::MethodDescriptor* m );
        const char* get_firmware_id();
    };
}

#endif