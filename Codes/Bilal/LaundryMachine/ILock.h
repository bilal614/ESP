#ifndef ILOCK_H
#define ILOCK_H

class ILock
{
public:
  // Inputs
  virtual boolean GetLockStatus() = 0;
};

#endif


