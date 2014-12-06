#pragma once

//���̃N���X

#include "Observable.h"
#include "Component.h"

#define PI 3.14159

namespace GaL{

	//!�ėp�I�u�W�F�N�g(��)
	class Mover : public Component, public Observer<Mover>{
	private:
		double X,Y;
		double Speed;
		double Yaw, VYaw;	//��]�p���x,�����x
		double Angle;

		int Width,Height;

		int HitRange;	//�����蔻��(���a)
	
	public:
		Mover(double _x,double _y);
		virtual ~Mover();

		//!�����蔻��(�~)
		virtual bool IsHit(Mover* _mover);


		//--------------------------------------
		double GetX();
		double GetY();
		void SetX(const double _x);
		void SetY(const double _y);

		double GetSpeed();
		void SetSpeed(const double _speed);

		double GetAngle();
		void SetAngle(const double _angle);

		double GetYaw();
		void SetYaw(const double _yaw);
		double GetVYaw();
		void SetVYaw(const double _vyaw);

		int GetWidth();
		void SetWidth(const int _width);
		int GetHeight();
		void SetHeight(const int _height);

	};

}