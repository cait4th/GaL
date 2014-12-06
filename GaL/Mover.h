#pragma once

//物体クラス

#include "Observable.h"
#include "Component.h"

#define PI 3.14159

namespace GaL{

	//!汎用オブジェクト(可動)
	class Mover : public Component, public Observer<Mover>{
	private:
		double X,Y;
		double Speed;
		double Yaw, VYaw;	//回転角速度,加速度
		double Angle;

		int Width,Height;

		int HitRange;	//当たり判定(半径)
	
	public:
		Mover(double _x,double _y);
		virtual ~Mover();

		//!当たり判定(円)
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