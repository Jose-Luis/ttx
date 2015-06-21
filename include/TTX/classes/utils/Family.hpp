#ifndef FAMILY_INC
#define FAMILY_INC

#include <forward_list>

template<class TYPE>
class Family
{
   public:

      Family(TYPE* theMe):
         mRoot(nullptr),
         mFather(nullptr),
         mMe(theMe)
      {}

      TYPE* getFather()
         {return mFather;}

      TYPE* getRoot()
         {return mRoot;}

      TYPE* getMe()
         {return mMe;}

      bool isRoot()
         {return mFather == nullptr;}

      void addChild(TYPE* theChild)
         {mChildren.push_front(theChild);}

      void dropChild(TYPE* theChild)
         {mChildren.remove(theChild);}

   private:

      void setRoot(TYPE* theRoot)
      { mRoot = theRoot;}
      TYPE* mRoot;
      TYPE* mFather;
      TYPE* mMe;
      std::forward_list<TYPE*> mChildren;
};

#endif
