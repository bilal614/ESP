#ifndef LOCK_H
#define LOCK_H

#include "ILock.h"

const boolean lock = 1;
const boolean unlocked = 0;

class Lock
{
  private:
    ILock* iLock;
    boolean locked;
    
  public:
    Lock(ILock *);
    void lockMachine();//is the polling function to check what the lock switch status is and will turn on/off the locked
  
};

#endif


