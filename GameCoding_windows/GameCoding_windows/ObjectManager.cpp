#include "pch.h"
#include "ObjectManager.h"
#include "Object.h"

ObjectManager::~ObjectManager()
{
	Clear();
}

void ObjectManager::Add(Object* object)
{
	if (object == nullptr)
		return;

	auto findIt = std::find(_objects.begin(), _objects.end(), object);
	
	// 이미 있는 거라면 return 
	if (findIt != _objects.end())
		return;

	_objects.push_back(object);
}

void ObjectManager::Remove(Object* object)
{
	if (object == nullptr)
		return;
	
	auto it = std::remove(_objects.begin(), _objects.end(), object);
	// 진짜 삭제되는 게 아니라 찌끄래기를 남김
	_objects.erase(it, _objects.end());
	// 그래서 이렇게 erase도 같이 해 줘야 한다. 

	// TODO: 괜찮은 걸까?
	delete object; 
}

void ObjectManager::Clear()
{
	std::for_each(_objects.begin(), _objects.end(), [=](Object* obj) {delete obj; });
	
	_objects.clear();
}
