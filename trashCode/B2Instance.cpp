
#include <TTX/prototypes/B2Instance.hpp>

void B2Instance::destroy(void)
{
   b2Body* anBody = mProperties.get<b2Body*>("b2Body");
   b2World* anWorld = anBody->GetWorld();
   anWorld->DestroyBody(anBody);
   GQE::Instance::destroy();
}
