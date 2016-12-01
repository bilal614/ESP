#ifndef ILOCK_H
#define ILOCK_H

class ILock
{
public:
  // Inputs
  virtual boolean GetLockStatus() = 0;
  // Outputs
  virtual boolean LockDoor(boolean &lockStatus) = 0;
  virtual boolean UnlockDoor(boolean &lockStatus) = 0;
};

#endif


