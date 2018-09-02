#ifndef HX711_CLASS
#define HX711_CLASS

#include "BaseClass.h"
#include "MethodDescriptor.h"

class Hx711;

namespace nanpy {
    class Hx711Class: public ObjectsManager<Hx711> {
    public:
        void elaborate( nanpy::MethodDescriptor* m );
        const char* get_firmware_id();
    };
}

#endif