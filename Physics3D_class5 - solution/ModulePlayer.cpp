#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "Primitive.h"
#include "PhysVehicle3D.h"
#include "PhysBody3D.h"

#define PI 3.14159265

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled), vehicle(NULL)
{
	turn = acceleration = brake = 0.0f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	VehicleInfo car;

	// Car properties ----------------------------------------
	car.chassis_size.Set(2, 2, 4);
	car.chassis_offset.Set(0, 1.5, 0);
	car.mass = 500.0f;
	car.suspensionStiffness = 15.88f;
	car.suspensionCompression = 0.83f;
	car.suspensionDamping = 0.88f;
	car.maxSuspensionTravelCm = 1000.0f;
	car.frictionSlip = 50.5;
	car.maxSuspensionForce = 6000.0f;

	// Wheel properties ---------------------------------------
	float connection_height = 1.2f;
	float wheel_radius = 0.6f;
	float wheel_width = 0.5f;
	float suspensionRestLength = 1.2f;

	// Don't change anything below this line ------------------

	float half_width = car.chassis_size.x*0.5f;
	float half_length = car.chassis_size.z*0.5f;
	
	vec3 direction(0,-1,0);
	vec3 axis(-1,0,0);
	
	car.num_wheels = 4;
	car.wheels = new Wheel[4];

	// FRONT-LEFT ------------------------
	car.wheels[0].connection.Set(half_width - 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[0].direction = direction;
	car.wheels[0].axis = axis;
	car.wheels[0].suspensionRestLength = suspensionRestLength;
	car.wheels[0].radius = wheel_radius;
	car.wheels[0].width = wheel_width;
	car.wheels[0].front = true;
	car.wheels[0].drive = true;
	car.wheels[0].brake = false;
	car.wheels[0].steering = true;

	// FRONT-RIGHT ------------------------
	car.wheels[1].connection.Set(-half_width + 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[1].direction = direction;
	car.wheels[1].axis = axis;
	car.wheels[1].suspensionRestLength = suspensionRestLength;
	car.wheels[1].radius = wheel_radius;
	car.wheels[1].width = wheel_width;
	car.wheels[1].front = true;
	car.wheels[1].drive = true;
	car.wheels[1].brake = false;
	car.wheels[1].steering = true;

	// REAR-LEFT ------------------------
	car.wheels[2].connection.Set(half_width - 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[2].direction = direction;
	car.wheels[2].axis = axis;
	car.wheels[2].suspensionRestLength = suspensionRestLength;
	car.wheels[2].radius = wheel_radius;
	car.wheels[2].width = wheel_width;
	car.wheels[2].front = false;
	car.wheels[2].drive = false;
	car.wheels[2].brake = true;
	car.wheels[2].steering = false;

	// REAR-RIGHT ------------------------
	car.wheels[3].connection.Set(-half_width + 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[3].direction = direction;
	car.wheels[3].axis = axis;
	car.wheels[3].suspensionRestLength = suspensionRestLength;
	car.wheels[3].radius = wheel_radius;
	car.wheels[3].width = wheel_width;
	car.wheels[3].front = false;
	car.wheels[3].drive = false;
	car.wheels[3].brake = true;
	car.wheels[3].steering = false;

	

	vehicle = App->physics->AddVehicle(car);
	vehicle->SetPos(0, 0, 10);


	turret = App->physics->AddBody(n, 1);
//	turret->body->forceActivationState(DISABLE_SIMULATION);



	btVector3 sphereanchor(0,-n.size.y, 0);
	btVector3 vehicleanchor(0, 2, 0);
	btVector3 axisns(0,1, 0);
	turret_carconst = App->physics->Add_Hinge_Constraint(*vehicle->GetRigidBody(), *turret->GetRigidBody(), vehicleanchor, sphereanchor, axisns, axisns, true);
	turret_carconst->setLimit(0, 3.14);
	turret_carconst->enableMotor(true);
	turret_carconst->setMaxMotorImpulse(10.0f);

	btVector3 cannonanchor(-canon.height, 0, 0);
	btVector3 turretanchor(0, n.size.y/6, 0);
	btVector3 axisnturretcanon(0, 0, 1);
	canon.height = 2.5;
	canon.radius = 0.5;
	canonbody = App->physics->AddBody(canon, 1);
//	canonbody->body->forceActivationState(DISABLE_SIMULATION);

	

	canon_turretconst = App->physics->Add_Hinge_Constraint(*turret->GetRigidBody(), *canonbody->GetRigidBody(), turretanchor, cannonanchor, axisnturretcanon, axisnturretcanon, true);
	canon_turretconst->setLimit(-1.08, 0);
	canon_turretconst->enableMotor(true);
	canon_turretconst->setMaxMotorImpulse(10.0f);


	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	return true;
}

// Update: draw background
update_status ModulePlayer::Update(float dt)
{
	turn = acceleration = brake = 0.0f;

	if(App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
	{
		acceleration = MAX_ACCELERATION;
	}
	
	if(App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
	{
		if(turn < TURN_DEGREES)
			turn +=  TURN_DEGREES;
	}

	if(App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
	{
		if(turn > -TURN_DEGREES)
			turn -= TURN_DEGREES;
	}

	if(App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
	{
		acceleration = -MAX_ACCELERATION;
	}
	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_REPEAT)
	{
		brake = BRAKE_POWER;
	}


	if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN)
	{
		Sphere s(1);
		float *mat = new float[16];
		App->player->canonbody->GetTransform(mat);
		s.SetPos(mat[12], mat[13], mat[14]);
		float force = 30.0f;
		PhysBody3D *sbody;
		sbody = App->physics->AddBody(s, 1);
		CanonBallsSpheres.PushBack(s);
		int xmouse = App->input->GetMouseX();
		int ymouse = App->input->GetMouseY();
		sbody->GetRigidBody()->setIgnoreCollisionCheck(App->player->canonbody->GetRigidBody(), true);
		sbody->GetRigidBody()->setIgnoreCollisionCheck(App->player->turret->GetRigidBody(), true);

		//Testing the shoting stuff
		float Zx, Zy, Zz;
		mat4x4 Aa;
		App->player->canonbody->body->getWorldTransform().getOpenGLMatrix(Aa.M);
		Zx = Aa[0];
		Zy = Aa[1];
		Zz = Aa[2];
		sbody->Push(Zx*force, Zy*force, Zz*force);
		CanonBallsBody.PushBack(sbody);

	}

	for (int i = 0; i < CanonBallsBody.Count(); i++) {
		CanonBallsSpheres[i].Render();
		CanonBallsBody[i]->GetTransform(&CanonBallsSpheres[i].transform);
	}


	if (App->input->GetKey(SDL_SCANCODE_W) != KEY_IDLE || App->input->GetKey(SDL_SCANCODE_S) != KEY_IDLE)
	{

		if (App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
		{
			canon_turretconst->setMotorTargetVelocity(-2);
		}

		if (App->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT)
		{
			canon_turretconst->setMotorTargetVelocity(2);
		}
	}
	else
	{
		//Must be toched to match the gravity force
		canon_turretconst->setMotorTargetVelocity(-0.07);
	}


	if (App->input->GetKey(SDL_SCANCODE_D) != KEY_IDLE || App->input->GetKey(SDL_SCANCODE_A) != KEY_IDLE)
	{

		if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
		{
			turret_carconst->setMotorTargetVelocity(-2);
		}

		if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
		{
			turret_carconst->setMotorTargetVelocity(2);
		}
	}
	else 
	{
		turret_carconst->setMotorTargetVelocity(0);
	}

	vehicle->ApplyEngineForce(acceleration);
	vehicle->Turn(turn);
	vehicle->Brake(brake);
	
	vehicle->Render();
	turret->GetTransform(&n.transform);

	n.Render();
	canonbody->GetTransform(&canon.transform);
	
	canon.Render();

	char title[80];
	sprintf_s(title, "%.1f Km/h", vehicle->GetKmh());
	App->window->SetTitle(title);

	return UPDATE_CONTINUE;
}



