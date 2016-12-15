#ifndef ILOCK_H
#define ILOCK_H

class ILock
{
  public:
    virtual boolean GetLockStatus();
    virtual void SetLockStatus(boolean lock)=0;
};

#endif


