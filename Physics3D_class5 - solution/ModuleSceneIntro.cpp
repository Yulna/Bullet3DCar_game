#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"
#include"ModulePlayer.h"
#include"PhysVehicle3D.h"
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

	//-----enemy 1-------
	Create_Guy(&bodcub7, &enemyhinge, vec3(89, 0.1, -200), bad_guy);

	//-----enemy 2-------
	Create_Guy(&bodcub9_enemy2, &enemyhinge3, vec3(100, 0.1, -200), bad_guy);

	//-----good guy 1-----
	Create_Guy(&bodcub8_good_guy1, &enemyhinge2, vec3(75, 0.1, -180), good_guy);


	//SENSOR

	
	//SENSOR
	Cube cub_7_6_Sensor;
	PhysBody3D*bodcub_7_6_Sensor;
	cub_7_6_Sensor.size.x = 10;
	cub_7_6_Sensor.size.z = 2;
	cub_7_6_Sensor.size.y = 3;
	MySensorCube.PushBack(cub_7_6_Sensor);
	bodcub_7_6_Sensor = App->physics->AddBody(cub_7_6_Sensor, 0);
	bodcub_7_6_Sensor->SetPos(89, 2, -213);

	bodcub_7_6_Sensor->SetAsSensor(true);
	bodcub_7_6_Sensor->collision_listeners.add(this);
	MySensorCubeBody.PushBack(bodcub_7_6_Sensor);


	//----
	



	
	
	return ret;
}




// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

void ModuleSceneIntro::Create_Guy(PhysBody3D **body, btHingeConstraint **hinge, vec3 position, guy guy_type)
{
	Cube cub_base;
	PhysBody3D*bodcub_base;
	cub_base.size.x = 4;
	cub_base.size.z = 0.5;
	cub_base.size.y = 0;
	cub_base.color = Black;
	MyCubeMap.PushBack(cub_base);
	bodcub_base = App->physics->AddBody(cub_base, 0);
	bodcub_base->SetPos(position.x, position.y, position.z);
	MyPhysbodyCubeMap.PushBack(bodcub_base);


	Cube cub_enemy_good;
	cub_enemy_good.size.x = 4;
	cub_enemy_good.size.z = 0;
	cub_enemy_good.size.y = 5;
	if (guy_type == good_guy) {
		cub_enemy_good.color = Green;
	}
	else {
		cub_enemy_good.color = Red;
	}
	MyCubeMap.PushBack(cub_enemy_good);
	PhysBody3D* bodcub_enemy_good;
	bodcub_enemy_good = App->physics->AddBody(cub_enemy_good, 1);
	bodcub_enemy_good->collision_listeners.add(this);
	bodcub_enemy_good->SetPos(position.x, 5, position.z);
	MyPhysbodyCubeMap.PushBack(bodcub_enemy_good);
	btVector3 anchor_bodcub6(0, 0, 0);
	btVector3 anchor_bodcub7(0, -cub_enemy_good.size.y / 2, 0.01);
	btVector3 axis_bod_6_7(1, 0, 0);
	*body = bodcub_enemy_good;

	btHingeConstraint *guy_hinge;
	guy_hinge = App->physics->Add_Hinge_Constraint(*bodcub_base->GetRigidBody(), *bodcub_enemy_good->GetRigidBody(), anchor_bodcub6, anchor_bodcub7, axis_bod_6_7, axis_bod_6_7, true);
	guy_hinge->setLimit(-3.14 * 0.5, 0);
	*hinge = guy_hinge;
}


update_status ModuleSceneIntro::PreUpdate(float dt)
{

	for (int i = 0; i < App->player->CanonBallsBody.Count(); i++) 
	{
		if (App->player->CanonBallsBody[i]->tokill == true)
		{

			App->physics->DestroyBody(*App->player->CanonBallsBody[i]);
			App->player->CanonBallsSpheres.Remove(i);
			App->player->CanonBallsBody.Remove(i);
			
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
		MyPhysbodyCubeMap[i]->GetTransform(&MyCubeMap[i].transform);
		MyCubeMap[i].Render();
	
	}
	for (int i = 0; i < MySphereObj.Count(); i++) {
		MyPhysbodySphereobj[i]->GetTransform(&MySphereObj[i].transform);
		MySphereObj[i].Render();

	}
	for (int i = 0; i < MyCubeObj.Count(); i++) {
		MyPhysbodyCubeobj[i]->GetTransform(&MyCubeObj[i].transform);
		MyCubeObj[i].Render();
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
	
		if ((bodcub7 == body1 || bodcub7 == body2) && (App->player->CanonBallsBody[i] == body1 || App->player->CanonBallsBody[i] == body2) && bodcub7->active==true ) {
			enemyhinge->enableMotor(false);
			App->player->puntuation += 20;
			bodcub7->active = false;
		}

		if ((bodcub8_good_guy1 == body1 || bodcub8_good_guy1 == body2) && (App->player->CanonBallsBody[i] == body1 || App->player->CanonBallsBody[i] == body2) && bodcub8_good_guy1->active == true) {
			enemyhinge2->enableMotor(false);
			App->player->puntuation -= 10;
			bodcub8_good_guy1->active = false;
		}
		
		if ((bodcub9_enemy2 == body1 || bodcub9_enemy2 == body2) && (App->player->CanonBallsBody[i] == body1 || App->player->CanonBallsBody[i] == body2) && bodcub9_enemy2->active == true) {
			enemyhinge3->enableMotor(false);
			App->player->puntuation += 20;
			bodcub9_enemy2->active = false;
		}
	}

	if (MySensorCubeBody[0] == body1 && App->player->turret == body2) {
		FirstStage_Activation();
	}
}

void ModuleSceneIntro::FirstStage_Activation()
{
	//----enemy_1
	bodcub7->body->activate(true);
	enemyhinge->enableMotor(true);
	enemyhinge->setMaxMotorImpulse(10);
	enemyhinge->setMotorTargetVelocity(10);
	//----good_person_1
	bodcub8_good_guy1->body->activate(true);
	enemyhinge2->enableMotor(true);
	enemyhinge2->setMaxMotorImpulse(10);
	enemyhinge2->setMotorTargetVelocity(10);

	//--- enemy2----
	bodcub9_enemy2->body->activate(true);
	enemyhinge3->enableMotor(true);
	enemyhinge3->setMaxMotorImpulse(10);
	enemyhinge3->setMotorTargetVelocity(10);

}


