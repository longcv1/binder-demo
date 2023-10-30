#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <utils/Log.h>
#include "IBasicService.h"

// class MyBasicService : public BnBasicService
// {
// public:
//     virtual ~MyBasicService() {}
//     void sayHello()
//     {
//         std::cout << "MyBasicService::sayHello" << std::endl;
//     }

//     int32_t random()
//     {
//         return rand() % 100;
//     }
// };

class MyBasicService : public BnBasicService
{
public:
   virtual ~MyBasicService(){}
   int addAccount(const String16 &name)
   {
      std::cout << "\n--->MyBasicService::addAccount()"<<std::endl;
      m_accounts.push(name);
      return 0;
   }
   Vector<String16> listAccounts()
   {
      std::cout << "\n==>MyBasicService::listAccounts()"<<std::endl;
      return m_accounts;
   }

private:
   Vector<String16> m_accounts;
};

int main()
{
   SLOGD("---AccountServer is starting---");
   sp<IServiceManager> sm = defaultServiceManager();
   sm->addService(String16("service.demo"), new MyBasicService);
   SLOGD("---Successfully register service: service.demo---");
   ProcessState::self()->startThreadPool();
   IPCThreadState::self()->joinThreadPool();
   return 0;
}

// #include <utils/Log.h>
// #include <binder/IPCThreadState.h>
// #include <binder/ProcessState.h>
// #include <binder/IServiceManager.h>

// #include "AccountService.h"

// using namespace android;

// int main()
// {
//     SLOGD("---AccountServer is starting---");

//     sp<ProcessState> proc(ProcessState::self());
//     ProcessState::self()->startThreadPool();

//     sp<IServiceManager> sm = defaultServiceManager();
//     sm->addService(String16("service.demo"), new AccountService());

//     SLOGD("---Successfully register service: service.demo---");
//     SLOGD("---Ready to joinThreadPool---");

//     IPCThreadState::self()->joinThreadPool();

//     return 0;
// }