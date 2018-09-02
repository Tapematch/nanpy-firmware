#ifndef RGBLED_CLASS
#define RGBLED_CLASS

#include "BaseClass.h"
#include "MethodDescriptor.h"

class RGBLED;

namespace nanpy {
    class RGBLEDClass: public ObjectsManager<RGBLED> {
    public:
        void elaborate( nanpy::MethodDescriptor* m );
        const char* get_firmware_id();
    };
}

#endif