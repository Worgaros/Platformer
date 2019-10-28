#include "platform.h"
#include "globals.h"

Platform::Platform(sf::Vector2f position, sf::Vector2f size) : position_(position), size_(size)
{
	gameObjectType_ = GameObjectType::PLATFORM;
}
void Platform::Init(b2World& world)
{
	rectShape_.setPosition(position_);
	rectShape_.setSize(size_);
	rectShape_.setOrigin(size_ / 2.0f);
	rectShape_.setFillColor(sf::Color::Blue);

	b2BodyDef bodyDef;
	bodyDef.position = pixel2meter(position_);
	platformBody_ = world.CreateBody(&bodyDef);
	b2PolygonShape shape;
	shape.SetAsBox(pixel2meter(size_.x / 2.0f), pixel2meter(size_.y / 2.0f));

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.userData = this;
	fixtureDef.friction = 0.0f;
	platformBody_->CreateFixture(&fixtureDef);
}
void Platform::Draw(sf::RenderWindow& window)
{
	window.draw(rectShape_);
}