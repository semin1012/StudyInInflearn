#pragma once

class Scene
{
public:
	Scene();
	virtual ~Scene();

	virtual void Init() abstract;
	// virtual void Init() = 0; 와 같은 문법이다.
	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;

protected:

};

