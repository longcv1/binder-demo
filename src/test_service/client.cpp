#include <iostream>
#include "IBasicService.h"

int main()
{
    sp<IServiceManager> sm = defaultServiceManager();
    sp<IBinder> binder = sm->getService(String16("service.demo"));
    sp<IBasicService> service = interface_cast<IBasicService>(binder);
    service->sayHello();
    for (int16_t i = 0; i < 10; i++)
    {
        int32_t value = service->random();
        std::cout << "client::random recv: " << value << std::endl;
    }
    return 0;
}
