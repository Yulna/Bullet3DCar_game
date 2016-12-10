#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));

	
	//------Map-----

	Cube cub1;
	PhysBody3D*bodcub1;
	cub1.size.x = 8;
	cub1.size.z = 100;
	cub1.SetRotation(10, vec3(1, 0, 0));
	MyCubeMap.PushBack(cub1);
	bodcub1 = App->physics->AddBody(cub1, 0);
	bodcub1->SetPos(0.5, 8.5, 53);
	MyPhysbodyCubeMap.PushBack(bodcub1);

	Cube cub2;
	PhysBody3D*bodcub2;
	cub2.size.x = 8;
	cub2.size.z = 200;
	MyCubeMap.PushBack(cub2);
	bodcub2 = App->physics->AddBody(cub2, 0);
	bodcub2->SetPos(8, 0, 2);
	MyPhysbodyCubeMap.PushBack(bodcub2);
	
	Cube cub3;
	PhysBody3D*bodcub3;
	cub3.size.x = 110;
	cub3.size.z = 8;
	MyCubeMap.PushBack(cub3);
	bodcub3 = App->physics->AddBody(cub3, 0);
	bodcub3->SetPos(51.5, 0, 105.5);
	MyPhysbodyCubeMap.PushBack(bodcub3);

	Cube cub4;
	PhysBody3D*bodcub4;
	cub4.size.x = 110;
	cub4.size.z = 8;
	MyCubeMap.PushBack(cub4);
	bodcub4 = App->physics->AddBody(cub4, 0);
	bodcub4->SetPos(51.5, 0, 113.5);
	MyPhysbodyCubeMap.PushBack(bodcub4);

	Cube cub5;
	PhysBody3D*bodcub5;
	cub5.size.x = 8;
	cub5.size.z = 200;
	MyCubeMap.PushBack(cub5);
	bodcub5 = App->physics->AddBody(cub5, 0);
	bodcub5->SetPos(94.5, 0, 2);
	MyPhysbodyCubeMap.PushBack(bodcub5);

	Cube cub6;
	PhysBody3D*bodcub6;
	cub6.size.x = 8;
	cub6.size.z = 200;
	MyCubeMap.PushBack(cub6);
	bodcub6 = App->physics->AddBody(cub6, 0);
	bodcub6->SetPos(102.5, 0, 2);
	MyPhysbodyCubeMap.PushBack(bodcub6);

	Cube cub7;
	PhysBody3D*bodcub7;
	cub7.size.x = 110;
	cub7.size.z = 8;
	MyCubeMap.PushBack(cub7);
	bodcub7 = App->physics->AddBody(cub7, 0);
	bodcub7->SetPos(51.5, 0, -102);
	MyPhysbodyCubeMap.PushBack(bodcub7);

	Cube cub8;
	PhysBody3D*bodcub8;
	cub8.size.x = 110;
	cub8.size.z = 8;
	MyCubeMap.PushBack(cub8);
	bodcub8 = App->physics->AddBody(cub8, 0);
	bodcub8->SetPos(51.5, 0, -110);
	MyPhysbodyCubeMap.PushBack(bodcub8);


	//-----Objects-----

	Sphere ballkicker;
	ballkicker.SetPos(1, 1, 1);
	ballkicker.radius = 1;
	MySphereObj.PushBack(ballkicker);
	
	PhysBody3D*ballkickerObject;
	ballkickerObject = App->physics->AddBody(ballkicker, 1);
	MyPhysbodySphereobj.PushBack(ballkickerObject);

	Cube rect;
	rect.size.y = 3;
	MyCubeObj.PushBack(rect);

	PhysBody3D* RectObject;
	RectObject = App->physics->AddBody(rect, 0);
	MyPhysbodyCubeobj.PushBack(RectObject);

	//P2P Constraint to make ball kicker with rect 
	App->physics->Add_P2P_Constraint(*ballkickerObject->GetRigidBody(), *RectObject->GetRigidBody(), btVector3(0, 1, 0), btVector3(0, 1, 0), true);

	
	
	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();
	for (int i=0; i < MyCubeMap.Count(); i++) {
		MyCubeMap[i].Render();
		MyPhysbodyCubeMap[i]->GetTransform(&MyCubeMap[i].transform);
	}
	for (int i = 0; i < MySphereObj.Count(); i++) {
		MySphereObj[i].Render();
		MyPhysbodySphereobj[i]->GetTransform(&MySphereObj[i].transform);
	}
	for (int i = 0; i < MyCubeObj.Count(); i++) {
		MyCubeObj[i].Render();
		MyPhysbodyCubeobj[i]->GetTransform(&MyCubeObj[i].transform);
	}

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

