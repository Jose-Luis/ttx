// =====================================================================================
// 
//       Filename:  FocusProto.cpp
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  02/21/2013 12:59:15 AM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Jose Luis Lavado (), joseluislavado@gmail.com
//        Company:  
// 
// =====================================================================================

#include <TTX/prototypes/components/FocusProto.hpp>

FocusProto::FocusProto(GQE::typePrototypeID theID,mpe::EmitterID theEmitter):
   GQE::Prototype(theID),
   mEmitter(theEmitter)
{
   mProperties.add<mpe::EmitterID&>("sEmitterID",mEmitter);
}
