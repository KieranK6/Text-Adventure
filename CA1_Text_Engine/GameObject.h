#pragma once
#include <string>

//Purpose: Base class for all game objects
//Author: Arnas
//Version: 1.0
//Bugs: None known
//TODO: none

class GameObject{
	friend std::ostream& operator<<(std::ostream& outStream,
		GameObject& gameObject);

public:
#pragma region constructors
	GameObject();
	GameObject(std::string name, std::string description);
	~GameObject();
#pragma endregion
#pragma region setters and getters
	void setID(int id) { GameObject::id = id; }
	void setName(std::string name) { GameObject::name = name; }
	void setDescription(std::string description) { GameObject::description = description; }

	int getID() const { return id; }
	std::string getName() const { return name; }
	std::string getDescription() const { return description; }
#pragma endregion
#pragma region other
	operator std::string() const;
	std::string to_string() const;
	void print() const;
	GameObject clone(GameObject& go) const;
#pragma endregion
private:
	int id;
	std::string name, description;
protected:
	static int count;
};