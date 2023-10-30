#include <string>
#include<iostream>
#include "IBasicService.h"

// enum
// {
//    HELLO = IBinder::FIRST_CALL_TRANSACTION,
//    RANDOM = IBinder::FIRST_CALL_TRANSACTION + 1,
// };

// class BpBasicService : public BpInterface<IBasicService>
// {
// public:
//    BpBasicService(const sp<IBinder> &impl) : BpInterface<IBasicService>(impl) {}
//    void sayHello()
//    {
//       printf("BpBasicService::sayHello\n");
//       Parcel data, reply;
//       data.writeInterfaceToken(IBasicService::getInterfaceDescriptor());
//       remote()->transact(HELLO, data, &reply);
//       printf("BpBasicService::sayHello: got response from BnBasicService\n");
//    }

//    int32_t random()
//    {
//       printf("BpBasicService::random\n");
//       Parcel data, reply;
//       data.writeInterfaceToken(IBasicService::getInterfaceDescriptor());
//       remote()->transact(RANDOM, data, &reply);
//       int32_t value = reply.readInt32();
//       printf("BpBasicService::random: got random number from BnBasicService: %d\n", value);
//       return value;
//    }
// };

// IMPLEMENT_META_INTERFACE(BasicService, "me.basicservice");

// status_t BnBasicService::onTransact(uint32_t code, const Parcel &data, Parcel *reply, uint32_t flags)
// {
//    switch (code)
//    {
//    case HELLO:
//    {
//       printf("BnBasicService:: got the client hello\n");
//       CHECK_INTERFACE(IBasicService, data, reply);
//       sayHello();
//       break;
//    }
//    case RANDOM:
//    {
//       printf("BnBasicService:: got the client random\n");
//       CHECK_INTERFACE(IBasicService, data, reply);
//       int32_t value = random();
//       reply->writeInt32(value);
//       break;
//    }
//    default:
//       break;
//    }

//    return NO_ERROR;
// }

/********************************************/
class BpBasicService : public BpInterface<IBasicService>
{
public:
   BpBasicService(const sp<IBinder> &impl)
       : BpInterface<IBasicService>(impl) {}

   int addAccount(const String16 &name)
   {
      printf("=> BpAccountService::addAccount");
      Parcel data, reply;
      data.writeInterfaceToken(IBasicService::getInterfaceDescriptor());
      data.writeString16(name);
      remote()->transact(BnBasicService::ADD_ACC_TRANSACTION, data, &reply);
      return reply.readInt32();
   }

   Vector<String16> listAccounts()
   {
      Parcel data, reply;
      printf("=> BpAccountService::listAccount\n");
      u_int32_t number;
      Vector<String16> accounts;
      data.writeInterfaceToken(IBasicService::getInterfaceDescriptor());
      remote()->transact(BnBasicService::LIST_ACC_TRANSACTION, data, &reply);
      number = reply.readInt32();

      while (number--)
      {
         accounts.push_back(reply.readString16());
      }

      return accounts;
   }
};

IMPLEMENT_META_INTERFACE(BasicService, "me.basicservice");

status_t BnBasicService::onTransact(uint32_t code, const Parcel &data, Parcel *reply, u_int32_t flag)
{
   switch (code)
   {
   case ADD_ACC_TRANSACTION:
   {
      printf("~~BnAccountService::ADD_ACC_TRANSACTION");
      CHECK_INTERFACE(IBasicService, data, reply);
      String16 name = data.readString16();
      int number = addAccount(name);
      std::cout << number << std::endl;
      reply->writeInt32(number);
   }

   break;

   case LIST_ACC_TRANSACTION:
   {
      printf("~~BnAccountService::LIST_ACC_TRANSACTION");
      CHECK_INTERFACE(IBasicService, data, reply);
      Vector<String16> accounts = listAccounts();
      reply->writeInt32(accounts.size());
      for (int i = 0; i < accounts.size(); i++)
      {
         reply->writeString16(accounts.itemAt(i));
      }
   }

   break;

   default:
      return BBinder::onTransact(code, data, reply, flag);
   }

   return NO_ERROR;
}