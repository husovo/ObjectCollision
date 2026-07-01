#include <raylib.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define NUM_OF_OBJ 10

typedef struct object{
	Vector2 Position;
	Vector2 Velocity;
	Vector2 Acceleration;
	float mass;
	Color color;
	float radius;
}obj;

void updateObject(obj *object){
	object->Velocity.y += object->Acceleration.y;
	object->Position.y += object->Velocity.y;
	if(object->Position.y +object->radius >= HEIGHT){
		object->Position.y = HEIGHT-object->radius;
		object->Velocity.y *= -0.75f;
	}
	DrawCircleV(object->Position,object->radius,object->color);
}

int main()
{
	srand(time(NULL));
	obj objects[NUM_OF_OBJ];
	float gravity = 0.75;
	for(int i =0; i <NUM_OF_OBJ; i++){
		objects[i].Position = (Vector2){rand() % WIDTH,50};
		objects[i].Velocity = (Vector2) {0.0f,0.0f};
		objects[i].mass = 0.5+i*gravity;
		objects[i].Acceleration.y=gravity/objects[i].mass;
		objects[i].radius =(float) GetRandomValue(20,40);
		objects[i].color = (Color){
			rand() % 256,
			rand() % 256,
			rand() % 256,
			255	
		};
	}

	InitWindow(WIDTH,HEIGHT,"Motion");
	SetTargetFPS(60);
	while(!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		for(int i = 0; i < NUM_OF_OBJ; i++)
		{
			updateObject(&objects[i]);
		}
		EndDrawing();
	}
	CloseWindow();
	
	return 0;
}
