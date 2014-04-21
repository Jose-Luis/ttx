#include <TTX/prototypes/Box.hpp>

Box::Box():
    GQE::Prototype("pBox"),
    B2Proto("pBox"),
    RenderProto("pBox"),
    HealthProto("pBox")
{
    b2FixtureDef anFixture1;
    mShape1.SetAsBox(1,1);
    anFixture1.shape = &mShape1;
    anFixture1.density = 1;
    anFixture1.friction = 0.5;
    anFixture1.restitution = 0;
    anFixture1.filter.categoryBits = ObjectCategories::ENEMY_SHIP;
    anFixture1.filter.maskBits = ObjectCategories::SCENE | ObjectCategories::FRIENDLY_BULLET | ObjectCategories::FRIENDLY_SHIP;

    mBodyDef.type = b2_dynamicBody;
    mProperties.set("rTexRect",sf::IntRect(96,0,32,32));
    mFixturesDef.push_back(anFixture1);
    mAnimation1.push_back(sf::IntRect(96,0,32,32));
    mAnimation1.push_back(sf::IntRect(128,0,32,32));
    mAnimation1.push_back(sf::IntRect(160,0,32,32));
    mAnimation1.push_back(sf::IntRect(192,0,32,32));
    Animation anAnimation(&mAnimation1);
    anAnimation.mLoop = true;
    anAnimation.mFPS = 2;
    mProperties.add<Animation>("rAnimation", anAnimation);
    mSystemIDs.push_back("AnimationSystem");
    mProperties.set("Resistance", 5.f);
    mProperties.set("Health", 150.f);
}

