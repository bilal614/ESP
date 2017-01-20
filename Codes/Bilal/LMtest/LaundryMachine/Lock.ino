
Lock::Lock()
{ 
}

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

boolean Lock::lockMachine()
{
    if(Lock::checkLock())
    {
      lock = locked;
      return true;
      //Serial.print("lock switch is: ");Serial.println(lock);
    }
    else
    {
      lock = unlocked;
      return false;
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

