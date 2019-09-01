#ifndef __CATPOO_LIFECYCLE_H__
#define __CATPOO_LIFECYCLE_H__

class LifeCycle
{
protected:

  /**
   * Call this function once per main loop to update the
   * internal state.
   */
  virtual void update();
};


#endif
