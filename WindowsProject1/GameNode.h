#pragma once
class GameNode
{
public:
	GameNode();
	~GameNode();

	virtual void Init()				=0;	//무조건 구현하도록
	virtual void Update()			=0;
	virtual void Render()			=0;
};

