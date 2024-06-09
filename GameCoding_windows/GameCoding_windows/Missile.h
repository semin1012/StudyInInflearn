#pragma once
#include "Object.h"

class Missile : public Object
{
public:
	Missile();
	virtual ~Missile() override;


	virtual void	Init() override;
	virtual void	Update() override;
	virtual void	Render(HDC hdc) override;

public:

protected:
	//Object* _target;	// 이거는 _target이 사라지는 순간 크래쉬가 날 수 있다
	//shared_ptr<Object> _target; 고민해야 된다 
};

