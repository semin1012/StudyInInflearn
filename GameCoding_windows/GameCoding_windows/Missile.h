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
	//Object* _target;	// �̰Ŵ� _target�� ������� ���� ũ������ �� �� �ִ�
	//shared_ptr<Object> _target; ����ؾ� �ȴ� 
};

