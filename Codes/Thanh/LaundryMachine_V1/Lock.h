#ifndef LOCK_H
#define LOCK_H

#include "ILock.h"

const boolean locked = 1;
const boolean unlocked = 0;

class Lock
{
  private:
    ILock* iLock;
    boolean lock;
    
  public:
    Lock();
    Lock(ILock *);
    void lockMachine();//is the polling function to check what the lock switch status is and will turn on/off the locked
    boolean checkLock();
    void setLock(boolean l);
    ~Lock();
    void setInterface(ILock* lck);
};

#endif


