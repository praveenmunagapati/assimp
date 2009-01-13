/*
---------------------------------------------------------------------------
Open Asset Import Library (ASSIMP)
---------------------------------------------------------------------------

Copyright (c) 2006-2008, ASSIMP Development Team

All rights reserved.

Redistribution and use of this software in source and binary forms, 
with or without modification, are permitted provided that the following 
conditions are met:

* Redistributions of source code must retain the above
  copyright notice, this list of conditions and the
  following disclaimer.

* Redistributions in binary form must reproduce the above
  copyright notice, this list of conditions and the
  following disclaimer in the documentation and/or other
  materials provided with the distribution.

* Neither the name of the ASSIMP team, nor the names of its
  contributors may be used to endorse or promote products
  derived from this software without specific prior
  written permission of the ASSIMP Development Team.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
---------------------------------------------------------------------------
*/
/** @file aiVector3D.h
 *  @brief 3D vector structure, including operators when compiling in C++
 */
#ifndef AI_VECTOR3D_H_INC
#define AI_VECTOR3D_H_INC

#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "./Compiler/pushpack1.h"

// ---------------------------------------------------------------------------
/** Represents a three-dimensional vector. */
struct aiVector3D
{
#ifdef __cplusplus
	aiVector3D () : x(0.0f), y(0.0f), z(0.0f) {}
	aiVector3D (float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
	aiVector3D (float _xyz) : x(_xyz), y(_xyz), z(_xyz) {}
	aiVector3D (const aiVector3D& o) : x(o.x), y(o.y), z(o.z) {}

	void Set( float pX, float pY, float pZ) { x = pX; y = pY; z = pZ; }
	float SquareLength() const { return x*x + y*y + z*z; }
	float Length() const { return sqrt( SquareLength()); }
	aiVector3D& Normalize() { *this /= Length(); return *this; }
	const aiVector3D& operator += (const aiVector3D& o) { x += o.x; y += o.y; z += o.z; return *this; }
	const aiVector3D& operator -= (const aiVector3D& o) { x -= o.x; y -= o.y; z -= o.z; return *this; }
	const aiVector3D& operator *= (float f) { x *= f; y *= f; z *= f; return *this; }
	const aiVector3D& operator /= (float f) { x /= f; y /= f; z /= f; return *this; }

	inline float operator[](unsigned int i) const {return *(&x + i);}
	inline float& operator[](unsigned int i) {return *(&x + i);}

	inline bool operator== (const aiVector3D& other) const
		{return x == other.x && y == other.y && z == other.z;}

	inline bool operator!= (const aiVector3D& other) const
		{return x != other.x || y != other.y || z != other.z;}

	inline aiVector3D& operator= (float f)
		{x = y = z = f;return *this;}

	const aiVector3D SymMul(const aiVector3D& o)
		{return aiVector3D(x*o.x,y*o.y,z*o.z);}

#endif // __cplusplus

	float x, y, z;	
} PACK_STRUCT;

#include "./Compiler/poppack1.h"

#ifdef __cplusplus
} // end extern "C"

// symmetric addition
inline aiVector3D operator + (const aiVector3D& v1, const aiVector3D& v2)
{
	return aiVector3D( v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

// symmetric subtraction
inline aiVector3D operator - (const aiVector3D& v1, const aiVector3D& v2)
{
	return aiVector3D( v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

// scalar product
inline float operator * (const aiVector3D& v1, const aiVector3D& v2)
{
	return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

// scalar multiplication
inline aiVector3D operator * ( float f, const aiVector3D& v)
{
	return aiVector3D( f*v.x, f*v.y, f*v.z);
}

// and the other way around
inline aiVector3D operator * ( const aiVector3D& v, float f)
{
	return aiVector3D( f*v.x, f*v.y, f*v.z);
}

// scalar division
inline aiVector3D operator / ( const aiVector3D& v, float f)
{
	
	return v * (1/f);
}

// vector division
inline aiVector3D operator / ( const aiVector3D& v, const aiVector3D& v2)
{
	return aiVector3D(v.x / v2.x,v.y / v2.y,v.z / v2.z);
}

// cross product
inline aiVector3D operator ^ ( const aiVector3D& v1, const aiVector3D& v2)
{
	return aiVector3D( v1.y*v2.z - v1.z*v2.y, v1.z*v2.x - v1.x*v2.z, v1.x*v2.y - v1.y*v2.x);
}

// vector inversion
inline aiVector3D operator - ( const aiVector3D& v)
{
	return aiVector3D( -v.x, -v.y, -v.z);
}

#endif // __cplusplus

#endif // AI_VECTOR3D_H_INC
