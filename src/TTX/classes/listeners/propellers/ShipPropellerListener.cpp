#include <TTX/classes/listeners/propellers/ShipPropellerListener.hpp>

void ShipPropellerListener::update(Input::Data theInputData)
{
   b2Vec2 anDirection(theInputData.move.x, theInputData.move.y);
   b2Body* body = mEntity->mProperties.get<b2Body*>(BODY);

         if(!theInputData.pivot)
         {
            body->ApplyForceToCenter(16384 * anDirection);
         }

         if(theInputData.turn)
         {
            body->SetFixedRotation(false);
            body->ApplyTorque(body->GetLocalVector(anDirection).x * 32768);
         }
         else
         {
            body->SetAngularVelocity(0);
            body->SetFixedRotation(true);
         }
}

ShipPropellerListener* ShipPropellerListener::clone()
{
   return new ShipPropellerListener();
}

