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
enum guy {
	bad_guy,
	good_guy,
	unknown
};
class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status PreUpdate(float dt);
	update_status Update(float dt);
	bool CleanUp();
	void Create_Guy(PhysBody3D **body, btHingeConstraint **hinge, vec3 position, guy guy_type, float angle);
	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);
	void Stage_Activation(int stage);

public:


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

	PhysBody3D* house_top_body;

	p2DynArray<PhysBody3D*> Stage1_guys_bodys;
	p2DynArray<btHingeConstraint*> Stage1_guys_hinges;
	p2DynArray<PhysBody3D*> Stage2_guys_bodys;
	p2DynArray<btHingeConstraint*> Stage2_guys_hinges;
	p2DynArray<PhysBody3D*> Stage3_guys_bodys;
	p2DynArray<btHingeConstraint*> Stage3_guys_hinges;
	p2DynArray<PhysBody3D*> Stage4_guys_bodys;
	p2DynArray<btHingeConstraint*> Stage4_guys_hinges;	
	PhysBody3D*PlainGame_Body;
	
	
};
