// #include <iostream>
// #include "IBasicService.h"

// int main()
// {
//     sp<IServiceManager> sm = defaultServiceManager();
//     sp<IBinder> binder = sm->getService(String16("service.demo"));
//     sp<IBasicService> service = interface_cast<IBasicService>(binder);
//     service->sayHello();
//     for (int16_t i = 0; i < 10; i++)
//     {
//         int32_t value = service->random();
//         std::cout << "client::random recv: " << value << std::endl;
//     }
//     return 0;
// }

#include <binder/IServiceManager.h>
#include<string>
#include <utils/Log.h>
#include<iostream>
#include "IBasicService.h"

using namespace android;

void showAccounts(const Vector<String16> &accounts)
{
   std::cout << "There are " << accounts.size() << " accounts" <<std::endl;
   for (size_t i = 0; i < accounts.size(); i++)
   {
      printf("account[%d]: %s", i+1, accounts[i].string());
   }
}

int main()
{
   sp<IServiceManager> serviceManager = defaultServiceManager();
   sp<IBinder> binder = serviceManager->getService(String16("service.demo"));
   sp<IBasicService> service = interface_cast<IBasicService>(binder);

   service->addAccount(String16("John"));
   showAccounts(service->listAccounts());

   service->addAccount(String16("Doe"));
   showAccounts(service->listAccounts());
}