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

	//App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	//App->camera->LookAt(vec3(0, 0, 0));

	
	//------Map-----
	//Surface
	Cube PlainGame;
	PhysBody3D*PlainGame_Body;
	PlainGame.size.x = 500;
	PlainGame.size.z = 500;
	MyCubeMap.PushBack(PlainGame);
	PlainGame_Body = App->physics->AddBody(PlainGame, 0);
	PlainGame_Body->SetPos(102.5, -0.5, -30);
	MyPhysbodyCubeMap.PushBack(PlainGame_Body);



	Cube roadboarder1L;
	PhysBody3D*bodcub1;
	roadboarder1L.size.x = 0.5;
	roadboarder1L.size.z = 200;
	roadboarder1L.size.y = 2;
	roadboarder1L.color = Blue;
	MyCubeMap.PushBack(roadboarder1L);
	bodcub1 = App->physics->AddBody(roadboarder1L, 0);
	bodcub1->SetPos(95.5, 0.5, -122);
	MyPhysbodyCubeMap.PushBack(bodcub1);

	Cube roadboarder1R;
	PhysBody3D*bodcub2;
	roadboarder1R.size.x = 0.5;
	roadboarder1R.size.z = 200;
	roadboarder1R.size.y = 2;
	roadboarder1R.color = Blue;
	MyCubeMap.PushBack(roadboarder1R);
	bodcub2 = App->physics->AddBody(roadboarder1R, 0);
	bodcub2->SetPos(83, 0.5, -122);
	MyPhysbodyCubeMap.PushBack(bodcub2);
	

	Cube roadcurve1R;
	PhysBody3D*bodcub3;
	roadcurve1R.size.x = 0.5;
	roadcurve1R.size.z = 20;
	roadcurve1R.size.y = 2;
	roadcurve1R.color = Blue;
	roadcurve1R.SetRotation(-30, vec3(0, 1, 0));
	MyCubeMap.PushBack(roadcurve1R);
	bodcub3 = App->physics->AddBody(roadcurve1R, 0);
	bodcub3->SetPos(78, 0.5, -13.5);
	MyPhysbodyCubeMap.PushBack(bodcub3);
	

	Cube roadcurve1L;
	roadcurve1L.size.x = 0.5;
	roadcurve1L.size.z = 20;
	roadcurve1L.size.y = 2;
	roadcurve1L.color = Blue;
	roadcurve1L.SetRotation(-30, vec3(0, 1, 0));
	MyCubeMap.PushBack(roadcurve1L);
	bodcub3 = App->physics->AddBody(roadcurve1L, 0);
	bodcub3->SetPos(90.5, 0.5, -13.5);
	MyPhysbodyCubeMap.PushBack(bodcub3);

	Cube roadcurve2L;
	roadcurve2L.size.x = 0.5;
	roadcurve2L.size.z = 40;
	roadcurve2L.size.y = 2;
	roadcurve2L.color = Blue;
	roadcurve2L.SetRotation(30, vec3(0, 1, 0));
	MyCubeMap.PushBack(roadcurve2L);
	bodcub3 = App->physics->AddBody(roadcurve2L, 0);
	bodcub3->SetPos(95.5, 0.5, 12.25);
	MyPhysbodyCubeMap.PushBack(bodcub3);

	Cube roadcurve2R;
	roadcurve2R.size.x = 0.5;
	roadcurve2R.size.z = 40;
	roadcurve2R.size.y = 2;
	roadcurve2R.color = Blue;
	roadcurve2R.SetRotation(30, vec3(0, 1, 0));
	MyCubeMap.PushBack(roadcurve2R);
	bodcub3 = App->physics->AddBody(roadcurve2R, 0);
	bodcub3->SetPos(83, 0.5, 12.25);
	MyPhysbodyCubeMap.PushBack(bodcub3);
	

	


	//-----Objects-----

	Sphere ballkicker;
	ballkicker.SetPos(1, 1, 1);
	ballkicker.radius = 1;
	MySphereObj.PushBack(ballkicker);
	

	ballkickerObject = App->physics->AddBody(ballkicker, 1);
	MyPhysbodySphereobj.PushBack(ballkickerObject);
	ballkickerObject->collision_listeners.add(this);

	Cube rect;
	rect.size.y = 3;
	MyCubeObj.PushBack(rect);

	PhysBody3D* RectObject;
	RectObject = App->physics->AddBody(rect, 0);
	MyPhysbodyCubeobj.PushBack(RectObject);

	//P2P Constraint to make ball kicker with rect 
	App->physics->Add_P2P_Constraint(*ballkickerObject->GetRigidBody(), *RectObject->GetRigidBody(), btVector3(0, 1, 0), btVector3(0, 1, 0), true);
	timer.Start();
	



	//-----Targets-----

	Cube cub6;
	PhysBody3D*bodcub6;
	cub6.size.x = 4;
	cub6.size.z = 0.5;
	cub6.size.y = 1;
	cub6.color = Black;
	MyCubeMap.PushBack(cub6);
	bodcub6 = App->physics->AddBody(cub6, 0);
	bodcub6->SetPos(90.5, 0.1, -200);
	MyPhysbodyCubeMap.PushBack(bodcub6);

	Cube cub7;
	PhysBody3D*bodcub7;
	cub7.size.x = 4;
	cub7.size.z = 0.5;
	cub7.size.y = 5;
	cub7.color = Red;
	MyCubeMap.PushBack(cub7);
	bodcub7 = App->physics->AddBody(cub7, 1);
	bodcub7->SetPos(90.5, 5, -200);
	MyPhysbodyCubeMap.PushBack(bodcub7);

	Cube cub_7_6_Sensor;
	PhysBody3D*bodcub_7_6_Sensor;
	cub6.size.x = 12;
	cub6.size.z = 2;
	cub6.size.y = 5;
	//SENSOR
/*	cub6.color = Black;
	MyCubeMap.PushBack(cub6);
	bodcub6 = App->physics->AddBody(cub6, 0);
	bodcub6->SetPos(90.5, 0.1, -200);
	MyPhysbodyCubeMap.PushBack(bodcub6);*/

	btVector3 anchor_bodcub6(0,0,0);
	btVector3 anchor_bodcub7(0, -cub7.size.y/2, 0.5);
	btVector3 axis_bod_6_7(1, 0, 0);
	btHingeConstraint *enemyhinge;
	enemyhinge = App->physics->Add_Hinge_Constraint(*bodcub6->GetRigidBody(), *bodcub7->GetRigidBody(), anchor_bodcub6, anchor_bodcub7, axis_bod_6_7, axis_bod_6_7, true);
	return ret;
}



// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}


update_status ModuleSceneIntro::PreUpdate(float dt)
{

	for (int i = 0; i < App->player->CanonBallsBody.Count(); i++) 
	{
		if (App->player->CanonBallsBody[i]->tokill == true)
		{

			App->physics->DestroyBody(*App->player->CanonBallsBody[i]);
			
			
		}
	}

	return UPDATE_CONTINUE;
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
	int timepassed;
	for (int i = 0; i < App->player->CanonBallsBody.Count(); i++) {
		timepassed = timer.ReadMs();
		if ((ballkickerObject == body1 ) && ( App->player->CanonBallsBody[i] == body2) && (timepassed>=1000)) {
			App->player->puntuation += 10;
			LOG("Puntuation: %i", App->player->puntuation);
			body2->tokill = true;
			timer.Start();
		}
	}
}

