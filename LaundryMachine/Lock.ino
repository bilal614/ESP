
Lock::Lock()
{
  lock = Lock::checkLock();   
}

Lock::Lock(ILock * l)
{
  iLock = l; 
  lock = Lock::checkLock(); 
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

void Lock::setInterface(ILock* lck)
{
  iLock = lck;  
}

