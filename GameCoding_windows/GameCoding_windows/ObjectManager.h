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
		// type trait, ���� template ������ Object���� �ƴ��� Init�� �ִ��� ������
		// ������� �ϴ� �������� �� �Ǹ� ơ ��
		// �� ���ڸ� Init()�� �־ ���� ���� ���ư��� �� ���� �ִ�. 
		static_assert(std::is_convertible_v<T*, Object*>);
		// �� �ڵ�� ������ Ÿ�ӿ� Object Ÿ������ Ȯ���� �� �� �ִ�.

		T* object = new T();
		object->Init();

		return object;
	}

private:
	vector<Object*> _objects;
};

