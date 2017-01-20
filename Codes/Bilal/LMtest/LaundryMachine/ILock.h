#ifndef ILOCK_H
#define ILOCK_H

class ILock
{
  public:
    virtual boolean GetLockStatus() = 0;
    virtual void SetLockStatus(boolean lock) = 0;

};

#endif


