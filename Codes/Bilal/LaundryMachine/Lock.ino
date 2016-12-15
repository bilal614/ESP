
Lock::Lock(ILock * l)
{
  iLock = l;  
}

Lock::~Lock()
{
  //delete iLock;  
}

boolean Lock::checkLock()
{
  boolean LockStatus = iLock->GetLockStatus();
  return LockStatus;
}

void Lock::lockMachine()
{
    if(Lock::checkLock())
    {
      lock = locked;
    }
    else
    {
      lock = unlocked;  
    }
}

void Lock::setLock(boolean l)
{
  lock = l;  
}
