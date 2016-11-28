#ifndef ILOCK_H
#define ILOCK_H

class ILock
{
public:
  // Inputs

  virtual boolean GetLockStatus() = 0; 
  // Outputs
  virtual boolean LockDoor(boolean &lockStatus)= 0;//we can change lockStatus which is an argument passed by reference to the function
  virtual boolean UnlockDoor(boolean &lockStatus) = 0;//we can change lockStatus which is an argument passed by reference to the function
};

#endif


