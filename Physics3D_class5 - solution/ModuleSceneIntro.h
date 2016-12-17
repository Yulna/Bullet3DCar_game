#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"
#include"j1PerfTimer.h"

#define MAX_SNAKE 2
#define MAX_CUBE 50
struct PhysBody3D;
struct PhysMotor3D;
struct btHingeConstraint;
class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);

public:
	/*
	PhysBody3D* pb_snake[MAX_SNAKE];
	Sphere s_snake[MAX_SNAKE];

	PhysBody3D* pb_snake2[MAX_SNAKE];
	Sphere s_snake2[MAX_SNAKE];
	*/

	PhysBody3D* pb_chassis;
	Cube p_chassis;

	PhysBody3D* pb_wheel;
	Cylinder p_wheel;

	PhysBody3D* pb_wheel2;
	Cylinder p_wheel2;

	PhysMotor3D* left_wheel;
	PhysMotor3D* right_wheel;

	PhysBody3D*ballkickerObject;
	Sphere n;
	PhysBody3D* turret;
	p2DynArray<Cube> MyCubeMap;
	p2DynArray<PhysBody3D*> MyPhysbodyCubeMap;
	
	p2DynArray<Sphere> MySphereObj;
	p2DynArray<PhysBody3D*> MyPhysbodySphereobj;

	p2DynArray<Cube> MyCubeObj;
	p2DynArray<PhysBody3D*> MyPhysbodyCubeobj;

	p2DynArray<Cube> MySensorCube;
	p2DynArray<PhysBody3D*> MySensorCubeBody;
	j1PerfTimer timer;
	btHingeConstraint *enemyhinge;
	PhysBody3D* bodcub7;
	
};
