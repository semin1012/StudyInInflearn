#pragma once

class Scene
{
public:
	Scene();
	virtual ~Scene();

	virtual void Init() abstract;
	// virtual void Init() = 0; �� ���� �����̴�.
	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;

protected:

};

