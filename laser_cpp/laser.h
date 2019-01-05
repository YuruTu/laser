//laser,h


#define LASER_API __declspec(dllexport)
typedef struct StructPointerTest
{
	double arr[2500];
}StructPointerTest, *StructPointer;
extern "C" {
	LASER_API StructPointer __stdcall laser_mode(long , long );
	LASER_API void __stdcall hello();
}

