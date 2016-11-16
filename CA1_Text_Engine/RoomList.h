#pragma once
#include <list>;
#include "Room.h";
class RoomList {
public:
	RoomList();
	RoomList(std::list<Room> roomList);
	~RoomList();

	void setList(std::list<Room> roomList) { RoomList::roomList = roomList; }
	std::list<Room> getList() const { return roomList; }

	void printItems() const;

private:
	std::list<Room> roomList;
};