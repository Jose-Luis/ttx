#include <TTX/prototypes/BasicShip.hpp>

BasicShip::BasicShip():
    GQE::Prototype("pBasicShip"),
    B2Proto("pBasicShip"),
    RenderProto("pBasicShip"),
    HealthProto("pBasicShip")
{

    mBodyDef.type = b2_dynamicBody;
    mBodyDef.linearDamping =8.0f;
    mBodyDef.angularDamping = 32.0f;

    b2FixtureDef anFixture1;
    b2Vec2 vertices[3];
    vertices[0].Set(0.0f,-1.0f);
    vertices[1].Set(1.0f,1.0f);
    vertices[2].Set(-1.0f,1.0f);
    int32 count=3;
    mShape1.Set(vertices,count);
    anFixture1.shape = &mShape1;
    anFixture1.density = 10.0f;
    anFixture1.friction = 0.5;
    anFixture1.restitution = 0;
    anFixture1.filter.categoryBits = ObjectCategories::FRIENDLY_SHIP;
    anFixture1.filter.maskBits = ObjectCategories::SCENE | ObjectCategories::ENEMY_SHIP;

    b2FixtureDef anFixture2;
    mShape2.SetAsBox(0.125,0.25, b2Vec2(0.75,0),0);
    anFixture2.shape = &mShape2;
    anFixture2.filter.maskBits = ObjectCategories::SCENE;

    b2FixtureDef anFixture3;
    mShape3.SetAsBox(0.125,0.25, b2Vec2(-0.75,0),0);
    anFixture3.shape = &mShape3;
    anFixture3.filter.maskBits = ObjectCategories::SCENE;

    Propeller anPropeller;
    anPropeller.setEmitterID("ShipPropeller");
    anPropeller.setLinearPower(8192);
    anPropeller.setTurnPower(16384);

    Weapon anWeapon;
    anWeapon.setPosition(Position2D(-0.75,0,-HALF_PI));

    mProperties.add<Propeller>("pPropeller",anPropeller);
    mProperties.add<Weapon>("wWeapon",anWeapon);
    mProperties.set("rTexRect",sf::Rect<int>(0,96,32,32));

    mProperties.set("Resistance",100.f);
    mProperties.set("Health",100.f);
    mProperties.set("IDead",static_cast<IDead*>(&mDead);

    mFixturesDef.push_back(anFixture1);
    mFixturesDef.push_back(anFixture2);
    mFixturesDef.push_back(anFixture3);
    mSystemIDs.push_back("PropellerSystem");
}

void BasicShip::ShipDead::execute(Position2D thePosition,IActionState& theActionState)
{
   theActionState.addParticleFocus(thePosition,"ShipDead");
}



