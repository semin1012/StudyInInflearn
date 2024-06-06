#pragma once

class Object;

class ObjectManager
{
public:
	DECLARE_SINGLE(ObjectManager);

	~ObjectManager();

	void Add(Object* object);
	void Remove(Object* object);
	void Clear();

	const vector<Object*>& GetObjects() { return _objects; }

	template<typename T>
	T* CreateObject()
	{
		// type trait, 원래 template 문법은 Object인지 아닌지 Init이 있는지 없는지
		// 상관없이 일단 돌려보고 안 되면 퉤 뱉어냄
		// 운 나쁘면 Init()이 있어서 오류 없이 돌아가게 될 수도 있다. 
		static_assert(std::is_convertible_v<T*, Object*>);
		// 이 코드로 컴파일 타임에 Object 타입인지 확인해 볼 수 있다.

		T* object = new T();
		object->Init();

		return object;
	}

private:
	vector<Object*> _objects;
};

