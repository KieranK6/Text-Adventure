#include "InteractableList.h"

InteractableList::InteractableList()
{
	std::list<Interactable> iList(0);
	setList(iList);
}

InteractableList::InteractableList(std::list<Interactable> iList) : interactableList(iList)
{
}

InteractableList::~InteractableList()
{
}

void InteractableList::printItems() const
{
	for (Interactable i : interactableList) {
		i.print();
	}
}

bool InteractableList::addItem(const Interactable &item)
{
	std::list<Interactable>::size_type sizeBefore = interactableList.size();
	interactableList.push_back(item);
	std::list<Interactable>::size_type sizeAfter = interactableList.size();
	return(sizeAfter == (sizeBefore + 1));
}

bool InteractableList::removeItem(const Interactable &item)
{
	std::list<Interactable>::size_type sizeBefore = interactableList.size();
	interactableList.remove(item);
	std::list<Interactable>::size_type sizeAfter = interactableList.size();
	return(sizeAfter == (sizeBefore - 1));
}

bool InteractableList::contains(Interactable &item)
{
	for (Interactable i : interactableList) {
		if (item == i) {
			return true;
		}
	}
	return false;
}

