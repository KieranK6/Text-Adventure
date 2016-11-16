#include "GameObject.h";
#include <iostream>;

int GameObject::count = 1;

GameObject::GameObject() : id(count), name("default_name"), description("default description")
{
	count++;
}

GameObject::GameObject(std::string name, std::string description) : id(count), name(name), description(description)
{
	count++;
}

GameObject::~GameObject()
{
	count--;
}

GameObject::operator std::string() const
{
	return std::to_string(id) + ":" + getName() + ":" + getDescription();
}

std::string GameObject::to_string() const
{
	return std::string();
}

void GameObject::print() const
{
	std::cout << GameObject::to_string();
}


std::ostream & operator<<(std::ostream& outStream, GameObject& gameObject)
{
	return outStream << gameObject.name << ":" << gameObject.description;
}
