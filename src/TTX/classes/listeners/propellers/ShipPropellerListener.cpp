#include <TTX/classes/listeners/propellers/ShipPropellerListener.hpp>

void ShipPropellerListener::update(Input::Data theInputData)
{
   b2Vec2 anDirection(theInputData.move.x, theInputData.move.y);
   float anPower = anDirection.LengthSquared();

   if(anPower)
   {
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
      b2Vec2 anPosition = body->GetWorldCenter();
      mFocus->setPosition(mpe::Vec2(anPosition.x, anPosition.y));
      float  anAngle = body->GetAngle() * TODEG;
      mFocus->setAngle(anAngle);
   }
   mFocus->setPPS(anPower * 32);


}

ShipPropellerListener* ShipPropellerListener::clone()
{
   return new ShipPropellerListener();
}

ShipPropellerListener::~ShipPropellerListener()
{
   mFocus->kill();
}

void ShipPropellerListener::init()
{
   Particles& particles = mState->getParticles();
   mFocus = particles.createFocus("ShipPropeller");
   particles.addFocus(mFocus);
}


