#ifndef BASIC_SERVICE
#define BASIC_SERVICE
#include <stdio.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IBinder.h>
#include <binder/Binder.h>
#include <binder/ProcessState.h>
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>

using namespace android;

// class IBasicService : public IInterface
// {
// public:
//    DECLARE_META_INTERFACE(BasicService);
//    virtual void sayHello() = 0;
//    virtual int32_t random() = 0;
// };

// class BnBasicService : public BnInterface<IBasicService>
// {
// public:
//    virtual status_t onTransact(uint32_t code, const Parcel &data, Parcel *reply, uint32_t flags = 0);
// };

/*******************************************/
class IBasicService : public IInterface
{
public:
   DECLARE_META_INTERFACE(BasicService);
   virtual int addAccount(const String16 &name) = 0;
   virtual Vector<String16> listAccounts() = 0;
};

class BnBasicService : public BnInterface<IBasicService>
{
public:
   enum
   {
      ADD_ACC_TRANSACTION = IBinder::FIRST_CALL_TRANSACTION,
      LIST_ACC_TRANSACTION,
   };

   virtual status_t onTransact(uint32_t code, const Parcel &data, Parcel *reply, uint32_t flag = 0);
};

#endif
